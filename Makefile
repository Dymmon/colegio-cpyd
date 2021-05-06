Programa: main.cpp Funciones.o
	g++ -Wall -g3 -o Programa main.cpp Funciones.o

Funciones.o: Funciones.h Funciones.cpp
	g++ -Wall -g3 -c Funciones.cpp
