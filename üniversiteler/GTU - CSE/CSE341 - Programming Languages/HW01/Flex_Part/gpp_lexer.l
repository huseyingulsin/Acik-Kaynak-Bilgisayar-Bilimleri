/**
 * @author Muhammed Oguz (muhammedogz)
 * @email muhammed0748@outlook.com
 * @create date 27-11-2021 23:37
 * @modify date 1-12-2021 23:37
 * @desc gpp interpreter lexer file
 */


/* definition seciton */
%{
    int is_op_cc = 0;
%}

COMMENT [;]{2}.*
NOTVALID [0-9]+[a-zA-Z]*
VALUE [1-9][0-9]*|[0]
IDENTIFIER  [a-zA-Z][a-zA-Z0-9]*


/* rules seciton */

%%

    /* KEYWORDS */

true    { printf("KW_TRUE\n");}
false   { printf("KW_FALSE\n");}
and     { printf("KW_AND\n");}
or      { printf("KW_OR\n");}
not     { printf("KW_NOT\n");}
equal   { printf("KW_EQUAL\n");} 
less    { printf("KW_LESS\n");}
nil     { printf("KW_NIL\n");}
list    { printf("KW_LIST\n");}
append  { printf("KW_APPEND\n");}
concat  { printf("KW_CONCAT\n");}
set     { printf("KW_SET\n");}
deffun  { printf("KW_DEFFUN\n");}
for     { printf("KW_FOR\n");}
if      { printf("KW_IF\n");}
load    { printf("KW_LOAD\n");}
disp    { printf("KW_DISP\n");}
exit    { printf("KW_EXIT\n"); return 0;}

    /* OPERATORS */

[+]       { printf("OP_PLUS\n");}
[-]       { printf("OP_MINUS\n");}
[/]       { printf("OP_DIV\n");}
[*]       { printf("OP_MULT\n");}
[(]       { printf("OP_OP\n");}
[)]       { printf("OP_CP\n");} 
[*]{2}    { printf("OP_DBLMULT\n");}
[,]       { printf("OP_COMMA\n");}
["]       { printf("OP_"); 
                if (is_op_cc == 0) { printf("OC\n"); is_op_cc = 1; }
                else               { printf("CC\n"); is_op_cc = 0; }
          } 


    /* COMMENT VALUE IDENTIFER */

{COMMENT} {printf ("COMMENT\n");}
{VALUE} { printf("VALUE\n");}
{NOTVALID} {printf ("Not Valid value or identifer. %s\n", yytext);}
{IDENTIFIER} {printf("IDENTIFIER\n");}

    /* space tabs newline */

[ \t\n]  {;} // ignore spaces, tabs and newlines

    /* Other syntax gives erros */

. { printf("SYNTAX ERROR: '%s' cannot be tokenized\n",yytext);} 

    /* EOF */

[\n]{2}      { printf("Lexer Completed Succesfully. Exiting...\n"); return 0;}

%%

int yywrap() {}

int main(int argc , char** argv)
{
    if (argc == 1)
    {
        printf("Type exit or two enters to exit\n");
        printf("Enter your string:");
    }
    else if (argc == 2)
    {
        FILE *fp;
        fp = fopen(argv[1], "r");
        yyin = fp;
    }
    else 
    {
        printf("Too many arguments\n");
        return 0;
    }

    yylex();
    return 0;
}