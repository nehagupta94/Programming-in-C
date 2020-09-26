all: defuseTheBomb checkmem.o clean.o

defuseTheBomb: bomb.o defuseMe.o hidden.o
	gcc -g hidden.o bomb.o defuseMe.o -o defuseTheBomb

bomb.o: bomb.c
	gcc -g -c bomb.c -o bomb.o

defuseMe.o: defuseMe.c
	gcc -g -c defuseMe.c -o defuseMe.o

clean.o: Trash.sh
	chmod +x Trash.sh
	./Trash.sh *.o

checkmem.o: program3B.c
	gcc -Wall -g program3B.c -o memcheck
	valgrind ./memcheck
