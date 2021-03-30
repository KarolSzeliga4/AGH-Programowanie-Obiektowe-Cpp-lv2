FLAGS = -Wall -pedantic
GXX = g++

all: main run 

main: main.o wire.o
	$(GXX) *.o -o main

main.o: main.cpp
	$(GXX) -c $(FLAGS) main.cpp

wire.o: wire.cpp wire.h
	$(GXX) -c $(FLAGS) wire.cpp

clean:
	rm -rf *.o main

run: 
	./main

check:
	valgrind ./main

.PHONY: all run clean check
