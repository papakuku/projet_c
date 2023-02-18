
CC=gcc
EXEC=prog
SRC =$(willcard *.c)
OBJ =$(SRC:.c=.o)




all:$(EXEC)

$(EXEC):main.o 
	$(CC) -o $@ $^ && ./$(EXEC)		

%.0 :%.c
	$(CC) -o $@ -c $<



clean: 
	rm -r *.o


mrp:clean
	rm -r prog		
