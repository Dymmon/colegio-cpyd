#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;

class estudiante
{
    public:
        estudiante();
        estudiante(int ident, string cod, int leng, int ing, int mat, int cien, int hist, int tecn, int art, int ed_fis);
        void mostrar();
        int get_pg(); //retorna el promedio general
        int get_paryed(); //retorna el promedio entre arte y educacion fisica
        int get_plehi(); //retorna el promedio entre lenguaje e historia
        int get_pmaci(); //retorna el promedio entre matematica y ciencias
        string get_codigo();
        int get_iden();
        virtual ~estudiante();

    protected:

    private:
        int identificador;
        string codigo;
        int lenguaje;
        int ingles;
        int matematica;
        int ciencias;
        int historia;
        int tecnologia;
        int arte;
        int ed_fisica;
        int prom_gral;
        int prom_artyed;
        int prom_lengyhist;
        int prom_matycien;
};

typedef vector<estudiante> vekest;



int str_to_int(string);
void procesar(vekest &);
void ver_vector(vekest);
void mejores_gral(vekest &);
void mejores_artes(vekest &);
void mejores_humanismo(vekest &);
void mejores_cientifico(vekest &);

#endif // FUNCIONES_H_INCLUDED
