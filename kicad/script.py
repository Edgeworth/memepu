
from pcbnew import *

board = GetBoard()
netcodes = board.GetNetsByNetcode()

def snap_modules():
    modules = board.GetModules()
    for m in modules:
        pos = m.GetPosition()
        if pos[0] % 500000 != 0 or pos[1] % 500000 != 0:
            new_pos = wxPoint(pos[0] / 500000 * 500000, pos[1] / 500000 * 500000)
            print "Repositioning", m.GetReference(), "from", pos, "to", new_pos
            m.SetPosition(new_pos)
            
def position_labels():
    modules = board.GetModules()
    for m in modules:
        ref_text = m.GetReference()
        # print ref_text
        if ref_text == 'U15':
            print "FOUND U15. Rotating."
            ref = m.Reference()
            pos = ref.GetPosition()
            cur_rot = ref.GetDrawRotation()
            ref.Rotate(pos, -cur_rot + 900)

position_labels()