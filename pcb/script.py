
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

def print_rect(r):
    print "Rect: ", ToMM(r.GetX()), ToMM(r.GetY()), ToMM(r.GetWidth()), ToMM(r.GetHeight())

def rotate_point(p, deg):
    while deg > 0:
        p = wxPoint(-p[1], p[0])
        deg -= 90
    return p

def position_labels():
    modules = board.GetModules()
    for m in modules:
        ref_text = m.GetReference()
        m_pos = m.GetPosition()
        ref = m.Reference()
        pos = ref.GetPosition()
        cur_rot = m.GetOrientation() + ref.GetDrawRotation()

        if ref_text.startswith('U'):
            if m.GetValue() not in ref_text:
                m.SetReference(ref_text + '-' + m.GetValue())
            ref.Rotate(pos, -cur_rot + 900)

            bb = ref.GetBoundingBox()
            w, h = bb.GetWidth(), bb.GetHeight()
            offset = max(w, h)
            new_pos = wxPoint(FromMM(2), FromMM(-0.5) + offset / 2)
            ref.SetPos(new_pos)
        if (ref_text.startswith('C') or ref_text.startswith('R') or
            ref_text.startswith('D') or ref_text.startswith('F')):
            ref.Rotate(pos, -cur_rot)
            center = m.GetFootprintRect().GetCenter() - m_pos
            center = rotate_point(center, m.GetOrientationDegrees())
            ref.SetPos0(center)

def undo_label_change():
    modules = board.GetModules()
    for m in modules:
        ref_text = m.GetReference()
        if ref_text.startswith('U'):
            m.SetReference(ref_text.split('-')[0])

snap_modules()
# position_labels()
# undo_label_change()