# Copyright 2019 E.
# Symbol data format:
#   group_name: <array>|<dict>
#     |group_name| is case insensitive (converted to upper-case)
#     If the value is an array of integers, pins named by the group name and
#     each integer are created. If the array length is 1, just the group name is
#     used. If a dictionary of pin name to number is given, those pin names are
#     used.
#   num_pins: Indicates the total number of pins in the symbol, for error checking.
data_71V632_symbol = {
    'io': [
        52, 53, 56, 57, 58, 59, 62, 63, 68, 69, 72, 73, 74, 75, 78, 79, 2, 3, 6,
        7, 8, 9, 12, 13, 18, 19, 22, 23, 24, 25, 28, 29
    ],
    'vcc': [4, 11, 15, 20, 27, 41, 54, 61, 65, 70, 77, 91],
    'gnd': [5, 10, 17, 21, 26, 40, 55, 60, 67, 71, 76, 90],
    'addr': [37, 36, 35, 34, 33, 32, 100, 99, 82, 81, 44, 45, 46, 47, 48, 49],
    'control': {
        '~lbo': 31,
        '~adv': 83,
        '~adsp': 84,
        '~adsc': 85,
        '~oe': 86,
        '~bwe': 87,
        '~gw': 88,
        'clk': 89,
        '~cs0': 97,
        '~cs1': 92,
        '~ce': 98,
        '~bw1': 93,
        '~bw2': 94,
        '~bw3': 95,
        '~bw4': 96,
    },
    'nc': [1, 14, 16, 30, 38, 39, 42, 43, 50, 51, 64, 66, 80],
    'num_pins':
        100
}

data_GTL2000_symbol = {
    'refs': {
        'SREF': 2,
        'GREF': 48,
        'DREF': 67
    },
    'gnd': [1],
    'D': [
        46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29,
        28, 27, 26, 25
    ],
    'S': [
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
        23, 24
    ],
    'num_pins':
        48
}

data_74LVC162244_symbol = {
  'vcc': [7, 18, 42, 31],
  'gnd': [4, 10, 15, 21, 28, 34, 39, 45],
  'Y': [2, 3, 5, 6, 8, 9, 11, 12, 13, 14, 16, 17, 19, 20, 22, 23],
  'A': [47, 46, 44, 43, 41, 40, 38, 37, 36, 35, 33, 32, 30, 29, 27, 26],
  '~oe': [1, 48, 25, 24],
  'num_pins': 48
}

# Check:  Pins 69, 83, 120 used by 4 rank DDR2 SO-DIMMs.
# BA2 is NC for 256 MB and 512 MB
data_DDR2_labels = {
    'left': [
        'VREF', 'GND', 'DQ0', 'DQ1', 'GND', '~DQS0', 'DQS0', 'GND', 'DQ2',
        'DQ3', 'GND', 'DQ8', 'DQ9', 'GND', '~DQS1', 'DQS1', 'GND', 'DQ10',
        'DQ11', 'GND', 'GND', 'DQ16', 'DQ17', 'GND', '~DQS2', 'DQS2', 'GND',
        'DQ18', 'DQ19', 'GND', 'DQ24', 'DQ25', 'GND', 'DM3', 'NC', 'GND',
        'DQ26', 'DQ27', 'GND', 'CKE0', 'VDD', 'NC', 'BA2', 'VDD', 'A12', 'A9',
        'A8', 'VDD', 'A5', 'A3', 'A1', 'VDD', 'A10/AP', 'BA0', '~WE', 'VDD',
        '~CAS', '~S1', 'VDD', 'ODT1', 'GND', 'DQ32', 'DQ33', 'GND', '~DQS4',
        'DQS4', 'GND', 'DQ34', 'DQ35', 'GND', 'DQ40', 'DQ41', 'GND', 'DM5',
        'GND', 'DQ42', 'DQ43', 'GND', 'DQ48', 'DQ49', 'GND', 'NC', 'GND',
        '~DQS6', 'DQS6', 'GND', 'DQ50', 'DQ51', 'GND', 'DQ56', 'DQ57', 'GND',
        'DM7', 'GND', 'DQ58', 'DQ59', 'GND', 'SDA', 'SCL', 'VDDSPD'
    ],
    'right': [
        'GND', 'DQ4', 'DQ5', 'GND', 'DM0', 'GND', 'DQ6', 'DQ7', 'GND', 'DQ12',
        'DQ13', 'GND', 'DM1', 'GND', 'CK0', '~CK0', 'GND', 'DQ14', 'DQ15',
        'GND', 'GND', 'DQ20', 'DQ21', 'GND', 'NC', 'DM2', 'GND', 'DQ22', 'DQ23',
        'GND', 'DQ28', 'DQ29', 'GND', '~DQS3', 'DQS3', 'GND', 'DQ30', 'DQ31',
        'GND', 'CKE1', 'VDD', 'NC', 'NC', 'VDD', 'A11', 'A7', 'A6', 'VDD', 'A4',
        'A2', 'A0', 'VDD', 'BA1', '~RAS', '~S0', 'VDD', 'ODT0', 'A13', 'VDD',
        'NC', 'GND', 'DQ36', 'DQ37', 'GND', 'DM4', 'GND', 'DQ38', 'DQ39', 'GND',
        'DQ44', 'DQ45', 'GND', '~DQS5', 'DQS5', 'GND', 'DQ46', 'DQ47', 'GND',
        'DQ52', 'DQ53', 'GND', 'CK1', '~CK1', 'GND', 'DM6', 'GND', 'DQ54',
        'DQ55', 'GND', 'DQ60', 'DQ61', 'GND', '~DQS7', 'DQS7', 'GND', 'DQ62',
        'DQ63', 'GND', 'SA0', 'SA1'
    ]
}
