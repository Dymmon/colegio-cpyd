
main: main.cpp Funciones.o
	g++ -Wall -g3 -o Programa_estudiantes main.cpp Funciones.o

Funciones.o: Funciones.h Funciones.cpp
	g++ -Wall -g3 -c Funciones.cpp

.PHONY: clean
clean:
	rm -fr *o Programa_estudiantes