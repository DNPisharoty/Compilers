
%{
#include "symtab.h"
#include "token_dnp6ga.h"
%}

%%

\/\/.*          ;
[[:space:]]     ;
,               ;
'               ;
\"              ;


GO              return CGO;
TURN            return CTURN; 
JUMP            return CJUMP;
FOR             return FORLOOP;
STEP            return STEPLOOP;
TO              return TO;
DO              return DO;
BEGIN           return OPEN;
END             return CLOSE;
INT 		return INT;
FLOAT		return FLOAT;
VAR 		return VAR;
CHAR		return CHAR;
DOUBLE		return DOUBLE;

sin             return SINFUNC;
cos             return COSFUNC;
sqrt            return SQRT;
pow 		return POWER;

;               return SEMICOLON;
\+              return PLUS;
-               return MINUS;
\*              return MULT;
\%              return MOD;
\/              return DIV;
\(              return OPENP;
\)              return CLOSEP;
\{              return OPENB;
\}              return CLOSEB;
=               return ASSIGN;
IF		return IF;
ELSE		return ELSE;
THEN		return THEN;
WHILE           return WHILE;
PROCEDURE       return PROC;
SWITCH          return SWITCH;
CASE            return CASE;

[0-9]+\.[0-9]+  yylval.d = atof(yytext);  return FLOATN;
[0-9]+  yylval.i = atoi(yytext);  return INTEGER;


[a-z][a-zA-Z0-9_]*       { yylval.n = lookup(yytext);
                          if (yylval.n==NULL)
                            yylval.n = insert(yytext);
                          return ID;
                }

[0-9A-Z_]+[a-zA-Z_0-9]*    fprintf(stderr,"\nIllegal Indentifier: %s\n",yytext);
        
.               fprintf(stderr,"Unexpected character %c (%2X)\n",yytext[0],yytext[0]);

%%
main(){

   int token;
   while((token = yylex()) != 0){

       switch(token){

             case ID : printf("Identifier:    %s\n",yytext); break;
             case FLOATN: printf("Float number: %s\n",yytext); break;
             case INTEGER: printf("Integer number: %s\n",yytext); break;
             case OPENP: printf("Open parentheses: %s\n",yytext);break;
	     case CLOSEP: printf("Closed parentheses: %s\n",yytext);break;
	     case OPENB: printf("Open brackets: %s\n",yytext);break;
	     case CLOSEB: printf("Closed brackets: %s\n",yytext);break;
	     case PLUS: printf("Plus operator: %s\n",yytext);break;
	     case MINUS: printf("Minus operator: %s\n",yytext);break;
	     case DIV: printf("Division operator: %s\n",yytext);break;
	     case MULT: printf("Multiplication operator: %s\n",yytext);break;
	     case MOD: printf("Modulus operator: %s\n",yytext);break;
             case ASSIGN: printf("Assignment operator: %s\n",yytext);break;
	     case SINFUNC: printf("Sin function: %s\n",yytext);break;
	     case COSFUNC: printf("Cos function: %s\n",yytext);break;
	     case SQRT: printf("Square root function: %s\n",yytext);break;
	     case POWER: printf("Power function: %s\n",yytext);break;
	     case PROC: printf("Procedure keyword: %s\n",yytext);break;
	     case IF: printf("IF keyword: %s\n",yytext); break;
	     case ELSE: printf("ELSE keyword: %s\n",yytext); break;
	     case THEN: printf("THEN keyword: %s\n",yytext); break;
	     case WHILE: printf("WHILE keyword: %s\n",yytext); break;
	     case FORLOOP: printf("FOR keyword: %s\n",yytext); break;
             case TO: printf("TO keyword: %s\n",yytext); break;
	     case DO: printf("DO keyword: %s\n",yytext); break;
	     case CGO: printf("GO keyword: %s\n",yytext); break;
	     case STEPLOOP: printf("STEP keyword: %s\n",yytext); break;
	     case OPEN: printf("BEGIN keyword: %s\n",yytext); break;
	     case CLOSE: printf("END keyword: %s\n",yytext); break;
	     case CTURN: printf("TURN keyword: %s\n",yytext); break;
	     case CJUMP: printf("JUMP keyword: %s\n",yytext); break;
	     case INT: printf("INT keyword: %s\n",yytext); break;
	     case FLOAT: printf("FLOAT keyword: %s\n",yytext); break;
	     case CHAR: printf("CHAR keyword: %s\n",yytext); break;
	     case DOUBLE: printf("DOUBLE keyword: %s\n",yytext); break;
	     case VAR: printf("VAR keyword: %s\n",yytext); break;
             case SEMICOLON: printf("Semicolon: %s\n",yytext);break;
             case SWITCH: printf("SWITCH keyword %s\n",yytext);break;
             case CASE: printf("CASE keyword: %s\n",yytext);break;
             default:
                        printf("Illegal Character\n"); break;




         }

}
}
