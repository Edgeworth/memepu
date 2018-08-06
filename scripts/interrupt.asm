LDA 1
LDB 1
EINT ;Enable interrupts.
start0:
  DSP
  STA 2048
  LDAADDR 2048
  DSP
  ADD
  JMP start0
LDA 0
LDB 1
start: ;Compute fibonnaci
  ADD
  DSP
  SWP
  JMP start

;Interrupt handler
040000:
  LDAADDR 0
  DSP
  LDAADDR 1
  DSP
  LDAADDR 2
  DSP
  LDAADDR 3
  DSP
  LDAADDR 4
  DSP
  RFI ;Return from interrupt.
