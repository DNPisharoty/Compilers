
%{
#include "symtab.h"
#include "turtle.tab.h"
%}

%%

\/\/.*          ;
[[:space:]]     ;
'               ;
\"              ;
,               ;              
\\n              ;

GO              return GO;
TURN            return TURN; 
JUMP            return JUMP;
FOR             return FOR;
STEP            return STEP;
TO              return TO;
DO              return DO;
BEGIN           return COPEN;
END             return CCLOSE;
VAR 		return VAR;

sin             return SIN;
cos             return COS;
sqrt            return SQRT;


;               return SEMICOLON;
\+              return PLUS;
-               return MINUS;
\*              return TIMES;
\/              return DIV;
\(              return OPEN;
\)              return CLOSE;
\{              return OPENB;
\}              return CLOSEB;
==              return COMPARE;
\<               return LESSTHAN;
\>               return GREATTHAN;
\=               return ASSIGN;
\!              return NOT;
IF		return IF;
ELSE		return ELSE;
THEN		return THEN;
WHILE           return WHILE;
PROCEDURE       return PROC;
CALL            return CALL;
PARAM           return PARAM;

[0-9]+\.[0-9]+  yylval.d = atof(yytext);  return FLOAT;
[0-9]+  yylval.i = atoi(yytext);  return NUMBER;


[a-z][a-zA-Z0-9_]*       { yylval.n = lookup(yytext);
                          if (yylval.n==NULL)
                            yylval.n = insert(yytext);
                          return ID;
                }

[0-9A-Z_]+[a-zA-Z_0-9]*    fprintf(stderr,"\nIllegal Indentifier: %s\n",yytext);
        
.               fprintf(stderr,"Unexpected character %c (%2X)\n",yytext[0],yytext[0]);

