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

class estudiante //Declaraci�n de la clase estudiante que guarda los datos obtenidos mediante el archivo estudiantes.csv
{
    public:
        //Declaraci�n de constructores
        estudiante();
        estudiante(int ident, string cod, int leng, int ing, int mat, int cien, int hist, int tecn, int art, int ed_fis);
        //Declaraci�n de getters
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
        //Se guardar�n los promedios solamente para agilizar la ejecuci�n del programa
        int prom_gral;
        int prom_artyed;
        int prom_lengyhist;
        int prom_matycien;
};

typedef vector<estudiante> vekest; //declaraci�n de vector de tipo estudiante para c�digo m�s limpio


//Prototipo de procedimiento que se ejecutar� en el main
void programa(vekest &);
#endif // FUNCIONES_H_INCLUDED
