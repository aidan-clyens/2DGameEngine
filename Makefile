CC=g++
CFLAGS=-Wall
DEBUG=-g
RELEASE=-O2
CSRCS=$(wildcard src/*cpp)
LINKER=-lsfml-graphics -lsfml-window -lsfml-system
INCLUDE=-I/usr/local/include/SFML -Iinclude

all: debug

debug:
	$(CC) -o main.o ${CSRCS} ${CFLAGS} ${DEBUG} ${INCLUDE} ${LINKER}

release:
	$(CC) -o main.o $(CSRCS) ${CFLAGS} ${RELEASE} ${INCLUDE} ${LINKER}

.PHONY: clean
clean:
	rm -rf *.o
