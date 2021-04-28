#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <stack>
using namespace std;

class estudiante
{
    public:
        estudiante();
        estudiante(int ident, string cod, int leng, int ing, int mat, int cien, int hist, int tecn, int art, int ed_fis);
        void mostrar();
        int get_pg(); //retorna el promedio general
        int get_paryed; //retorna el promedio entre arte y educacion fisica
        int get_plehi; //retorna el promedio entre lenguaje e historia
        int get_pmaci; //retorna el promedio entre matematica y ciencias
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

int str_to_int(string);
void procesar(stack<estudiante> &);
void ver_stack(stack<estudiante>);

#endif // FUNCIONES_H_INCLUDED
