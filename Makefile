funciones.o: Funciones.h Funciones.cpp
	g++ -Wall -g3 -c Funciones.cpp

main: main.cpp funciones.o
	g++ -Wall -g3 -o main main.cpp funciones.o
