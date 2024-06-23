CC=g++
CXXFLAGS=-std=c++11 -Wall -g
exe=asm3

OBJS = airport.o flight.o main.o manager.o

all: $(exe)

$(exe): $(OBJS)
	$(CC) $(OBJS) -o $(exe)

airport.o: airport.cpp airport.h
	$(CC) -c $(CXXFLAGS) airport.cpp

flight.o: flight.cpp flight.h
	$(CC) -c $(CXXFLAGS) flight.cpp

main.o: main.cpp airport.h flight.h manager.h
	$(CC) -c $(CXXFLAGS) main.cpp

manager.o: manager.cpp manager.h
	$(CC) -c $(CXXFLAGS) manager.cpp

clean:
	rm -f *.o $(exe)
