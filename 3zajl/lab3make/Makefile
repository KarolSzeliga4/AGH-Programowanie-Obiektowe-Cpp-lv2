FLAGS = -Wall -pedantic
GXX = g++

all: main run 

main: main.o vector.o matrix.o
	$(GXX) *.o -o main

main.o: main.cpp
	$(GXX) -c $(FLAGS) main.cpp

vector.o: vector.cpp vector.h
	$(GXX) -c $(FLAGS) vector.cpp

matrix.o: matrix.cpp matrix.h
	$(GXX) -c $(FLAGS) matrix.cpp	

clean:
	rm -rf *.o main

run: 
	./main

check: main
	valgrind ./main 

.PHONY: all run clean check 
