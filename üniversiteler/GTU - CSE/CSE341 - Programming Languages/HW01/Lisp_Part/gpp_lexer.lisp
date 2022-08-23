(setq KeyWordList (list "and" "or" "not" "equal" "less" "nil" "list" "append" "concat" "set" "deffun" "for" "if" "exit" "load" "disp" "true" "false"))
(setq KW (list "KW_AND" "KW_OR" "KW_NOT" "KW_EQUAL" "KW_LESS" "KW_NIL" "KW_LIST" "KW_APPEND" "KW_CONCAT" "KW_SET" "KW_DEFFUN" "KW_FOR" "KW_IF" "KW_EXIT" "KW_LOAD" "KW_DISP" "KW_TRUE" "KW_FALSE"))
(setq OperatorList (list "+" "-" "/" "**" "*" "(" ")" "\"" "\"" ","))
(setq OP (list "OP_PLUS" "OP_MINUS" "OP_DIV" "OP_DBLMULT" "OP_MULT" "OP_OP" "OP_CP" "OP_OC" "OP_CC" "OP_COMMA"))

(setq Space (list "\n" "\t" " "))
(setq Comment ";")
(setq PossibleOperatorList (list "(" ")" "\""))
(setq isOC 0)

(defvar exitValue 0)
(defvar isFinish 0)

(defun gppinterpreter ()
    "Call splitLine func in a while loop"
    (format t "Welcome to perfect lisp parser. Type (exit) to exit from program ~%")
    (loop 

        ; if you are using terminal to enter inputs. You can uncommnet this line
        ; (format t "> ") ; prints this before taking input


        (splitLine (read-line)) ; reads input and calls splitLine func
        
        (if (equal exitValue 1) ; if exitValue is 1, terminate the program
            (progn
                (setq exitValue 0)
                (format t "Exiting from parser! Have a good day. ~%")
                (return)
            )
        )
    )

)

(defun splitLine (line)
    "Take line input and divide it into words list"
	(let ((words (list)))
        ; remove newline tab space from given line
		(setq line (string-trim '(#\Space #\Tab #\Newline) line))
		(setq words (strSplit line))
		(loop for word in words
			do
                ; remove empty spaces from word
                (setq word (string-trim '(#\Space #\Tab #\Newline) word))

                (if (string= word "(exit)")
                    (progn
                        (setq exitValue 1)
                        (return)
                    )
                )

                ; when a comment line entered, do not check other inputs
                (if (equal (splitWord word) 2)
                    (return)
                )
		)		
	)
)

(defun splitWord (word)
    "Exemine each word and check which token type it is"
	(let ((len (length word)) (subWord) (j 0) (res) (temp) (id 0))
        (setq isFinish 0)
		(loop for i from 1 to len
			do

            (if (= isFinish 1) (setq isFinish 0) )
            (setq subWord (string-downcase (subseq word j i)))

            
            ; Check if subWord is a operator
            (if (and (equal isFinish 0) (not (equal (isOperator subWord) nil)) )
                (progn
                    (setq j i) 
                    (setq isFinish 1)
                )
            )	

            ; Check if subWord is a KeyWordList
            (setq isKeyWordValue (isKeyWord word subWord i len))
            (if (and (equal isFinish 0) (not (equal isKeyWordValue nil)) )
                (progn 
                    (if (equal isKeyWordValue 1)
                        (setq j i)
                    )
                    (setq isFinish 1)
                )
            )

            ; Check if subWord is a value
            (setq isValueNum (isValue word subWord i j len))
            (if (and (equal isFinish 0) (not (equal isValueNum nil)) )
                (progn 
                    (setq i isValueNum)
                    (setq j i)
                    (setq isFinish 1)
                )
            )

            ; check if subWord is a comment
            ; first and second letters are: ;
            (if (and (equal isFinish 0) (>= len 2) (string= (subseq word 0 1) Comment)) 
                (if (string= (subseq word 1 2) Comment)
                    (progn  (format t "COMMENT~%")  (setq isFinish 2))
                )
            )

            ; check of if given token is identifier or not
            ; also checks given token is valid or not
            (if (equal isFinish 0)
                (progn
                    (setq isIdentifierValue (isIdentifier word subWord i j len))
                    (if (not (equal isIdentifierValue nil)) 
                        (progn 
                            (if (equal isIdentifierValue 1)
                                (setq j i)  
                            )
                            (setq isFinish 1)
                        )
                    )
                )   
            )

            

            (if (or (= isFinish -1) (= isFinish 2)) (return isFinish))

		)

		isFinish			
	)
)

(defun isOperator (word)
    "Check if the given token is operator or not"
    (setq res (searchList word OperatorList))
    (if (not (equal res nil))
        (progn
            ; check subWord is " . 
            ; If it is, then increment isOC value for close or open
            (if (equal res 7) 
                (progn (setq res (+ res (mod isOC 2))) (setq isOC (+ isOC 1)))
            )
            (format t "~a ~%" (nth res OP))
        )
    )
    res
)

(defun isKeyWord (word subWord i len)
    "Check is the given token is Keyword or not"
    (setq returnValue nil)
    (setq res (searchList subWord KeyWordList))
    (if (not (equal res nil))
        (if (>= i len)
            (progn
                (format t "~a ~%" (nth res KW))
                (setq returnValue 0)
            )
            ; else
            (progn
                (setq temp (subseq word i (+ i 1)))
                (if (equal (searchList temp PossibleOperatorList) nil)
                    (if (equal (isIdentifierHelper (concatenate 'string subWord temp)) nil) 
                        (progn
                            (format t "ERROR ~S can not be tokenized.~%" (subseq subWord j len))
                            (setq isFinish -1)
                        )
                    )
                    (progn
                        (format t "~a ~%" (nth res KW))
                        (setq returnValue 1)
                     
                    )

                )
            )
        )
    )
    returnValue
)
    
(defun isValue (word subWord i j len)
    "Check if the given token is value or not"
    (setq returnValue nil)
    (setq res (isValueHelper subWord))
    (if (not (equal res nil))
        (progn
            (loop
                (setq i (+ i 1))
                (when (or (equal (isValueHelper (subseq word j (- i 1))) nil) (> i len)) 
                    (return))
            )
            (setq i (- i 1))
            (if (equal (isValueHelper (subseq word j i)) nil) 
                (progn
                    (setq i (- i 1))
                    (if (equal (searchList (subseq word i (+ i 1)) PossibleOperatorList) nil)
                        (progn
                            (format t "ERROR2 ~S can not be tokenized.~%" (subseq word j len))
                            (setq isFinish -1)
                        )
                        (format t "VALUE~%")
                    )
                )
                (format t "VALUE~%")
            )	
            (setq returnValue i)							     
        )	
    )
    returnValue
)

(defun isValueHelper (word)
    "Helps the isValue function. Checks if the given word has a digit or not"
	(let ((letter "") (res t))
		(if (equal (every #'digit-char-p word) nil)
			(setq res nil) ; if there is a word that is not a digit
			(setq res t) ; if every word is a digit
		)
		res	
	)
)

(defun isIdentifier (word subWord i j len)
    "Check if the given token is identifier or not or a invalid token"
    (setq returnValue nil)
    (setq res (isIdentifierHelper subWord))
    (if (and (equal isFinish 0) (equal res t) )
        (if (= i len)
            (progn 
                (format t "IDENTIFIER~%")
                (setq returnValue 0)
            )
            (progn
                (setq temp(subseq word j (+ i 1)))
                (setq id (isIdentifierHelper temp))
                (if (not (equal res id))
                    (progn
                        (setq temp (subseq word i (+ i 1)))
                        (if (equal (searchList temp PossibleOperatorList) nil)
                            (progn 
                                (setq isFinish -1) 
                                (format t "ERROR ~S can not be tokenized. ~%" (subseq word j len))
                            )
                            (progn 
                                (format t "IDENTIFIER~%")
                                (setq returnValue 1) 
                            )
                        )
                    )
                )
            )
        )
        (progn
            (format t "ERROR ~S can not be tokenized.~%" (subseq word j len))
            (setq isFinish -1)
        )
    )
    returnValue
)

(defun isIdentifierHelper (word)
    "Helps the isIdentifier func. Checks the given input has correct identifier types or not"
	(let ((len (- (length word) 1)) (letter "") (res t))

		(loop for i from 0 to len
			do
			(progn
				(setq letter (char word i))
				(if (= i 0)
					(if (or (alpha-char-p letter) (char= letter #\_)) 
                        (setq res t) 
                        (setq res nil)
                    )
					(if (or (alpha-char-p letter) (digit-char-p letter) (char= letter #\_)) 
                        (setq res t) 
                        (setq res nil)
                    )
				)
				(if (equal res nil) (return res))
			)
		)
		res
	)
)

; splits given stirng to words that represented as a list
(defun strSplit (str)
    "Splits given string"
  (strSplitHelper str))

; this is predefined function
; I took some help from stackoverflow.
(defun strSplitHelper (str &optional (r nil))
    "Splits given string with recursively and returns a list"
  (let ((n (position " " str
		     :from-end t
		     :test #'
             (lambda (x y) (find y x :test #'string=)) )))
    (if n
	(strSplitHelper (subseq str 0 n) (cons (subseq str (1+ n)) r))
      (cons str r)))
)

; search in the given list recursively
(defun searchList (word listCheck &optional (i 0))
    "Searchs in the given list recursively"
	(if (null listCheck)
		nil
		(if (string= word (car listCheck))
			i
			(searchList word (cdr listCheck) (+ i 1))
		)
	)
)

; call the desired function
(gppinterpreter)
