objects=main.o WeightedUndirectedGraph.o
graph : $(objects)
	gcc $(objects) -o graph
main.o : WeightedUndirectedGraph.h 
WeightedUndirectedGraph.o : WeightedUndirectedGraph.h
clean:
	rm graph $(objects)