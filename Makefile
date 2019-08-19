CC=g++
CFLAGS=-Wall
DEBUG=-g
RELEASE=-o2
CSRCS=$(wildcard src/*cpp)
LINKER=-lsfml-graphics -lsfml-window -lsfml-system
INCLUDE=-I/usr/local/include/SFML -Iinclude

all: main.o

main.o:
	$(CC) -o main.o ${CSRCS} ${CFLAGS} ${DEBUG} ${INCLUDE} ${LINKER}

.PHONY: clean
clean:
	rm -rf *.o
