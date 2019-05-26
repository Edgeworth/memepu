#!/usr/bin/env python3
import argparse
import glob
import multiprocessing
import os
import subprocess
import sys
import time


class WorkerQueue:
  def __init__(self):
    self.popens = {}
    self.max_procs = multiprocessing.cpu_count()

  def run_one_process(self, command):
    print('Running command "%s".' % command)
    return subprocess.Popen(command, shell=True, stdin=subprocess.DEVNULL,
                            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

  def cleanup(self):
    for command, popen in self.popens.items():
      popen.terminate()
    self.popens = {}

  def run(self, commands):
    while len(commands) > 0 or len(self.popens) > 0:
      while len(self.popens) < self.max_procs and len(commands) > 0:
        command = commands.pop()
        self.popens[command] = self.run_one_process(command)

      keys = list(self.popens.keys())
      something_happened = False
      for command in keys:
        popen = self.popens[command]
        ret = popen.poll()
        if ret is not None:
          something_happened = True
          if ret != 0:
            self.cleanup()
            print('Running command "%s" failed.' % command)
            sys.exit(1)
          else:
            del self.popens[command]
            print('Command "%s" succeeded.' % command)
      if not something_happened:
        time.sleep(0.1)


def run_command(command):
  print(command)
  if os.system(command):
    print('Running command "%s" failed.' % command)
    sys.exit(1)


def create_build_config(schematic):
  path = 'build/autogen'
  # TODO(testing): Actually use |schematic| value.
  if schematic:
    path += '_schematic'
  exists = os.path.exists(path)
  if not exists:
    os.makedirs(path)
  os.chdir(path)
  run_command('cmake BUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release ../..')
  run_command('make -j $(nproc)')
  os.chdir('../..')
  return path


def run_tests(path):
  run_command(os.path.join(path, 'tests'))


def run_synth(synth_cmd):
  pass


def run_synths():
  SYNTHS = ['synth_achronix', 'synth_coolrunner2', 'synth_easic', 'synth_ecp5', 'synth_gowin',
            'synth_greenpak4', 'synth_ice40', 'synth_intel', 'synth_xilinx']
  for synth_cmd in SYNTHS:
    run_synth(synth_cmd)


def run_formal_verification():
  IGNORES = ["workaround.v", "common.v"]
  files = glob.glob("*.v")
  commands = []
  for file in files:
    if file in IGNORES:
      continue
    name = os.path.splitext(os.path.basename(file))[0]
    commands.append('sby -t formally_verify.sby %s' % name)
  WorkerQueue().run(commands)


parser = argparse.ArgumentParser()
parser.add_argument('-f', '--formal', action='store_true', default=False, required=False)
parser.add_argument('-u', '--unit', action='store_true', default=False, required=False)
parser.add_argument('-s', '--synths', action='store_true', default=False, required=False)
parser.add_argument('-a', '--all', action='store_true', default=False, required=False)
args = parser.parse_args()

if args.unit or args.all:
  for schematic in [False, True]:
    print('Running test with schematic=%s' % str(schematic))
    path = create_build_config(schematic=schematic)
    run_tests(path)

if args.synths or args.all:
  os.chdir('verilog')
  run_synths()
  os.chdir('..')

if args.formal or args.all:
  os.chdir('verilog')
  run_formal_verification()
  os.chdir('..')
