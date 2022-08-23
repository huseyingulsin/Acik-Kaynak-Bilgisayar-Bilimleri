.data  
fin: .asciiz "file.txt" # filename
fout: .asciiz "out.txt"

buffer: .space 1024     # buffer - it will keep file content from readed file
buffer_write: .space 1024 # buffer - it will keep file content for writing

arr: .word 0:16         # every array assumed 16 size
longestArr: .word 0:16  # longestArr to hold longest sequence
tempArr: .word 0:16

whitespace: .asciiz " " 
newline: .asciiz "\n"
new_line: .byte '\n'
empty_space: .asciiz " "

readed_arr: .asciiz "readed arr from file -> ["
result_arr: .asciiz "]\nresult arr -> ["
new_lne_close: .asciiz "]\n"


.text

main:
    # call file reader func
    # keep all content in s0
    jal openFileAndRead

    addi $s4, $zero, 0 # keep this for buffer_write poistion
    
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

            li $v0, 4
            la $a0, readed_arr
            syscall 

            jal printArr 

            li $v0, 4
            la $a0, result_arr
            syscall 

            # call calculation formula here
            jal calcSequence

            # call fill_buffer function to fill buffer
            jal fill_buffer

            li $v0, 4
            la $a0, new_lne_close
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

    # write to file
    jal writeToFile


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
            la $a0, whitespace
            syscall

            addi $t5, $t5, 1
            addi $t6, $t6, 4

            j whilePrint

        endPrint:

    jr $ra

calcSequence:
    # i
    addi $t0, $zero, 0 # make sure t0 is zero
    # j
    addi $t1, $zero, 0 # make sure t1 is zero


    # it will track array with incrementing 4 for int
    addi $t8, $zero, 0 # make sure t1 is zero
    # it will track longestArr incrementing 4 for int
    addi $t9, $zero, 0 # make sure t2 is zero

    move $s6, $t3 # load size
    
    # it will track longestSeq size
    addi $s7, $zero, 0 # make sure s7 is zero 
    

    whileLoop:
        beq $t0, $s6, endLoop # for (int i = 0; i < size (t2); i++)

        lw $t5, arr($t8) # load arr[i]

        # load new variable to one,
        # it will keep track of the temp arr index
        # start from 1, because, I will assign first value manually
        addi $t2, $zero, 1 # tempArr index

        # it will keep assigments locations for TempArr
        addi $t4, $zero, 0

        # assign tempArr[0] = arr[0]
        sw $t5, tempArr($t4) # store arr[0] to tempArr[0]
        addi $t4, $t4, 4 # increment t9 for next int

        addi $t7, $t5, 0 # int temp = arr[i]
        
            # inner for loop
            addi $t1, $t0, 0 # j = i
            # itereate in inner lop for arr
            addi $t9, $zero, 0 # tempArr increemnter


            while2:
                beq $t1, $s6, end2 # for (int j = i; j < size (t2); j++)

                lw $t6, arr($t9) # load arr[j]
                
                # if arr[j] is bigger than temp
                # and increment tempArrIndex
                # else, do nothing
                bgt $t6, $t7, assign # arr[j] > temp
                    
                addi $t9, $t9, 4 # increment t9 for next int
                addi $t1, $t1, 1 # j++
                j while2

                assign:
                    sw $t6, tempArr($t4) #  tempArr[tempArrIndex] = arr[j]
                    move $t7, $t6 # temp = arr[j]

                    addi $t4, $t4, 4 # go to next index address
                    addi $t2, $t2, 1 # increment tempArrIndex

                addi $t9, $t9, 4 # increment t9 for next int
                addi $t1, $t1, 1 # j++
                j while2
            end2:

        

        # print temp arr
        # if
        bgt $t2, $s7, tempToLongest # if tempArr size is bigger than longest arr, copy tempArr to longestArr

        addi $t0, $t0, 1 # i++
        addi $t8, $t8, 4 # increment int value to print arr
        j whileLoop

        # if
        tempToLongest:
            move $s7, $t2 # longestArr = tempArr
            addi $t2, $zero, 0 # tempArrSize = 0
            addi $t9, $zero, 0 # initialize t9 to keep memories
            whileCopy:
                beq $t2, $s7, endCopy # if tempArrIndex == longestArrIndex
                lw $t5, tempArr($t9) # load tempArr[tempArrIndex]
                sw $t5, longestArr($t9) # longestArr[longestArrIndex] = tempArr[tempArrIndex]
                
                addi $t2, $t2, 1 # increment tempArrIndex
                addi $t9, $t9, 4 # increment t9 for next int

                j whileCopy

            endCopy:


        addi $t0, $t0, 1 # i++
        addi $t8, $t8, 4 # increment int value to print arr
        j whileLoop
    endLoop:

    # print longestArr
    addi $t8, $zero, 0 # make sure t8 is zero
    addi $t9, $zero, 0 # make sure t9 is zero

    whilePrintLoop:
        beq $t8, $s7, endPrintLoop # for (int i = 0; i < size (t2); i++)

        lw $t5, longestArr($t9) # load arr[i]

        li $v0, 1 # for printing int
        move $a0, $t5 # load arr
        syscall

        li $v0, 4 # for printing string
        la $a0, whitespace #print space
        syscall

        addi $t8, $t8, 1 # increment t9 for next int
        addi $t9, $t9, 4 # increment t9 for next int

        j whilePrintLoop

    endPrintLoop:

    jr $ra

fill_buffer:
    lb $s5, empty_space
    move $s6, $s7 # keep size
    addi $t7, $zero, 10 # keep this for division

    addi $t0, $zero, 0 # i = 0;
    addi $t1, $zero, 0 # address keeper

    whileWrite:
        beq $t0, $s6, endWhileWrite # if i == size, break

        lw $t2, longestArr($t1) # t2 = arr[i]
  
        div $t2, $t7 # t2 = t2 / 10
        mflo $t2 # t2 = t2 / 10
        mfhi $t3 # t3 = t2 % 10

        bgt $t2, 10, oneStep # if t2 > 10, go to oneStep

        addi $t2, $t2, 48 # t2 = t2 + 48 (ascii)
        addi $t3, $t3, 48 # t3 = t3 + 48 (ascii)

        sb $t2, buffer_write($s4) # buffer[i] = t2
        addi $s4, $s4, 1 # increment buffer position
        sb $t3, buffer_write($s4) # buffer[i] = t3
        addi $s4, $s4, 1 # increment buffer position
        sb $s5, buffer_write($s4) # buffer[i] = ' 
        addi $s4, $s4, 1 # increment buffer position

        addi $t0, $t0, 1 # i++
        addi $t1, $t1, 4 # address keeper += 4
        
        j whileWrite # goto whileWrite

        oneStep:
            div $t2, $t7 # t2 = t2 / 10
            mflo $t2 # t2 = t2 / 10
            mfhi $t4 # t3 = t2 % 10

            addi $t2, $t2, 48 # t2 = t2 + 48 (ascii)
            addi $t4, $t4, 48 # t3 = t3 + 48 (ascii)
            addi $t3, $t3, 48 # t3 = t3 + 48 (ascii)

            sb $t2, buffer_write($s4) # buffer[i] = t2
            addi $s4, $s4, 1 # increment buffer position
            sb $t4, buffer_write($s4) # buffer[i] = t4
            addi $s4, $s4, 1 # increment buffer position
            sb $t3, buffer_write($s4) # buffer[i] = t3
            addi $s4, $s4, 1 # increment buffer position
            sb $s5, buffer_write($s4) # buffer[i] = ' 
            addi $s4, $s4, 1 # increment buffer position

            addi $t0, $t0, 1 # i++
            addi $t1, $t1, 4 # address keeper += 4
            
            j whileWrite # goto whileWrite

    endWhileWrite:
    lb $s3, new_line
    sb $s3, buffer_write($s4) # buffer[i] = '\n'
    addi $s4, $s4, 1 # increment buffer position

    jr $ra


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
    la $a1, buffer_write      # address of buffer from which to write
    li   $a2, 1024        # hardcoded buffer length
    syscall            # write to file

    # Close the file 
    li   $v0, 16       # system call for close file
    move $a0, $s6      # file descriptor to close
    syscall            # close file

    jr $ra