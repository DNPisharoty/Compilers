
all: turtle eins.ps

eins.ps: eins.tlt turtle
	./turtle < eins.tlt > eins.ps

lex.yy.o:  lex.yy.c turtle.tab.h symtab.h
	gcc -c lex.yy.c

lex.yy.c: turtle-dnp6ga.l
	flex turtle-dnp6ga.l
	
turtle.tab.h: turtle-dnp6ga.y
	bison -d turtle-dnp6ga.y
	
turtle.tab.c: turtle-dnp6ga.y
	bison -d turtle-dnp6ga.y
	
turtle.tab.o: turtle.tab.c symtab.h
	gcc -c turtle.tab.c

turtle: turtle.tab.o lex.yy.o symtab.c
	gcc lex.yy.o turtle.tab.o symtab.c -lfl -o turtle

clean:
	rm -f turtle lex.* turtle.tab.* *.o eins.ps

