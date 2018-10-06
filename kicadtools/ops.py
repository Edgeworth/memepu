from common import *


def generate_clk_anders(left_labels, right_labels, local_labels=None):
    if local_labels is None:
        local_labels = []
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


def pcbnew_rotate_strip_270(num):
    x = 2
    skip = 10
    label = 0
    for i in range(num):
        run_xdotool_key(*nav('EmErrrEm2U%sECD2U%sEm%sDECUE%sE' % (
            x_to_navstr(x), x_to_navstr(-label), x_to_navstr(label), x_to_navstr(skip))))
        x -= 1
        skip += 1
        label -= 1


def pcbnew_rotate_leds_after(num):
    for i in range(num):
        run_xdotool_key(*nav('EmErrEm5DECR5U'))
