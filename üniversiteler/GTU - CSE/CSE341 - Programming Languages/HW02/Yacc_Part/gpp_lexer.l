/**
 * @author Muhammed Oguz (muhammedogz)
 * @create date 08-12-2021 12:56
 * @modify date 10-12-2021 01:16
 * @desc Contains lexer information
 */


/* uncomment this opiton if you compile your interpreter without -ll flag */
/* %option noyywrap */

%{

    #include <stdio.h>
    #include <stdlib.h>

    #include "gpp_interpreter.h" // interpreter generates this file

    int is_op_cc = 0;  // keep track open or close parenthesis

%}

/* rules for comment value and identifier */

COMMENT     [;]{2}.*
VALUE       [1-9][0-9]*|[0]
IDENTIFIER  [a-zA-Z][a-zA-Z0-9]*
FILENAME    [a-zA-Z0-9_.+]+


%%
    /* KEYWORDS */

true      { return KW_TRUE;     }
false     { return KW_FALSE;    }
and       { return KW_AND;      }
or        { return KW_OR;       }
not       { return KW_NOT;      }
equal     { return KW_EQUAL;    }
less      { return KW_LESS;     }
nil       { return KW_NIL;      }
list      { return KW_LIST;     }
append    { return KW_APPEND;   }
concat    { return KW_CONCAT;   }
set       { return KW_SET;      }
deffun    { return KW_DEFFUN;   }
for       { return KW_FOR;      }
if        { return KW_IF;       }
load      { return KW_LOAD;     }
disp      { return KW_DISP;     }
exit      { return KW_EXIT;     }

    /* OPERATORS */

[+]       { return OP_PLUS;     }
[-]       { return OP_MINUS;    }
[/]       { return OP_DIV;      }
[*]       { return OP_MULT;     }
[(]       { return OP_OP;       }
[)]       { return OP_CP;       }
[*]{2}    { return OP_DBLMULT;  }
[']		  { return CUT;         }
[,]       { return OP_COMMA;    }
["]       {
                if (is_op_cc == 0) { is_op_cc = 1; return OP_OC; }
                else               { is_op_cc = 0; return OP_CC; }
          }

    /* VALUE - COMMENT - IDENTIFIER */
    
{COMMENT}       { return COMMENT; }
{IDENTIFIER}    { yylval.string = strdup(yytext); return IDENTIFIER; }
{VALUE}         { yylval.value = atoi(yytext); return VALUE; }
{FILENAME}      { yylval.string = strdup(yytext); return FILENAME; }

    /* space tabs newline */

[ \t\n]  {;} // ignore spaces, tabs and newlines
.       { 
            printf("Syntax Error\n");
            exit(1);
        }

%%
