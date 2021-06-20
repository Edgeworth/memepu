#!/usr/bin/env python3
# Copyright 2019 E.

from data import data_74LVC162244_symbol
from symbol import validate_data, insert_side

# TODO: replace all of this with direct generation?

def add_74LVC162244():
  validate_data(data_74LVC162244_symbol)
  # insert_side(
  #     data_74LVC162244_symbol, group='vcc', pin_type='powerinput', side='up')
  # insert_side(
  #   data_74LVC162244_symbol, group='gnd', pin_type='powerinput', side='down')
  # insert_side(
  #   data_74LVC162244_symbol, group='A', pin_type='input', side='left')
  # insert_side(
  #   data_74LVC162244_symbol, group='Y', pin_type='input', side='right')
  insert_side(
    data_74LVC162244_symbol, group='~oe', pin_type='input', side='up')

def main():
  # subprocess.call(['xdotool', 'search', '--name', '/Eeschema.*/', 'windowfocus'])
  # validate_data(data_71V632_symbol)
  # insert_side(data_71V632_symbol, 'gnd', 'down', 'powerinput')
  # insert_labels(data_DDR2_labels['left'][60:], rot=2)
  # insert_labels(data_DDR2_labels['right'][20:])
  # validate_data(data_GTL2000_symbol)
  # insert_side(data_GTL2000_symbol, 'D', 'right', 'bidirectional')
  add_74LVC162244()


if __name__ == '__main__':
  main()
