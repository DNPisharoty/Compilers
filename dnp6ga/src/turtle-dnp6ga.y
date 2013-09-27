
%{
#include <stdio.h>
#include "symtab.h"
%}

%union { int i; node *n; double d;}

%token GO TURN VAR JUMP
%token FOR STEP TO DO
%token IF THEN ELSE WHILE PROC
%token COPEN CCLOSE
%token SIN COS SQRT
%token <d> FLOAT
%token <n> ID               
%token <i> NUMBER       
%token  SEMICOLON PLUS MINUS TIMES DIV OPEN CLOSE ASSIGN 
%token COMPARE LESSTHAN GREATTHAN NOT 
%token  OPENB CLOSEB  PARAM
%token CALL
%type <n> decl
%type <n> decllist
%type <n> relation
%%
program: head decllist stmtlist tail;

head: { printf("%%!PS Adobe\n"
               "\n"
	       "newpath 0 0 moveto\n"
	       );
      };

tail: { printf("closepath \n stroke\n"); };

decllist: ;
decllist: decllist decl;

decl: VAR ID SEMICOLON { printf("/tlt%s 0 def\n",$2->symbol);} ;


stmtlist: ;
stmtlist: stmtlist stmt ;

stmt: ID ASSIGN expr SEMICOLON {printf("/tlt%s exch store\n",$1->symbol);} ;
stmt: GO expr SEMICOLON {printf("0 rlineto\n");};
stmt: JUMP expr SEMICOLON {printf("0 rmoveto\n");};
stmt: TURN expr SEMICOLON {printf("rotate\n");};

stmt: FOR ID ASSIGN expr 
          STEP expr
	  TO expr
	  DO {printf("{ /tlt%s exch store\n",$2->symbol);} 
	     stmt {printf("} for\n");};


stmt: IF OPEN  relation  CLOSE thenstmt
      OPENB { printf("{ \n") ; }
         stmtlist
      CLOSEB { printf("}");}
      elsepart ;

elsepart: {printf(" if\n");};
elsepart:  ELSE
      OPENB  { printf("\n{ \n") ; }
         stmtlist
      CLOSEB { printf("} ifelse\n");}; 
      
thenstmt: ;
thenstmt: THEN; 


stmt: WHILE OPEN {printf("{ ");} relation CLOSE 
        OPENB {printf("\{} {exit} ifelse\n");}  
           stmtlist 
        CLOSEB {printf(" } loop\n");};

stmt: PROC ID {printf("/proc%s",$2->symbol);} 
      OPENB {printf(" {\n");}
       stmtlist 
      CLOSEB  {printf("} def\n");};

stmt: CALL ID plist SEMICOLON{printf("proc%s\n",$2->symbol);};
plist: ;
plist: plist factor;



stmt: COPEN stmtlist CCLOSE;	 

expr: expr PLUS term { printf("add ");};
expr: expr MINUS term { printf("sub ");};
expr: term;

term: term TIMES factor { printf("mul ");};
term: term DIV factor { printf("div ");};
term: factor;

relation: factor  LESSTHAN factor {printf("lt\n");};
relation: factor GREATTHAN factor {printf("gt\n");};
relation: factor  COMPARE factor {printf("eq\n");};
relation: factor LESSTHAN ASSIGN factor {printf("le\n");};
relation: factor GREATTHAN ASSIGN factor {printf("ge\n");};
relation: factor NOT ASSIGN factor {printf("nq\n");};


factor: MINUS atomic { printf("neg ");};
factor: PLUS atomic;
factor: SIN factor { printf("sin ");};
factor: COS factor { printf("cos ");};
factor: SQRT factor { printf("sqrt ");};
factor: atomic;


atomic: OPENB expr CLOSEB;
atomic: NUMBER {printf("%d ",$1);};
atomic: FLOAT {printf("%f ",$1);};
atomic: ID {printf("tlt%s ", $1->symbol);};
atomic: PARAM;

%%
int yyerror(char *msg)
{  fprintf(stderr,"Error: %s\n",msg);
   return 0;
}

int main(void)
{   yyparse();
    return 0;
}

