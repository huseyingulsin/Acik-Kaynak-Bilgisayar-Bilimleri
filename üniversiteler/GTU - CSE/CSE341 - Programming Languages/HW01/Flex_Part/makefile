FLEX = flex
COMPILER = gcc

FILE = gpp_lexer

INPUTFILE = example_input.txt
OUTPUTFILE = example_output.txt

flex: ${FILE}.l
	${FLEX} -o ${FILE}.c $(FILE).l
	${COMPILER} ${FILE}.c -o ${FILE}
	./${FILE}

input:
	./${FILE} ${INPUTFILE}

output:
	./${FILE} ${INPUTFILE} > ${OUTPUTFILE}
