; Memory layout:
; 0: PC0 PC1 PC2 A
; 4: B TASK . .
; 8: Device 0 data size, Device data
;Kernel
LDA 0
STA 8 ;No data from device 0
EINT ;Enable interrupts.
mainloop:
	TASK 010000 ;Start task
	JMP mainloop

010000: ;Program
LDA 0
LDB 1
start: ;Compute fibonnaci
  ADD
  DSP
  SWP
  JMP start

020000: ;Syscall handler
	LDA 1 ;Currently only one syscall - read from device
	STA 8 ;Save waiting for syscall flag

040000: ;Interrupt handler
  IN0 ;Currently the only possible cause is data from device 0.
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
