.data  
fin: .asciiz "file.txt" # filename
buffer: .space 1024     # buffer - it will keep file content    

arr: .word 0:16         # every array assumed 16 size

whitespace: .asciiz " " 
newline: .asciiz "\n"

comma: .asciiz ","

.text

main:
    # call file reader func
    # keep all content in s0
    jal openFileAndRead
    
    addi $t3, $zero, 0 # t3 = 0, keeps array size
    addi $t4, $zero, 0 # t4 = 0, keeps array address location

    while:
        lb $t2, 0($s0) # load char

        beq $t2, $zero, end_arr # end of file
        beq $t2, 13, end_arr # end of line carriage return / new line
        beq $t2, ' ', new_int # end of word


        jal atoi

        j while

        end_arr:
            sw $t1, arr($t4) # store in array
            addi $t3, $t3, 1 # increment array size
            addi $t4, $t4, 4 # increment array address location

            jal printArr 

            li $v0, 4
            la $a0, newline
            syscall 

            lb $t2, 0($s0) # load char
            addi $t3, $zero, 0 # t3 = 0, keeps array size
            addi $t4, $zero, 0 # t4 = 0, keeps array address location

            beq $t2, 13, increment_two # it should pass two space

            j end

        increment_two:
            addi $s0, $s0, 2

            j while

        new_int:
            sw $t1, arr($t4) # store in array

            addi $t3, $t3, 1 # increment array size
            addi $t4, $t4, 4 # increment array address location

            addi $s0, $s0, 1

            j while
        
    end:


    # end of main
    li $v0, 10
    syscall



openFileAndRead:
    li   $v0, 13       # sys call for opening a file
    la   $a0, fin      # file name
    li   $a1, 0        # open in read mode
    li   $a2, 0        # ignore second arr
    syscall
    move $s6, $v0      # save the file descriptor 

    li   $v0, 14       # sys call for reading file
    move $a0, $s6      # file descriptor 
    la   $a1, buffer   # string buffer = file_content
    li   $a2, 1024     # hardcoded buffer length
    syscall      

    # Close the file 
    li   $v0, 16       # system call for close file
    move $a0, $s6      # file descriptor to close
    syscall

    la $s0, buffer   # keep address at $s0

    jr $ra  
        

atoi:
    # la $t0, str # load string address
    addi $t1, $zero, 0 # t1 = res = 0

        whileAtoi:

            lb $t2, 0($s0) # load char

            beq $t2, $zero, endAtoi # end of file
            beq $t2, 13, endAtoi # end of line
            beq $t2, ' ', endAtoi # end of word

            addi $t2, $t2, -48 # convert to char to int

            mul $t1, $t1, 10 # res *= 10
            add $t1, $t1, $t2 # res += temp

            addi $s0, $s0, 1 # go to next char
        
            j whileAtoi

        endAtoi:

    jr $ra



printArr:
    addi $t5, $zero, 0  
    addi $t6, $zero, 0
        whilePrint:
            beq $t5, $t3, endPrint

            lb $t9, arr($t6)

            li $v0, 1
            move $a0, $t9
            syscall

            li $v0, 4
            la $a0, comma
            syscall

            addi $t5, $t5, 1
            addi $t6, $t6, 4

            j whilePrint

        endPrint:

    jr $ra