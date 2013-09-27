/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     GO = 258,
     TURN = 259,
     VAR = 260,
     JUMP = 261,
     FOR = 262,
     STEP = 263,
     TO = 264,
     DO = 265,
     IF = 266,
     THEN = 267,
     ELSE = 268,
     WHILE = 269,
     PROC = 270,
     COPEN = 271,
     CCLOSE = 272,
     SIN = 273,
     COS = 274,
     SQRT = 275,
     FLOAT = 276,
     ID = 277,
     NUMBER = 278,
     SEMICOLON = 279,
     PLUS = 280,
     MINUS = 281,
     TIMES = 282,
     DIV = 283,
     OPEN = 284,
     CLOSE = 285,
     ASSIGN = 286,
     COMPARE = 287,
     LESSTHAN = 288,
     GREATTHAN = 289,
     NOT = 290,
     OPENB = 291,
     CLOSEB = 292,
     PARAM = 293,
     CALL = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 7 "turtle.y"
 int i; node *n; double d;


/* Line 2068 of yacc.c  */
#line 93 "turtle.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


