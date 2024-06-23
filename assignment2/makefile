CC=g++ 
CXXFLAGS = -std=c++11 -Wall
exe=asm2

all: $(exe)

$(exe): catalog.o run_catalog.o
	$(CC) catalog.o run_catalog.o -o $(exe)

catalog.o: catalog.cpp catalog.h 
	$(CC) -c $(CXXFLAGS) catalog.cpp

run_catalog.o: run_catalog.cpp catalog.h
	$(CC) -c $(CXXFLAGS) run_catalog.cpp

clean:
	rm -f *.o $(exe)
