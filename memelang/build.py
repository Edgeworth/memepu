#!/usr/bin/env python3
import argparse
import os
import sys


def run_command(cmd):
    res = os.system(cmd)
    if res != 0:
        sys.exit(1)


parser = argparse.ArgumentParser()
parser.add_argument(
    '-t', '--type', choices=['debug', 'release', 'relwithdebinfo'],
    default='debug', required=False)
parser.add_argument('-a', '--use_afl', action='store_true', default=False, required=False)
parser.add_argument('targets', nargs='*', type=str)
args = parser.parse_args()

compiler = 'c++'
if args.use_afl:
    compiler = 'afl-clang-fast++'

defs = {
    'CMAKE_BUILD_TYPE': args.type,
    'CMAKE_CXX_COMPILER': compiler
}

build_dir = os.path.join('build', defs['CMAKE_CXX_COMPILER'] + '-' + defs['CMAKE_BUILD_TYPE'])
regenerate = False
if not os.path.exists(build_dir):
    os.makedirs(build_dir)
    regenerate = True

os.chdir(build_dir)

if regenerate:
    print('Regenerating cmake files.')
    def_str = ' '.join('-D %s=\'%s\'' % (i, k) for i, k in defs.items())
    run_command('cmake %s ../../' % def_str)

run_command('AFL_HARDEN=1 make -j16 %s' % ' '.join(args.targets))
os.chdir('../../')
