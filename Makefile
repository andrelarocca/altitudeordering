altitude: graph.o main.o
	gcc -g graph.o main.o -o altitude
main.o: main.c graph.h
	gcc -g -c main.c
graph.o: graph.h graph.c
	gcc -g -c graph.c
