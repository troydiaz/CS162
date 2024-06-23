MAKEFLAGS += -j

CC=g++
CXXFLAGS=-std=c++11 -Wall -g
exe=wumpus

OBJS = event.o game.o gold.o main.o pool.o room.o stalactites.o wumpus.o

all: $(exe)

$(exe): $(OBJS)
	$(CC) $(OBJS) -o $(exe)

event.o: event.cpp event.h
	$(CC) -c $(CXXFLAGS) event.cpp

game.o: game.cpp game.h gold.h stalactites.h pool.h wumpus.h
	$(CC) -c $(CXXFLAGS) game.cpp

gold.o: gold.cpp gold.h
	$(CC) -c $(CXXFLAGS) gold.cpp

main.o: main.cpp game.h
	$(CC) -c $(CXXFLAGS) main.cpp

pool.o: pool.cpp pool.h
	$(CC) -c $(CXXFLAGS) pool.cpp

room.o: room.cpp room.h
	$(CC) -c $(CXXFLAGS) room.cpp

stalactites.o: stalactites.cpp stalactites.h
	$(CC) -c $(CXXFLAGS) stalactites.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c $(CXXFLAGS) wumpus.cpp

clean:
	rm -f *.o $(exe)