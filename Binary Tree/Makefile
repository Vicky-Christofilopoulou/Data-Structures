objects=main.o BinaryTree.o
Binary : $(objects)
	gcc $(objects) -o Binary
main.o : BinaryTree.h 
BinaryTree.o : BinaryTree.h
clean:
	rm Binary $(objects)