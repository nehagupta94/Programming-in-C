all: program6
program6: program6.o bst.o
	gcc -g program6.o bst.o -o program6
program6.o: program6.c
	gcc -g -c program6.c -o program6.o
bst.o: bst.c
	gcc -g -c bst.c -o bst.o
run:program6
	./program6
memcheck: program6
	valgrind --leak-check=yes --track-origins=yes -v ./program6
clean: program6
	rm program6.o bst.o program6