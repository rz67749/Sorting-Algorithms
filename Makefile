GPP = g++
CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors

main: Main.cpp Sorting.o
	$(GPP) $(CFLAGS) -o main Main.cpp Sorting.o

Sorting.o: Sorting.cpp Sorting.h
	$(GPP) $(CFLAGS) -c Sorting.cpp

clean:
	rm -rf main
	rm -rf *.o
