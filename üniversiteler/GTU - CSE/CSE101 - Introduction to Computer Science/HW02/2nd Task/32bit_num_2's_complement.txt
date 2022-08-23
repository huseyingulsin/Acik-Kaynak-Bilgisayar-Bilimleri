load R4,01001000b		;first part of the selected 32bit number
load R5,10010000b		;second part of the selected 32bit number
load R6,01001101b		;third part of the selected 32bit number
load R7,01011001b		;fourth part of the selected 32bit number
load R8,11111111b		;for converting 1's complement
load R9,00000001b		;for converting 2's complement

xor R4,R4,R8		;R4's 1's complement
xor R5,R5,R8		;R5's 1's complement
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
move R0,R4			;first part of 32bit number 2's complement
move R1,R5			;second part of 32bit number 2's complement
move R2,R6			;third part of 32bit number 2's complement
move R3,R7			;fourh part of 32bit number 2's complement
store R0,[00]		;store first part in memory 0000
store R1,[01]		;store second part in memory 0001
store R2,[02]		;store thirdpart in memory 0002
store R3,[03]		;store fourh part in memory 0003
halt

Text:    db      10
         db      "It is The 2's complement",10
         db      "of an 32bit number",10
         db      "-Muhammed Oguz",10
         db      0

halt

