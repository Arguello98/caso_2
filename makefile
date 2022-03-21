caso_2: main quicksort insertion textSearch 
	g++ -o caso_2 main.o quicksort.o insertion.o textSearch.o

main:
	g++ -c main.cpp

quicksort:
	g++ -c quicksort.cpp

insertion:
	g++ -c insertion.cpp

textSearch:
	g++ -c textSearch.cpp