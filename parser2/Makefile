parse: decl.o expr.o stmt.o type.o param_list.o symbol.o scope.o hash_table.o main.o scanner.o parser.o library.o
	/usr/bin/gcc decl.o param_list.o expr.o stmt.o type.o symbol.o scope.o hash_table.o main.o scanner.o parser.o -o cminor -lm

%.o: %.c *.h
	/usr/bin/gcc -Wall -c $< -o $@

scanner.c: scanner.flex parser.h
	flex -oscanner.c scanner.flex

parser.c parser.h: parser.bison 
	bison --defines=parser.h --output=parser.c -v parser.bison 

clean:
	rm -f *.s *.o cminor lex.yy.c parse.tab.* parser.output sourcefile


assemble:
	/usr/bin/gcc -c sourcefile.s -o sourcefile.o
	/usr/bin/gcc sourcefile.o library.o -o sourcefile
