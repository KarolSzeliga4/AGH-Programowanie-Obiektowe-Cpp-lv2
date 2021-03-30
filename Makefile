FLAGS = -Wall -pedantic
GXX = g++

all: main run 

main: main.o
	$(GXX) *.o -o main

main.o: main.cpp shape.h shape_ptr.h 
	$(GXX) -c $(FLAGS) main.cpp

clean:
	rm -rf *.o main

run: 
	./main

check: main
	valgrind ./main 

.PHONY: all run clean check 
