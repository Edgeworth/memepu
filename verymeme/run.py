#!/usr/bin/env python3
import argparse
import glob
import os
import sys


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
  for file in files:
    if file in IGNORES:
      continue
    name = os.path.splitext(os.path.basename(file))[0]
    run_command('sby -t formally_verify.sby %s' % name)


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
