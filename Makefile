CC = gcc
CFLAGS = -I.
DEPS = ArrayList.h BinaryTree.h console.h LinkedList.h main.h readFile.h Restaurant.h search.h writeFile.h
OBJ = ArrayList.o BinaryTree.o console.o LinkedList.o main.o readFile.o Restaurant.o search.o writeFile.o

%.o : %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

all : $(OBJ)
	$(CC) -o yelp $^ $(CFLAGS)

.PHONY : clean

clean :
	rm $(OBJ) yelp 
