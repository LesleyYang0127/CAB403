CC = gcc
CFLAGS = -Wall -pedantic

all: part1

part1: dbl_vector.o main.o

main.o: main.c

dbl_vector: dbl_vector.c

clean:
	rm -f fib *.o

.PHONY: all clean