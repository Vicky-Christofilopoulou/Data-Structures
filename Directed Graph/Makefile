objects= main.o DirectedGraph.o
graph : $(objects)
	gcc $(objects) -o graph
main.o: DirectedGraph.h
DirectedGraph.o: DirectedGraph.h
clean:
	rm graph $(objects);