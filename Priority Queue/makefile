objects=sorting.o PQImplementation.o
pqsort : $(objects)
	gcc $(objects) -o pqsort

sorting.o : PQInterface.h 

PQImplementation.o : PQInterface.h 

clean:
	rm pqsort $(objects)