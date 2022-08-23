/**
 * @author Muhammed Oguz (muhammedogz)
 * @create date 07-12-2021 12:56
 * @modify date 10-12-2021 01:16
 * @desc Contains interpreter information
 */


%{
	#include <stdio.h>
	#include <string.h>
    #include <stdlib.h>

    #include "yacc_helper.h"
%}

%union 
{
	char *string;
	int value;
	int values[1000];
}


%token <string> IDENTIFIER FILENAME
%token <value> VALUE
%token KW_AND KW_OR KW_NOT KW_EQUAL KW_LESS KW_NIL KW_LIST KW_APPEND KW_CONCAT KW_SET KW_DEFFUN KW_DEFVAR KW_FOR KW_IF KW_EXIT KW_LOAD
%token  KW_DISP KW_TRUE KW_FALSE OP_PLUS OP_MINUS OP_DIV OP_DBLMULT OP_MULT OP_OP OP_CP OP_OC OP_CC COMMENT CUT
%token OP_COMMA // unused because there is no rule for this


%start START

%type <value> INPUT
%type <values> LISTVALUE
%type <values> VALUES
%type <string> FUNCPARAM
%type <value> EXPI
%type <value> EXPB
%type <values> EXPLISTI

%%

START: | START INPUT {var1 = 0; var2 = 0; sum = 0;};

INPUT:
	EXPI {      printSelector(&$$, type, var2, isNil); if (isNil == 1) isNil = 0; $$ = $1; } |
	EXPLISTI {  printSelector(&$$, type, var2, 1); $$ = $<value>1;
            if(type == 3) copy($<values>$, $<values>1, var2); } |
	COMMENT { printf("Result: COMMENT\n"); };

LISTVALUE:
	OP_OP KW_LIST VALUES OP_CP  { copy($<values>$, $<values>3, var1); type = LIST; } |
	CUT OP_OP VALUES OP_CP      { copy($<values>$, $<values>3, var1); type = LIST; };

VALUES:
	VALUES VALUE{ $$[var1] = $<value>2; var1 += 1; type = LIST; } | 
	VALUE {$$[var1] = $<value>1; var1 += 1; type = LIST;};

FUNCPARAM:
	IDENTIFIER { addIdentifier($1, 0); $$ = $1; type = STRING; };

EXPI:
	OP_OP OP_PLUS EXPI EXPI OP_CP           {$$ = $3 + $4; type = INT;} |
	OP_OP OP_MINUS EXPI EXPI OP_CP          {$$ = $3 - $4; type = INT;} |
	OP_OP OP_MULT EXPI EXPI OP_CP           {$$ = $3 * $4; type = INT;} |
	OP_OP OP_DIV EXPI EXPI OP_CP            {checkZeroDivision($4); $$ = $3 / $4; type = INT; } |
	OP_OP OP_DBLMULT EXPI EXPI OP_CP        {$$ = _pow($3, $4); type = INT; } | 
    OP_OP IDENTIFIER EXPLISTI OP_CP         {$<string>$ = $<string>2; type = STRING;} |
	OP_OP IDENTIFIER EXPI OP_CP             {$$ = getIdentifierValue($2) + $3; type = INT;} |
	OP_OP KW_SET IDENTIFIER EXPI OP_CP      { addIdentifier($3, $4); $$ = $4; type = INT; } | 
	OP_OP KW_SET IDENTIFIER EXPLISTI OP_CP  { copy($<values>$, $<values>4, var2); type = LIST; } | 
    OP_OP KW_IF EXPB EXPLISTI OP_CP{
		if($3 == 1) copy($<values>$, $<values>4, var2);
		else        $$ = 0;
        type = LIST; } |
    OP_OP KW_IF EXPB EXPLISTI EXPLISTI OP_CP{
        if($3 == 1) copy($<values>$, $<values>4, var2);
        else        copy($<values>$, $<values>5, var2);
        type = LIST; } |
	OP_OP KW_IF EXPB EXPI OP_CP{
        if($3 == 1) { $$ = $4; type = INT; }
        else        { $$ = 0; type = LIST;  }      } |
	OP_OP KW_IF EXPB EXPI EXPI OP_CP{
		if($3 == 1) $$ = $4;
		else        $$ = $5;
        type = INT; } |
	OP_OP KW_FOR OP_OP IDENTIFIER EXPI EXPI OP_CP EXPLISTI OP_CP { copy($<values>$, $<values>8, var2); type = LIST; }|
	OP_OP KW_LOAD OP_OC FILENAME OP_CC OP_CP { $$ = loadFile($<string>4); type = BOOL; } |
	OP_OP KW_DEFVAR IDENTIFIER EXPI OP_CP{ addIdentifier($3, $4); $<string>$ = $3; type = STRING; } |
	OP_OP KW_DEFVAR IDENTIFIER EXPLISTI OP_CP{ $<string>$ = $<string>3; type = STRING; } |
	OP_OP KW_DEFFUN IDENTIFIER OP_OP FUNCPARAM OP_CP EXPI OP_CP { addIdentifier($3, $7); $<string>$ = $3; type =  STRING; } | 
    OP_OP KW_DEFFUN IDENTIFIER OP_OP FUNCPARAM OP_CP EXPLISTI OP_CP { addIdentifier($3, $<value>7); $<string>$ = $3;  type =  STRING; } |
	OP_OP KW_DEFFUN IDENTIFIER EXPLISTI OP_CP { addIdentifier($3, $<value>4); $<string>$ = $3;  type =  STRING; } |
	OP_OP KW_DISP EXPI OP_CP { $$ = $3; } |
	OP_OP KW_DISP EXPLISTI OP_CP { copy($<values>$, $<values>3, var2); type = LIST; } |
	OP_OP KW_EXIT OP_CP {printf("Exiting.\n"); exit(0);} |
	EXPB {$$ = $1;};

EXPB:
	OP_OP KW_AND EXPB EXPB OP_CP    {$$ = $3 && $4; type = BOOL;} |
	OP_OP KW_OR EXPB EXPB OP_CP     {$$ = $3 || $4; type = BOOL;} |
	OP_OP KW_NOT EXPB OP_CP         {if($3 == 0) $$ = 1; else $$ = 0; type = BOOL;} |
    OP_OP KW_EQUAL EXPB EXPB OP_CP  {if($3 == $4) $$ = 1; else $$ = 0; type = BOOL;} |
	OP_OP KW_LESS EXPB EXPB OP_CP   {if($3 < $4) $$ = 1; else $$ = 0; type = BOOL;} |
	VALUE {$$ = $1; type = INT;} |
    KW_TRUE {$$ = 1; type = BOOL;} |
	KW_FALSE {$$ = 0; type = BOOL;} |
	KW_NIL {$$ = 0; type = BOOL; isNil = 1;} |
	IDENTIFIER { $$ = getIdentifierValue($<string>1); type = INT; };

EXPLISTI:
	OP_OP KW_CONCAT EXPLISTI EXPLISTI OP_CP   { copy($$, concat_append($3, $4, sum, var2), sum); type = LIST; var2 = sum; } |
	OP_OP KW_APPEND EXPLISTI EXPLISTI OP_CP   { copy($$, concat_append($3, $4, sum, var2), sum); var2 = sum; type = LIST;} |
	OP_OP KW_APPEND EXPI EXPLISTI OP_CP       { appendBegining($4, var2, $3); var2 += 1; type = LIST; } |
	LISTVALUE { copy($<values>$, $<values>1, var1); var2 = var1; sum += var1; var1 = 0;  type = LIST; };

%%

int main(int argc, char *argv[])
{
    
    if (argc == 1)
    {
        printf("Type (exit) for exit\n");
        printf("Enter your input\n");
    }
    else if (argc == 2)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            printf("File not found\n");
            return 0;
        }
    }
    else 
    {
        printf("Too many arguments\n");
        printf("Usage: ./gpp_interpreter || ./gpp_interpreter <filename>");
        return 0;
    }

    yyparse();
}