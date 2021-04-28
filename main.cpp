#include "Funciones.h"

int main()
{
    vekest V;
    cout << "Testing" << endl << endl;
    procesar(V);
    cout << V.size() << endl;
    mejores_gral(V);
    cout << V.size() << endl;
    mejores_artes(V);
    cout << V.size() << endl;
    mejores_humanismo(V);
    cout << V.size() << endl;
    mejores_cientifico(V);
    cout << V.size() << endl;


    //ver_vector(V);

    return 0;
}
