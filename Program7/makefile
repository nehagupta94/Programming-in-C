all: program7
program7: program7.o heap.o
	gcc -g program7.o heap.o -o program7
program7.o: program7.c
	gcc -g -c program7.c -o program7.o
heap.o: heap.c
	gcc -g -c heap.c -o heap.o
run:program7
	./program7
memcheck: program7
	valgrind --leak-check=yes --track-origins=yes -v ./program7
clean: program7
	rm program7.o heap.o program7