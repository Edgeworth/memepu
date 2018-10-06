#!/usr/bin/env python3
import subprocess
import kicad_data


subprocess.call(['xdotool', 'search', '--name', '/Eeschema.*/', 'windowfocus'])

def chunks(l, n):
	return [l[i:i+n] for i in range(0, len(l), n)]

def tr(s):
	m = str.maketrans({'_': 'underscore', '~': 'asciitilde', '.': 'period'})
	return [c.translate(m) for c in s]

def replace(l, fr, to):
	return [i.replace(fr, to) for i in l]

def run_xdotool_key(*keys):
	cmd = ['xdotool', 'key', '--delay', '20'] + list(keys)
	subprocess.call(['echo'] + cmd)
	subprocess.call(cmd)

def nav(s):
	d = {'U': 'Up', 'D': 'Down', 'R': 'Right', 'L': 'Left', 'E': 'Return', 'X': 'Delete', 'T': 'Tab'}
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
		else:
			code = mod+d.get(c, c)
			mod = ''
			if cur != -1:
				code = [code] * cur
				cur = -1
			else:
				code = [code]
			res += code
	return res

def generate_clk_anders(left_labels, right_labels, local_labels=[]):
	col_count = 0
	for l in chunks(list(zip(left_labels, right_labels)), 4):
		run_xdotool_key('l', *tr('CLK'), *nav('ErrEDD'))
		for left, right in l:
			run_xdotool_key('l', *tr(left), *nav('ErrECRR2U'))
			key = 'l' if left in local_labels else 'h'
			run_xdotool_key(key, *tr(right), *nav('ErrE2DCLL2D'))
		run_xdotool_key(*nav('4D'))
		col_count += 1

		if col_count == 2:
			col_count = 0
			run_xdotool_key(*nav('6U4CR2CU2U'))

def generate_nclk_notters(labels):
	for l in chunks(labels, 6):
		for label in l:
			run_xdotool_key('l', *tr(label), *nav('ErrECR2R'))
			run_xdotool_key('l', *tr(label.replace('~', '')), *nav('EE6DCL2L'))
		run_xdotool_key(*nav('6U4CR3CU'))

def import_hierarchical_labels(num):
	for i in range(num):
		run_xdotool_key(*nav('2E2D'))

def delete_hierarchical_labels(num):
	for i in range(num):
		run_xdotool_key('Delete', *nav('2DE2D'))

def shuffle_pins_down(num_pins, num_move):
	for i in range(num_pins):
		run_xdotool_key(*nav('LmDEURmDE' * num_move * 2))
		run_xdotool_key(*nav('2U' + str(num_move * 2) + 'U'))

def shuffle_pins_up(num_pins, num_move):
	for i in range(num_pins):
		run_xdotool_key(*nav('LmUEDRmUE' * num_move * 2))
		run_xdotool_key(*nav('2D' + str(num_move * 2) + 'D'))

def generate_labels(labels, t='l', rot=0):
	for l in labels:
		run_xdotool_key(t, *tr(l), *nav('E' + str(rot) + 'r' + 'EDD'))

def sgn(x):
	return -1 if x < 0 else 1

def x_to_navstr(x):
	big, small = sgn(x) * (abs(x) // 10), sgn(x) * (abs(x) % 10)
	c = ''
	if x < 0: c = 'L'
	if x > 0: c = 'R'
	s = ''
	if big != 0: s += str(abs(big)) + 'C' + c
	if small != 0: s += str(abs(small)) + c
	return s

def pcbnew_rotate_strip_270(num):
	x = 2
	skip = 10
	label = 0
	for i in range(num):
		run_xdotool_key(*nav('EmErrrEm2U%sECD2U%sEm%sDECUE%sE' % (x_to_navstr(x), x_to_navstr(-label), x_to_navstr(label), x_to_navstr(skip))))
		x -= 1
		skip += 1
		label -= 1

def pcbnew_rotate_leds_after(num):
	for i in range(num):
		run_xdotool_key(*nav('EmErrEm5DECR5U'))


# shuffle_pins_up(8, 8)

import_hierarchical_labels(8)

# for label in out_labels[:20]:
# 	run_xdotool_key(*nav('l'), *tr(label), *nav('EE2D'))
