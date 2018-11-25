#!/usr/bin/env python3
import time

from data import data_DDR2_labels, data_GTL2000_symbol
from symbol import validate_data, insert_side


def main():
    # subprocess.call(['xdotool', 'search', '--name', '/Eeschema.*/', 'windowfocus'])
    # validate_data(data_71V632_symbol)
    # insert_side(data_71V632_symbol, 'gnd', 'down', 'powerinput')
    # insert_labels(data_DDR2_labels['left'][60:], rot=2)
    # insert_labels(data_DDR2_labels['right'][20:])
    validate_data(data_GTL2000_symbol)
    insert_side(data_GTL2000_symbol, 'D', 'right', 'bidirectional')


if __name__ == '__main__':
    main()
