
all: program4 clean
program4: program4.o tournament.o
	gcc -g program4.o tournament.o -o program4 
program4.o: program4.c
	gcc -g -c program4.c -o program4.o
tournament.o: tournament.c
	gcc -g -c tournament.c -o tournament.o
run:program4
	./program4 	
checkmem: program4
	valgrind --leak-check=yes -v ./program4 
clean: program4
	rm program4.o tournament.o program4 
