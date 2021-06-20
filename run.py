#!/usr/bin/env python3
# Copyright 2019 E.
import argparse
import glob
import multiprocessing
import os
import signal
import subprocess

import sys
import time

queue = None


def signal_handler(signum, frame):
  print('Got signal %s' % str(signum))
  if queue is not None:
    print('...shutting down queue')
    queue.cleanup()
    sys.exit(1)


class WorkerQueue:
  def __init__(self):
    self.popens = {}
    self.max_procs = multiprocessing.cpu_count()

  @staticmethod
  def run_one_process(command):
    print('Running command "%s".' % command)
    return subprocess.Popen(command, shell=True, stdin=subprocess.DEVNULL,
                            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

  def cleanup(self):
    for command, popen in self.popens.items():
      popen.terminate()
    self.popens = {}

  def run(self, commands):
    total_num_commands = len(commands)
    failed_commands = []
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
          del self.popens[command]
          finished_commands = total_num_commands - len(commands) - len(self.popens)
          status = 'succeeded'
          if ret != 0:
            status = 'FAILED'
            failed_commands.append(command)
          print(
            'Command "%s" %s. (%d/%d)' % (command, status, finished_commands, total_num_commands))
      if not something_happened:
        time.sleep(0.1)
    if failed_commands:
      print('FAILED: %s' % ', '.join(failed_commands))


def run_command(command):
  print(command)
  if os.system(command):
    print('Running command "%s" failed.' % command)
    sys.exit(1)


def create_build_config(hexfile):
  COMMON_FILE = 'verilog/common.v'
  VERYMEME_DIR = os.getcwd()
  path = '/tmp/verymeme'
  hexfile_define = ''
  if hexfile:
    path += '_hexfile'
    hexfile_define = '-DVERILOG_HEXFILE=YES'
  exists = os.path.exists(path)
  if not exists:
    os.makedirs(path)
  os.chdir(path)
  run_command(
    'cmake BUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release %s %s' % (hexfile_define, VERYMEME_DIR))
  run_command('make -j $(nproc)')
  os.chdir(VERYMEME_DIR)
  return path


def generate_memeware():
  path = create_build_config(hexfile=False)
  run_command('%s --output_path=./verilog' % os.path.join(path, 'memeware'))


def run_tests(path):
  run_command(os.path.join(path, 'tests'))


def run_formal_verification():
  global queue
  # Ignore explicit sram and lut instantiates because they take too long to run.s
  IGNORES = ["workaround.v", "common.v", "lut17x8.v", "lut12x8.v", "lut12x32.v", "sram5x32.v",
             "sram16x32.v"]
  files = glob.glob("*.v")
  commands = []
  for file in files:
    if file in IGNORES:
      continue
    name = os.path.splitext(os.path.basename(file))[0]
    commands.append('sby -t formally_verify.sby %s' % name)
  queue = WorkerQueue()  # Set global queue variable so we can clean-up on SIGINT.
  queue.run(commands)


def check_pwd():
  if not os.path.exists('verilog'):
    print('Current directory %s is wrong, go to memepu/verymeme' % os.getcwd())
    sys.exit(1)


parser = argparse.ArgumentParser()
parser.add_argument('-f', '--formal', action='store_true', default=False, required=False,
                    help='Run formal verification.')
parser.add_argument('-u', '--unit', action='store_true', default=False, required=False,
                    help='Run unit tests.')
parser.add_argument('-w', '--memeware', action='store_true', default=False, required=False,
                    help='Generate firmware.')
parser.add_argument('-g', '--generate_schematic', action='store_true', default=False,
                    required=False, help='Verifies schematics can be generated')
parser.add_argument('-a', '--all', action='store_true', default=False, required=False,
                    help='Run all.')
args = parser.parse_args()

check_pwd()

signal.signal(signal.SIGINT, signal_handler)

if args.memeware or args.all:
  generate_memeware()

if args.unit or args.all:
  for hexfile in [False, True]:
    print('Running test with hexfile=%s' % str(hexfile))
    path = create_build_config(hexfile=hexfile)
    run_tests(path)

if args.formal or args.all:
  os.chdir('verilog')
  run_formal_verification()
  os.chdir('..')

if args.generate_schematic or args.all:
  pass  # TODO
