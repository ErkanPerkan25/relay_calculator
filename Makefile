CXX ?= g++

CXXFLAGS := -c -Wall -ansi -pedantic -std=c++20

relay_calculator: main.o Swimmer.o
	$(CXX) -o relay_calculator main.o Swimmer.o

main.o: main.cpp Swimmer.hpp
	$(CC) $(CXXFLAGS) main.cpp

Swimmer.o: Swimmer.cpp Swimmer.hpp
	$(CC) $(CXXFLAGS) Swimmer.cpp

clean:
	/bin/rm -f *~ *.o relay_calculator

.PHONY: clean
