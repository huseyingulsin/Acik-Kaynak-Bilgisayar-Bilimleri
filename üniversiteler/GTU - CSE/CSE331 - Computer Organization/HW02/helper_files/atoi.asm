.data
    str: .asciiz "143 1 2342"

.text
    main:
        la $t0, str # load string address
        addi $t1, $zero, 0 # t1 = res = 0

        whileAtoi:

            lb $t2, 0($t0) # load char

            beq $t2, $zero, endAtoi
            beq $t2, '\n', endAtoi
            beq $t2, ' ', increment_next

            addi $t2, $t2, -48 # convert to char to int

            mul $t1, $t1, 10 # res *= 10
            add $t1, $t1, $t2 # res += temp

            increment_next:
            addi $t0, $t0, 1 # go to next char
        
            j whileAtoi

        endAtoi:

        li $v0, 1
        move $a0, $t1
        syscall

