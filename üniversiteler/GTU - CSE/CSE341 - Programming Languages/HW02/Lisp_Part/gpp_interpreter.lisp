;;  @author Muhammed Oguz (muhammedogz)
;;  @email muhammed0748@outlook.com
;;  @create date 7-12-2021 14:42
;;  @modify date 12-12-2021 21:22
;;  @desc gpp interpreter some tokens are missing unfortunatelly :(

(load "gpp_lexer.lisp")

; keep value num to determine right value
(defvar valNum 0)
; keep id num to determine right id
(defvar idNum 0)

(defun gppinterpreter ()
    "Call splitLine func in a while loop"
    (format t "Welcome to perfect lisp interpreter. Type (exit) to exit from program ~%")
    (loop 

        ; if you are using terminal to enter inputs. You can uncommnet this line
        ; (format t "> ") ; prints this before taking input

        (determineTokenType)

        ; if newlineCount == 2 break the loop condition
        (if (= newLineCount 2)
            (progn
                (setq exitValue 1)
            )
        )

        (start tokenType)


        (if (equal exitValue 1) ; if exitValue is 1, terminate the program
            (progn
                (setq exitValue 0)
                (format t "Exiting from interpreter! Have a good day. ~%")
                (return)
            )
        )

        ; reset those values for every iteration
        (setq tokenType (list))
        (setq valueList (list))
        (setq identifierListTemp (list))
        (setq valNum 0)
        (setq idNum 0)
    )
)

; Use top down parser to parse the input
(defun start (tokenType)
    (setf isCheck (check tokenType))

    (if (equal isCheck nil)
        (progn
            (printLn "Syntax Error!")
            (setq exitValue 1)
        )
        (progn
            (printLn "Syntax OK!")
            (format t "Result: ~a ~%" isCheck)
        )
    )
)

(defun check (tokenType)
    (setf checkValue nil)
    (if (equal (length tokenType) 1)
        (progn
            (if (string= (nth 0 tokenType) "VALUE")
                (progn
                    (setf checkValue (nth valNum valueList))
                    (setq valNum (+ valNum 1))
                )
            )
            (if (string= (nth 0 tokenType) "IDENTIFIER")
                (setf checkValue (searchIdentifier tokenType))
            )

            ; check if nil
            (if (string= (nth 0 tokenType) "KW_NIL")
                (setf checkValue "nil")
            )

            ; check KW_FALSE
            (if (string= (nth 0 tokenType) "KW_FALSE")
                (setf checkValue "false")
            )

            ; check KW_TRUE	
            (if (string= (nth 0 tokenType) "KW_TRUE")
                (setf checkValue "true")
            )

            ; check COMMENT
            (if (string= (nth 0 tokenType) "COMMENT")
                (setf checkValue "comment")
            )

        )
    )
    (if (equal (length tokenType) 3)
        (progn
            (if (and (string= (nth 0 tokenType) "OP_OP") (string= (nth 2 tokenType) "OP_CP"))
            
                (progn
                    ; check if KW_EXIT
                    (if (string= (nth 1 tokenType) "KW_EXIT")
                        (progn
                            (setf checkValue "exit")
                            (setq exitValue 1)
                        )
                    )
                )

            )
        )
    )
    (if (equal (length tokenType) 4)
        (progn
            (if (and (string= (nth 0 tokenType) "OP_OP") (string= (nth 3 tokenType) "OP_CP"))
                (progn

                    ; OP_OP KW_NOT VALUE OP_CP
                    (if (string= (nth 1 tokenType) "KW_NOT")
                        (setf checkValue (opNOT tokenType))
                    )
                )

            )
        )
    )
    (if (equal (length tokenType) 5)
        (progn 
            (if (and (string= (nth 0 tokenType) "OP_OP") (string= (nth 4 tokenType) "OP_CP"))
                (progn
                    ; look for + operation
                    (if (string= (nth 1 tokenType) "OP_PLUS")
                        (setf checkValue (opPLUS tokenType))
                    )

                    ; look for - operation	
                    (if (string= (nth 1 tokenType) "OP_MINUS")
                        (setf checkValue (opMINUS tokenType))
                    )

                    ; look for * operation
                    (if (string= (nth 1 tokenType) "OP_MULT")
                        (setf checkValue (opMULT tokenType))
                    )

                    ; look for / operation
                    (if (string= (nth 1 tokenType) "OP_DIV")
                        (setf checkValue (opDIV tokenType))
                    )

                    ; OP_OP KW_SET IDENTIFIER EXPI OP_CP
                    (if (string= (nth 1 tokenType) "KW_SET")
                        (setf checkValue (opSET tokenType))
                    )

                    ; OP_OP KW_EQUAL EXPI EXPI OP_CP
                    (if (string= (nth 1 tokenType) "KW_EQUAL")
                        (setf checkValue (opEQUAL tokenType))
                    )

                    ; OP_OP KW_LESS EXPI EXPI OP_CP	
                    (if (string= (nth 1 tokenType) "KW_LESS")
                        (setf checkValue (opLESS tokenType))
                    )
                )
                    
            )
        )
    )
    (if (equal (length tokenType) 6)
        (progn
            (if (and (string= (nth 0 tokenType) "OP_OP") (string= (nth 5 tokenType) "OP_CP"))
                (progn

                    ; look for ** operation
                    (if (and (string= (nth 1 tokenType) "OP_MULT") (string= (nth 2 tokenType) "OP_MULT"))
                        (setf checkValue (opDBLMULT tokenType))
                    )

                )
            )
        )
    )
    ; return
    checkValue
)


(defun opPLUS (tokenType)
    (setf val1 (check (list (nth 2 tokenType))))
    (setf val2 (check (list (nth 3 tokenType))))
    (+ val1 val2)
)

(defun opMINUS (tokenType)
    (setf val1 (check (list (nth 2 tokenType))))
    (setf val2 (check (list (nth 3 tokenType))))
    (- val1 val2)
)

(defun opMULT (tokenType)
    (setf val1 (check (list (nth 2 tokenType))))
    (setf val2 (check (list (nth 3 tokenType))))
    (* val1 val2)
)

(defun opDIV (tokenType)
    (setf val1 (check (list (nth 2 tokenType))))
    (setf val2 (check (list (nth 3 tokenType))))

    (if (equal val2 0)
        (progn
            (printLn "Division by zero error!")
            (setq exitValue 1)
        )
        (/ val1 val2)
    )
)

(defun opDBLMULT (tokenType)
    (setf val1 (check (list (nth 3 tokenType))))
    (setf val2 (check (list (nth 4 tokenType))))
    (expt val1 val2)
)

(defun opSET (tokenType)
    
    (setf val (check (list (nth 3 tokenType))))
    (setq identifierList (addToListTail (nth 0 identifierListTemp) identifierList))
    (setq identifierValueList (addToListTail val identifierValueList))

    (nth 0 valueList)
)

(defun opEQUAL (tokenType)
    (setf val1 (check (list (nth 2 tokenType))))
    (setf val2 (check (list (nth 3 tokenType))))

    (if (equal val1 val2)
        "TRUE"
        "FALSE"
    )
)

(defun opLESS (tokenType)
    (setf val1 (check (list (nth 2 tokenType))))
    (setf val2 (check (list (nth 3 tokenType))))

    (if (< val1 val2)
        "TRUE"
        "FALSE"
    )
)

(defun opNOT (tokenType)
    (setf val (check (list (nth 2 tokenType))))
    
    (if (string= val "KW_TRUE")
        "FALSE"
        "TRUE"
    )
    (if (equal val "KW_FALSE")
        "TRUE"
        "FALSE"
    )
)

(defun searchIdentifier (tokenType)
    (setf searchID (nth idNum identifierListTemp))
    (setq idNum (+ idNum 1))
    (setf searchIndex (searchList searchID identifierList))
    (if (equal searchIndex nil)
        (progn
            (format t "Identifier not found! ~%")
            nil    
        )
        (progn
            (nth searchIndex identifierValueList)
        )
    )
)

(gppinterpreter)