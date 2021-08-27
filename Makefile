CC = gcc
CFLAGS = -Wall -pedantic
LDFLAGS =

all: dbl_vector
	echo "Success"

dbl_vector: main.o dbl_vector.o

main.o: main.c

dbl_vector.o: dbl_vector.c



clean:
	rm -f fib *.o

.PHONY: all clean