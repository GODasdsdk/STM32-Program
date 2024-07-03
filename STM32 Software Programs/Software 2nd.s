  AREA MYCODE, CODE, READONLY
  ENTRY
__main2
  EXPORT __main2
  ; finish the code  
  LDR R0, =data1
  LDR R1, =data2
  LDR R3, =16
  LDR R6, =0x20001000
  
addLoop
  LDRB R4, [R0], #1
  LDRB R5, [R1], #1
  ADDS R4, R4, R5
  STRB R4, [R6], #1
  SUBS R3, R3, #1
  BNE addLoop
  
  LDR R0, =data1
  LDR R1, =data2
  LDR R3, =16
  LDR R6, =0x20002000
  
minusLoop
  LDRB R4, [R0], #1
  LDRB R5, [R1], #1
  SUBS R4, R4, R5
  STRB R4, [R6], #1
  SUBS R3, R3, #1
  BNE minusLoop
  
  
  ALIGN 4
data1 DCB 12,25,43,65,19,234,34,123,198,45,87,90,102,9,56,90
data2 DCB 250,20,12,216,19,60,29,178,190,1,20,38,128,6,200,39
  END