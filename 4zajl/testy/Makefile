CC=g++
CXXFLAGS= -g -Wall -pedantic
OBJS = main.o MyArray.o
OUT = GAME

$(OUT): $(OBJS)
	$(CC)  -o $@  $^ $(CXXFLAGS)
	
.c.o:
	$(CC) -c -o $@ $< $(CXXFLAGS) 
	
.PHONY: clean run

clean:
	rm -f *o
	rm -f $(OUT)
	clear
	
run:
	./$(OUT)