CC = gcc
#CFLAGS=-W -Wall -ansi -pedantic -std=c99
CFLAGS = -std=c99

.PHONY: all

all: game

game: main.o
	$(CC) gcc -o $@ $^ $(CFLAGS)
main.o: tabsim.o lista.o
	$(CC) -c main.c tabsim.c elemento.c lista.c $(CFLAGS)
%.o : %.c
	gcc -o $@ $< -c $(CFLAGS)

lista.o : lista.h

tabsim.o : tabsim.h

clean:
		rm -rf *.o *~
mrproper: clean
		rm -rf game
