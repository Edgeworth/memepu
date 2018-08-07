LDA 0
LDB 1
EINT ;Enable interrupts.
start: ;Compute fibonnaci
  ADD
  DSP
  SWP
  JMP start
;Interrupt handler
040000:
  IN0
  CMP ;0 is dump, 1 is read. Compare A to 0.
  JZH dump
  LDA 1
  DSP
  OUT0 75 ;Send bytes
  OUT0 69
  OUT0 75
  OUT0 10
  OUT0 0
  JMP return
dump:
  LDA 0
  DSP
  DMP ;Dump internal state
return:
  RFI ;Return from interrupt.
