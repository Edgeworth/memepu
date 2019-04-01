import subprocess


def chunks(l, n):
  return [l[i:i + n] for i in range(0, len(l), n)]


def tr(s):
  m = str.maketrans({'_': 'underscore', '~': 'asciitilde', '.': 'period'})
  return [c.translate(m) for c in str(s)]


def replace(l, fr, to):
  return [i.replace(fr, to) for i in l]


def run_xdotool_key(*keys):
  cmd = ['xdotool', 'key', '--delay', '150'] + list(keys)
  subprocess.call(['echo'] + cmd)
  subprocess.call(cmd)


def nav(s):
  d = {
      'U': 'Up',
      'D': 'Down',
      'R': 'Right',
      'L': 'Left',
      'E': 'Return',
      'X': 'Delete',
      'T': 'Tab'
  }
  cur = -1
  mod = ''
  res = []
  for c in s:
    if c.isdigit():
      if cur == -1:
        cur = int(c)
      else:
        cur *= 10
        cur += int(c)
    elif c == 'C':
      mod = 'Control_L+'
    elif c == 'A':
      mod = 'Alt_L+'
    else:
      code = mod + d.get(c, c)
      mod = ''
      if cur != -1:
        code = [code] * cur
        cur = -1
      else:
        code = [code]
      res += code
  return res


def sgn(x):
  return -1 if x < 0 else 1


def x_to_navstr(x):
  big, small = sgn(x) * (abs(x) // 10), sgn(x) * (abs(x) % 10)
  c = ''
  if x < 0:
    c = 'L'
  if x > 0:
    c = 'R'
  s = ''
  if big != 0:
    s += str(abs(big)) + 'C' + c
  if small != 0:
    s += str(abs(small)) + c
  return s


def listify(a):
  if isinstance(a, list):
    return a[:]
  return [a]
