#!/usr/bin/env python3
import argparse
import os
import sys


def run_command(command):
  print(command)
  if os.system(command):
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
  if not exists:
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


parser = argparse.ArgumentParser()
parser.add_argument('-t', '--test', action='store_true', default=False, required=False)
args = parser.parse_args()

if args.test:
  for schematic in [False, True]:
    print('Running test with schematic=%s' % str(schematic))
    path = create_build_config(schematic=schematic)
    run_tests(path)
  os.chdir('verilog')
  run_synths()
  run_command('sby -t formally_verify.sby')
  os.chdir('..')
