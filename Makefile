CC = g++
CFLAGS = -c -g -Wall -Wextra
LFLAGS = -g -Wall -Wextra -I/usr/local/lib -L/usr/local/lib

.PHONY: all clean

all: test

test: cube.o test.cpp
	$(CC) $(LFLAGS) $^ -o $@

cube.o: cube.cpp cube.h
	$(CC) $(CFLAGS) $<

clean:
	$(RM) *.o
	$(RM) *~
	$(RM) *.txt
	$(RM) test
