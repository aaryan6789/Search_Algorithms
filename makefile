all: search

clean:
	rm	-f *.o
	rm	sortingAlgorithms
	rm	search

#Compilation Rules
search:	binary_search.o	array.o	main.o
	gcc -g -o	search binary_search.o	array.o	main.o

binary_search.o:	binary_search.c	catalog.h
	gcc -c -g binary_search.c catalog.h

array.o:	array.c	catalog.h
	gcc -c -g array.c catalog.h

main.o:	main.c	catalog.h
	gcc -c -g main.c catalog.h