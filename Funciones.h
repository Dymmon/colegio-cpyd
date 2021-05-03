#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//Se incluyen todas las librerias a usar
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;

class estudiante //Declaración de la clase estudiante que guarda los datos obtenidos mediante el archivo estudiantes.csv
{
    public:
        //Declaración de constructores
        estudiante();
        estudiante(int ident, string cod, int leng, int ing, int mat, int cien, int hist, int tecn, int art, int ed_fis);
        //Declaración de getters
        int get_pg(); //retorna el promedio general
        int get_paryed(); //retorna el promedio entre arte y educacion fisica
        int get_plehi(); //retorna el promedio entre lenguaje e historia
        int get_pmaci(); //retorna el promedio entre matematica y ciencias
        string get_codigo();
        int get_iden();

    protected:

    private:
        int identificador;
        string codigo;
        //Se guardarán los promedios solamente para agilizar la ejecución del programa
        int prom_gral;
        int prom_artyed;
        int prom_lengyhist;
        int prom_matycien;
};

typedef vector<estudiante> vekest; //declaración de vector de tipo estudiante para código más limpio


//Prototipo de procedimiento que se ejecutará en el main
void programa(vekest &);
#endif // FUNCIONES_H_INCLUDED
