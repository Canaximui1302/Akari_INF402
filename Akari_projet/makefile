
CC = gcc
CFLAGS= -c -Wall

all: main

solveur.o: solveur.c solveur.h type.h
	$(CC) $(CFLAGS) solveur.c  

type.o: type.c type.h solveur.h
	$(CC) $(CFLAGS) type.c

main.o: main.c solveur.h type.h
	$(CC) $(CFLAGS) main.c

main: main.o solveur.o type.o
	$(CC) main.o solveur.o type.o -o main 

clean:
	rm -f *.o 
