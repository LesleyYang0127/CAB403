CC = gcc -lm -lrt -lpthread
CFLAGS = -Wall -pedantic
LDFLAGS =

all: shm_ipc
	echo "Success"

shm_ipc: shm_ipc.o

shm_ipc.o: shm_ipc.c


clean:
	rm -f shm_ipc *.o

.PHONY: all clean