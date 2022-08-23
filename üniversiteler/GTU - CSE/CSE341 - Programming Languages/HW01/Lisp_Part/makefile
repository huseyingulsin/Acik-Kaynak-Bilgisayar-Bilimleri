LISP = clisp

FILE = gpp_lexer

INPUTFILE = example_input.txt
OUTPUTFILE = example_output.txt

flex: ${FILE}.lisp
	${LISP} ${FILE}.lisp


input:
	${LISP} ${FILE}.lisp < ${INPUTFILE}

output:
	${LISP} ${FILE}.lisp < ${INPUTFILE} > ${OUTPUTFILE}
