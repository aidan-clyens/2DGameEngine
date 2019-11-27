CC=g++
CFLAGS=-Wall
DEBUG=-g
RELEASE=-O2
CSRCS=$(wildcard src/*cpp) $(wildcard src/*/*.cpp)
LINKER=-lsfml-graphics -lsfml-window -lsfml-system
INCLUDE=-I/usr/local/include/SFML -Iinclude -Iinclude/States -Iinclude/GameObjects -Iinclude/ResourceManagers -Iinclude/GUI

all: debug

debug:
	$(CC) -o main.o ${CSRCS} ${CFLAGS} ${DEBUG} ${INCLUDE} ${LINKER}

release:
	$(CC) -o main.o $(CSRCS) ${CFLAGS} ${RELEASE} ${INCLUDE} ${LINKER}

.PHONY: clean
clean:
	rm -rf *.o
