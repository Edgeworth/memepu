import time

from common import run_xdotool_key, nav, tr, listify


def validate_data(data):
    num_pins = data['num_pins']
    pins = listify(data.get('nc', []))
    for group in data.keys():
        if group == 'num_pins' or group == 'nc': continue
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


def reset_pin_dialog():
    run_xdotool_key(*nav('p'))
    time.sleep(0.05)  # wait a bit for the dialog to appear
    run_xdotool_key('Tab', 'Tab', *nav('10U'), *(['Tab'] * 4), *nav('4U'), 'Tab',
                    *tr('2.54'), *nav('E'), 'Escape')


def insert_pins(title, numbers, pin_type, side):
    title = title.upper()
    for i, pin_number in enumerate(numbers):
        pin_name = title
        if len(numbers) > 1: pin_name += str(i)
        run_xdotool_key(*nav('p'))
        time.sleep(0.05)  # wait a bit for the dialog to appear
        run_xdotool_key(*tr(pin_name), 'Tab', *tr(pin_number), 'Tab')
        if i == 0:  # Set up pin properties.
            run_xdotool_key(
                *(['Down'] * PIN_TYPES[pin_type]), *(['Tab'] * 4),
                *(['Down'] * PIN_DIR[side][0]))
        run_xdotool_key('Tab', 'Tab', *nav('EE' + PIN_DIR[side][1] * 2))


def insert_side(data, group, side, pin_type):
    reset_pin_dialog()
    group_data = data[group]
    if isinstance(group_data, list):
        group_data = {group: group_data}
    for k, v in group_data.items():
        insert_pins(k, listify(v), pin_type, side)
        reset_pin_dialog()
