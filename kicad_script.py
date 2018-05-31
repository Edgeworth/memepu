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
'~K0_IN_NCLK',
'~K1_IN_NCLK',
'~K2_IN_NCLK',
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

out_labels = ['~A_OUT_NCLK',
'~B_OUT_NCLK',
'~M0_OUT_NCLK',
'~M1_OUT_NCLK',
'~M2_OUT_NCLK',
'~S0_OUT_NCLK',
'~S1_OUT_NCLK',
'~S2_OUT_NCLK',
'~K0_OUT_NCLK',
'~K1_OUT_NCLK',
'~K2_OUT_NCLK',
'~STATUS_OUT_NCLK',
'~INTERRUPT_OUT_NCLK',
'~SUM_OUT_NCLK',
'~MMU_OUT_NCLK',
'~MMU_CONTROL_OUT_NCLK',
'~TASK_OUT_NCLK',
'~MLU_OUT_NCLK',
'~CTRLLOGIC_OUT_NCLK']

ctrl_labels_nclk = ["~SUB_NCLK",
"~RESET_NCLK",
"~RESET_UOP_COUNT_NCLK",
"~SET_INT_ENABLE_SYNC",
"~UNSET_INT_ENABLE_SYNC"]

ctrl_labels_clk = [
"~PC_INC_NCLK",
"~OPCODE0_INC_NCLK",
"~OPCODE1_INC_NCLK",
"~SP_INC_NCLK",
"~SP_DEC_NCLK",
"~KSP_INC_NCLK",
"~KSP_DEC_NCLK",
"~ALU_FLAG_SET_NCLK"]

ctrl_local_lables = [
'OPCODE0_INC_NCLK', 'OPCODE1_INC_NCLK'
]

subprocess.call(['xdotool', 'search', '--name', '/Eeschema.*/', 'windowfocus'])

def chunks(l, n):
	return [l[i:i+n] for i in range(0, len(l), n)]

def tr(s):
	m = str.maketrans({'_': 'underscore', '~': 'asciitilde'})
	return [c.translate(m) for c in s]

def replace(l, fr, to):
	return [i.replace(fr, to) for i in l]

def run_xdotool_key(*keys):
	cmd = ['xdotool', 'key', '--delay', '15'] + list(keys)
	subprocess.call(['echo'] + cmd)
	subprocess.call(cmd)

def generate_labels(labels, t='l', rot=0):
	for l in labels:
		run_xdotool_key(t, *tr(l), *nav('E' + str(rot) + 'r' + 'EDD'))

def nav(s):
	d = {'U': 'Up', 'D': 'Down', 'R': 'Right', 'L': 'Left', 'E': 'Return'}
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

# generate_labels(ctrl_labels_nclk, 'h', 2)
# generate_labels(ctrl_labels_clk)
# generate_nclk_notters(in_labels)

# in_labels_pos = replace(in_labels, '~', '')
# generate_clk_anders(in_labels_pos, replace(in_labels_pos, 'NCLK', 'CLK'), in_local_labels)


ctrl_labels_clk_pos = replace(ctrl_labels_clk, '~', '')
generate_clk_anders(ctrl_labels_clk_pos, replace(ctrl_labels_clk_pos, 'NCLK', 'CLK'), ctrl_local_lables)