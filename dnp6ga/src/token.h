
/* Tokens.  */
#define GO 258
#define TURN 259
#define VAR 260
#define JUMP 261
#define FOR 262
#define STEP 263
#define TO 264
#define DO 265
#define IF 266
#define THEN 267
#define ELSE 268
#define WHILE 269
#define PROC 270
#define COPEN 271
#define CCLOSE 272
#define SIN 273
#define COS 274
#define SQRT 275
#define FLOAT 276
#define ID 277
#define NUMBER 278
#define SEMICOLON 279
#define PLUS 280
#define MINUS 281
#define TIMES 282
#define DIV 283
#define OPEN 284
#define CLOSE 285
#define ASSIGN 286
#define COMPARE 287
#define LESSTHAN 288
#define GREATTHAN 289
#define NOT 290
#define OPENB 291
#define CLOSEB 292
#define PARAM 293
#define CALL 294
typedef union YYSTYPE
{ int i; node *n; double d;}
        YYSTYPE;
extern YYSTYPE yylval;

