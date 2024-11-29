CXX=gcc
CXXFLAGS=-I. -g
.PHONY: clean

main: cjl.o main.o
	$(CXX) $(CXXFLAGS) cjl.o main.o -o main

cjl.o main.o: cjl.h cjl.c main.c
	$(CXX) $(CXXFLAGS) -c cjl.c main.c

clean:
	rm -rf main *.o