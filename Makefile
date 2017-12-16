PROG=final
CC=g++
CPPFLAGS=-g -Wall -std=c++11

.PHONY: all

all:
	$(CC) $(CPPFLAGS) main.cpp MST.cpp Test.cpp Heap.cpp -o $(PROG)

clean:
	rm -f *.o $(PROG) core
