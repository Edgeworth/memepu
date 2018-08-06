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
  LDA 99
  RFI ;Return from interrupt.
