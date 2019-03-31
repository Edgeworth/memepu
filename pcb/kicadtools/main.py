#!/usr/bin/env python3

from data import data_74LVC162244_symbol
from symbol import validate_data, insert_side


def main():
  # subprocess.call(['xdotool', 'search', '--name', '/Eeschema.*/', 'windowfocus'])
  # validate_data(data_71V632_symbol)
  # insert_side(data_71V632_symbol, 'gnd', 'down', 'powerinput')
  # insert_labels(data_DDR2_labels['left'][60:], rot=2)
  # insert_labels(data_DDR2_labels['right'][20:])
  # validate_data(data_GTL2000_symbol)
  # insert_side(data_GTL2000_symbol, 'D', 'right', 'bidirectional')
  validate_data(data_74LVC162244_symbol)
  insert_side(
      data_74LVC162244_symbol,
      group='D',
      pin_type='bidirectional',
      side='right')


if __name__ == '__main__':
  main()
