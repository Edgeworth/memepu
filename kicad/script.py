from pcbnew import *

board = GetBoard()
netcodes = board.GetNetsByNetcode()

modules = board.GetModules()
for m in modules:
    pos = m.GetPosition()
    if pos[0] % 500000 != 0 or pos[1] % 500000 != 0:
        new_pos = wxPoint(pos[0] / 500000 * 500000, pos[1] / 500000 * 500000)
        print "Repositioning", m.GetReference(), "from", pos, "to", new_pos
        m.SetPosition(new_pos)
        
