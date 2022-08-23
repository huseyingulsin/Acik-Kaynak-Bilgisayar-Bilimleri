load R6,01001000b		;first part of the selected 16bit number
load R7,10010000b		;second part of the selected 16bit number
load R8,11111111b		;for converting 1's complement
load R9,00000001b			;for converting 2's complement

xor R6,R6,R8		;R6's 1's complement
xor R7,R7,R8		;R7's 1's complement
addi R7,R7,R9		;R7's 2's complement

;This Part For Fun
load    RA,Text    
load    RB,1       
load    R0,0
JumpPoint:
load    RF,[RA]     
addi    RA,RA,RB    
jmpEQ   RF=R0,Ready
jmp     JumpPoint 
Ready:
move R0,R6			;first part of 16bit number 2's complement
move R1,R7			;second part of 16bit number 2's complement
store R0,[00]		;store first part in memory 0000
store R1,[01]		;store second part in memory 0001
halt

Text:    db      10
         db      "It is The 2's complement",10
         db      "of an 16bit number",10
         db      "-Muhammed Oguz",10
         db      0

halt
