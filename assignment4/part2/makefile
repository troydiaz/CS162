MAKEFLAGS += -j

CC=g++
CXXFLAGS=-std=c++11 -Wall -g
exe=stairs

OBJS = recurse.o stairs.o

all: $(exe)

$(exe): $(OBJS)
	$(CC) $(OBJS) -o $(exe)

recurse.o: recurse.cpp stairs.h
	$(CC) -c $(CXXFLAGS) recurse.cpp

stairs.o: stairs.cpp 
	$(CC) -c $(CXXFLAGS) stairs.cpp

clean:
	rm -f *.o $(exe)
