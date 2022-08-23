LISP = clisp

FILE = gpp_interpreter

INPUTFILE = helloworld.g++
OUTPUTFILE = helloworldOutput.txt

flex: ${FILE}.lisp
	${LISP} ${FILE}.lisp


input:
	${LISP} ${FILE}.lisp < ${INPUTFILE}

output:
	${LISP} ${FILE}.lisp < ${INPUTFILE} > ${OUTPUTFILE}
