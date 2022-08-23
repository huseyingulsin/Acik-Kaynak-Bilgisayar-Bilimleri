.data
    arr: .word 17,7,25,28,9,74,88
    size: .word 7
    new_line: .asciiz "\n"
    here: .asciiz "here\n"
    empty_space: .asciiz " "
    buffer: .space 1024
    fout: .asciiz "out.txt"

.text
fill_buffer:
    lb $s4, new_line
    lb $s5, empty_space
    lw $s6, size # keep size
    addi $s7, $zero, 10 # keep this for division

    addi $t8, $zero, 0 # keep this for buffer position

    addi $t0, $zero, 0 # i = 0;
    addi $t1, $zero, 0 # address keeper

    whileWrite:
        beq $t0, $s6, endWhileWrite # if i == size, break

        lw $t2, arr($t1) # t2 = arr[i]
  
        div $t2, $s7 # t2 = t2 / 10
        mflo $t2 # t2 = t2 / 10
        mfhi $t3 # t3 = t2 % 10

        bgt $t2, 10, oneStep # if t2 > 10, go to oneStep

        addi $t2, $t2, 48 # t2 = t2 + 48 (ascii)
        addi $t3, $t3, 48 # t3 = t3 + 48 (ascii)

        sb $t2, buffer($t8) # buffer[i] = t2
        addi $t8, $t8, 1 # increment buffer position
        sb $t3, buffer($t8) # buffer[i] = t3
        addi $t8, $t8, 1 # increment buffer position
        sb $s5, buffer($t8) # buffer[i] = ' 
        addi $t8, $t8, 1 # increment buffer position

        li $v0, 4 # syscall 4
        la $a0, buffer
        syscall

        li $v0, 4 # syscall 4
        la $a0, new_line
        syscall

        addi $t0, $t0, 1 # i++
        addi $t1, $t1, 4 # address keeper += 4
        
        j whileWrite # goto whileWrite

        oneStep:

            div $t2, $s7 # t2 = t2 / 10
            mflo $t2 # t2 = t2 / 10
            mfhi $t4 # t3 = t2 % 10

            addi $t2, $t2, 48 # t2 = t2 + 48 (ascii)
            addi $t4, $t4, 48 # t3 = t3 + 48 (ascii)
            addi $t3, $t3, 48 # t3 = t3 + 48 (ascii)

            sb $t2, buffer($t8) # buffer[i] = t2
            addi $t8, $t8, 1 # increment buffer position
            sb $t4, buffer($t8) # buffer[i] = t4
            addi $t8, $t8, 1 # increment buffer position
            sb $t3, buffer($t8) # buffer[i] = t3
            addi $t8, $t8, 1 # increment buffer position
            sb $s5, buffer($t8) # buffer[i] = ' 
            addi $t8, $t8, 1 # increment buffer position

            li $v0, 4 # syscall 4
            la $a0, buffer
            syscall

            li $v0, 4 # syscall 4
            la $a0, new_line
            syscall

            addi $t0, $t0, 1 # i++
            addi $t1, $t1, 4 # address keeper += 4
            
            j whileWrite # goto whileWrite

    endWhileWrite:

    sb $s4, buffer($t8) # buffer[i] = '\n'

    jal writeToFile

    li $v0, 10
    syscall

writeToFile:
# Open (for writing) a file that does not exist
    li   $v0, 13       # system call for open file
    la   $a0, fout     # output file name
    li   $a1, 1       # Open for writing (flags are 0: read, 1: write)
    li   $a2, 0        # mode is ignored
    syscall            # open a file (file descriptor returned in $v0)
    move $s6, $v0      # save the file descriptor 

    # Write to file just opened
    li   $v0, 15       # system call for write to file
    move $a0, $s6      # file descriptor 
    la $a1, buffer      # address of buffer from which to write
    li   $a2, 1024        # hardcoded buffer length
    syscall            # write to file

    # Close the file 
    li   $v0, 16       # system call for close file
    move $a0, $s6      # file descriptor to close
    syscall            # close file

    jr $ra