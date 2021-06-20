# Copyright 2019 E.
import time

from common import run_xdotool_key, nav, tr, listify


def validate_data(data):
  num_pins = data['num_pins']
  pins = listify(data.get('nc', []))
  for group in data.keys():
    if group == 'num_pins' or group == 'nc':
      continue
    group_data = data.get(group, {})
    if isinstance(group_data, dict):
      for k, v in group_data.items():
        pins.extend(listify(v))
    else:
      pins.extend(listify(group_data))
  assert len(pins) == num_pins and len(set(pins)) == num_pins


PIN_TYPES = {
    'input': 0,
    'output': 1,
    'bidirectional': 2,
    'tristate': 3,
    'powerinput': 6,
}

PIN_DIR = {
    'left': (0, 'D'),
    'right': (1, 'D'),
    'down': (2, 'R'),
    'up': (3, 'R'),
}

DIALOG_DELAY = 0.5


def reset_pin_dialog(side):
  run_xdotool_key(*nav('p'))
  time.sleep(DIALOG_DELAY)  # wait a bit for the dialog to appear
  # Need to actually place pin to set settings.A2
  run_xdotool_key('Tab', 'Tab', *nav('10U'), *(['Tab'] * 4), *nav('4U'), 'Tab',
                  *tr('2.54'), *nav('E'))
  time.sleep(DIALOG_DELAY)  # wait a bit for the dialog to appear
  run_xdotool_key(*nav('E' + PIN_DIR[side][1] * 2))

def insert_pins(prefix, numbers, pin_type, side):
  """
    Inserts pins of a certain type on a given side.

    :param prefix: Base name of a pin, e.g. A5 => A
    :param numbers: Pin numbers to add
    :param pin_type: Pin type
    :param side: Pin side (up, left, right, down)
    :return:
    """
  prefix = prefix.upper()
  for i, pin_number in enumerate(numbers):
    pin_name = prefix
    if len(numbers) > 1:
      pin_name += str(i)
    run_xdotool_key(*nav('p'))
    time.sleep(DIALOG_DELAY)  # wait a bit for the dialog to appear
    run_xdotool_key(*tr(pin_name), 'Tab', *tr(pin_number), 'Tab')
    if i == 0:  # Set up pin properties.
      run_xdotool_key(*(['Down'] * PIN_TYPES[pin_type]), *(['Tab'] * 4),
                      *(['Down'] * PIN_DIR[side][0]))
    run_xdotool_key('Tab', 'Tab', *nav('E'))
    time.sleep(DIALOG_DELAY) # wait a bit for the dialog to disappear
    run_xdotool_key(*nav('E' + PIN_DIR[side][1] * 2))


def insert_side(data, group, pin_type, side):
  """
    Runs the commands for inserting some pins into the Kicad schematic editor.

    :param data:
    :param group:
    :param pin_type: Pin type
    :param side: Pin side (up, left, right, down)
    :return:
    """
  reset_pin_dialog(side)
  group_data = data[group]
  if isinstance(group_data, list):
    group_data = {group: group_data}
  for k, v in group_data.items():
    insert_pins(k, listify(v), pin_type, side)
    reset_pin_dialog(side)
