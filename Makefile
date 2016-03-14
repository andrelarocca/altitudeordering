altitude: main.o graph.o
	g++ main.o graph.o -o altitude

main.o: main.c
	g++ -c main.c -o main.o

graph.o: graph.c
	g++ -c graph.c -o graph.o

clean:
	rm *o altitude
