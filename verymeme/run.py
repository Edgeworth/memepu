#!/usr/bin/env python3
import argparse
import os
import sys


def run_command(command):
  print(command)
  if os.system(command):
    sys.exit(1)


def create_build_config(schematic):
  path = "build/autogen"
  if schematic:
    path += "_schematic"
  exists = os.path.exists(path)
  if not exists:
    os.makedirs(path)
  os.chdir(path)
  if not exists:
    run_command("cmake BUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release ../..")
  run_command("make -j $(nproc)")
  os.chdir('../..')
  return path


def run_tests(path):
  run_command(os.path.join(path, 'tests'))


parser = argparse.ArgumentParser()
parser.add_argument('-t', '--test', action='store_true', default=False, required=False)
args = parser.parse_args()

if args.test:
  for schematic in [False, True]:
    print("Running test with schematic=%s" % str(schematic))
    path = create_build_config(schematic=schematic)
    run_tests(path)
