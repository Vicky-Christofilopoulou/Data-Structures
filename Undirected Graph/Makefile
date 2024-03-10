objects= main.o UndirectedGraph.o
graph : $(objects)
	gcc $(objects) -o graph
main.o: UndirectedGraph.h
UndirectedGraph.o: UndirectedGraph.h
clean:
	rm graph $(objects);