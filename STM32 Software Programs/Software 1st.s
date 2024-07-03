  AREA MYCODE, CODE, READONLY
  ENTRY
__main
  EXPORT __main  
	  
  ; finish the code
  LDR R0, =data
  LDR R1, =0x20001000
  LDR R2, =16
  
__loop_1
  LDRB R3, [R0], #1
  STRB R3, [R1], #1
  SUBS R2, R2, #1
  BNE __loop_1
  
  LDR R0, =data + 15
  LDR R1, =0x20002000
  LDR R2, =16
  
__loop_2
  LDRB R3, [R0], #-1
  STRB R3, [R1], #1
  SUBS R2, R2, #1
  BNE __loop_2
  
  
  ALIGN 4
data DCB 12,25,43,65,19,234,34,123,198,45,87,90,102,9,56,39
  END
  