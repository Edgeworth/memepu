LDA 0
LDB 1
start: ; Compute fibonnaci
  ADD
  DSP
  SWP
  JMP start

; Interrupt handler
040000:
  DMP ; Dump internal state
  RFI ; Return from interrupt.