CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o array.o movement.o terminal.o
EXEC = escape

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c array.h macros.h
	$(CC) $(CFLAGS) main.c -c

array.o : array.c array.h
	$(CC) $(CFLAGS) array.c -c

movement.o : movement.c movement.h
	$(CC) $(CFLAGS) movement.c -c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

clean :
	rm -f $(EXEC) $(OBJ)