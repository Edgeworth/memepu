#!/usr/bin/env python3
import subprocess

in_labels = [
'~A_IN_NCLK',
'~B_IN_NCLK',
'~M0_IN_NCLK',
'~M1_IN_NCLK',
'~M2_IN_NCLK',
'~S0_IN_NCLK',
'~S1_IN_NCLK',
'~S2_IN_NCLK',
'~PC0_IN_NCLK',
'~PC1_IN_NCLK',
'~PC2_IN_NCLK',
'~MMU0_IN_NCLK',
'~MMU1_IN_NCLK',
'~MMU2_IN_NCLK',
'~MMU_IN_NCLK',
'~MMU_CONTROL_IN_NCLK',
'~DISP_IN_NCLK',
'~TASK_IN_NCLK',
'~OPCODE0_IN_NCLK',
'~OPCODE1_IN_NCLK',
'~INT0_IN_NCLK',
'~INT1_IN_NCLK',
'~INT2_IN_NCLK',
'~INT3_IN_NCLK',
'~INT4_IN_NCLK',
'~INT5_IN_NCLK',
'~INT6_IN_NCLK',
'~INT7_IN_NCLK',
]

# Out of in_labels, when we make CLK versions, these ones should be
# local rather than hierarchical labels.
in_local_labels = ['OPCODE0_IN_NCLK', 'OPCODE1_IN_NCLK']

out_labels = [
'~A_OUT_NCLK',
'~B_OUT_NCLK',
'~M0_OUT_NCLK',
'~M1_OUT_NCLK',
'~M2_OUT_NCLK',
'~S0_OUT_NCLK',
'~S1_OUT_NCLK',
'~S2_OUT_NCLK',
'~PC0_OUT_NCLK',
'~PC1_OUT_NCLK',
'~PC2_OUT_NCLK',
'~STATUS_OUT_NCLK',
'~INT_OUT_NCLK',
'~SUM_OUT_NCLK',
'~MMU_OUT_NCLK',
'~MMU_CONTROL_OUT_NCLK',
'~TASK_OUT_NCLK',
'~MLU_OUT_NCLK',
'~CTRLLOGIC_OUT_NCLK',
'~INT0_OUT_NCLK',
'~INT1_OUT_NCLK',
'~INT2_OUT_NCLK',
'~INT3_OUT_NCLK',
'~INT4_OUT_NCLK',
'~INT5_OUT_NCLK',
'~INT6_OUT_NCLK',
'~INT7_OUT_NCLK',
]

ctrl_labels = [
'SUB_NCLK',
'~RESET_NCLK',
'~RESET_UOP_COUNT_NCLK',
'~SET_INT_ENABLE_ASYNC',
'~UNSET_INT_ENABLE_ASYNC',
'PC_INC_NCLK',
'~SP_INC_NCLK',
'~SP_DEC_NCLK',
'ALU_FLAG_SET_NCLK',
]

misc_labels = [
'MICROOP0',
'MICROOP1',
'MICROOP2',
'MICROOP3',
'MMU_READ_FAULT',
'MMU_WRITE_FAULT',
'INT0_LATCH',
'INT1_LATCH',
'INT2_LATCH',
'INT3_LATCH',
'INT4_LATCH',
'INT5_LATCH',
'INT6_LATCH',
'INT7_LATCH',
]

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

def generate_control_logic_leds(labels, diode_labels):
	for l, d in zip(labels, diode_labels):
		run_xdotool_key(*nav('h'), *tr(l), *nav('EECRv'), *tr(d), *nav('ECL4D'))

def change_resistor_values(num):
	for i in range(num):
		run_xdotool_key(*nav('v'), *tr('2.2K'), *nav('E4D'))

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

# pcbnew_rotate_strip_270(7)
# pcbnew_rotate_leds_after(5)

# generate_nclk_notters(in_labels)

# in_labels_pos = replace(in_labels, '~', '')
# generate_clk_anders(in_labels_pos, replace(in_labels_pos, 'NCLK', 'CLK'), in_local_labels)

# ctrl_labels_clk_pos = replace(ctrl_labels_clk, '~', '')
# generate_clk_anders(ctrl_labels_clk_pos, replace(ctrl_labels_clk_pos, 'NCLK', 'CLK'), ctrl_local_lables)

# import_hierarchical_labels(len(misc_labels))

# shuffle_pins_down(8, 1)

# generate_labels(test)

shuffle_pins_up(12, 8)

# labels = replace(ctrl_labels + misc_labels, '_NCLK', '')
# generate_control_logic_leds(labels, replace(labels, '~', ''))
