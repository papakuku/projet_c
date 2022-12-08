all : prog


prog: main.o player.o
	gcc -o prog main.o player.o



main.o : main.c
	gcc -o main.o -c main.c

player.o : player.c
	gcc -o player.o -c player.c



clean :
	rm -rf *.o

mproper : clean
	rm -rf prog
