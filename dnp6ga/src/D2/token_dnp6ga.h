
/* Tokens.  */
#define CGO 258
#define CTURN 259
#define VAR 260
#define CJUMP 261
#define FORLOOP 262
#define STEPLOOP 263
#define TO 264
#define DO 265
#define OPEN 266
#define CLOSE 267
#define SINFUNC 268
#define COSFUNC 269
#define SQRT 270
#define FLOAT 271
#define ID 272
#define INTEGER 273
#define SEMICOLON 274
#define PLUS 275
#define MINUS 276
#define MULT 277
#define DIV 278
#define OPENP 279
#define CLOSEP 280
#define ASSIGN 281
#define OPENB 282
#define CLOSEB 283
#define MOD 284
#define POWER 285
#define IF 286
#define ELSE 287
#define THEN 288
#define WHILE 289
#define PROC 290
#define INT 291
#define FLOATN 292
#define CHAR 293
#define DOUBLE 294
#define SWITCH 295
#define CASE 296

typedef union YYSTYPE
{ int i; node *n; double d;}
        YYSTYPE;
YYSTYPE yylval;

