# Copyright 2019 E.
import re
import sys


def map_byte(val):
  m = ['00', 'ff']
  return m[val & 1] + m[(val >> 1) & 1] + m[(val >> 2) & 1] + m[(val >> 3) & 1]


def parse_bdf(data):
  res = re.findall(
    r'STARTCHAR (\w+).*?ENCODING (\d+).*?BBX (\d+) (\d+) (\d+) (\d+).*?BITMAP\n(([0-9a-fA-F]+\n)*)ENDCHAR',
    data, re.S)
  m = {}
  for name, num, w, h, xoff, yoff, bytes, _ in res:
    bytes = bytes.strip().split('\n')
    w, h, xoff, yoff = int(w), int(h), int(xoff), int(yoff)
    if w > 4 or h > 5:
      print("err for", name, w, h, xoff, yoff)
      sys.exit(1)
    bytes = bytes + ['00'] * yoff
    bytes = ['00'] * (5 - len(bytes)) + bytes
    print('bitmap' + name + ':')
    for byte in bytes:
      val = int(byte[0], 16) >> xoff
      print('dw', map_byte(val))


if len(sys.argv) != 2:
  print("Need bdf font file")
  sys.exit(1)

parse_bdf(open(sys.argv[1]).read())
