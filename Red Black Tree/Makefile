objects=main.o RedBlackTree.o
red : $(objects)
	gcc $(objects) -o red
main.o : RedBlackTree.h 
RedBlackTree.o : RedBlackTree.h
clean:
	rm red $(objects)