#include "Funciones.h"


estudiante::estudiante() //Constructor vacío de la clase estudiante
{
    identificador=0;
    codigo="";
    prom_gral=0;
    prom_artyed=0;
    prom_matycien=0;
}

estudiante::estudiante(int ident, string cod, int leng, int ing, int mat, int cien, int hist, int tecn, int art, int ed_fis) //Constructor con parámetros de la clase estudiante
{
    identificador = ident;
    codigo = cod;
    prom_gral = (leng + ing + mat + cien + hist + tecn + art + ed_fis)/8;
    prom_artyed = (art + ed_fis)/2;
    prom_lengyhist = (leng + hist)/2;
    prom_matycien = (mat + cien)/2;
    //ctor
}

//Funciones miembro que retornan los datos privados guardados
int estudiante::get_pg()
{
    return prom_gral;
}
int estudiante::get_paryed()
{
    return prom_artyed;
}

int estudiante::get_plehi()
{
    return prom_lengyhist;
}

int estudiante::get_pmaci()
{
    return prom_matycien;
}

string estudiante::get_codigo()
{
    return codigo;
}

int estudiante::get_iden()
{
    return identificador;
}


string RemoveChar(string str, char c) //Función que remueve un caracter de un string para eliminar los " que vienen en el archivo
{
   string result;
   for (size_t i = 0; i < str.size(); i++)
   {
          char currentChar = str[i];
          if (currentChar != c)
              result += currentChar;
   }
       return result;
}

int str_to_int(string s) //Función para transformar los números con puntos en números utilizables
{
    stringstream texto(s);
    string aux, numero="";
    while(getline(texto,aux,'.'))
        numero+=aux;
    char *help = new char [numero.length()+1];
    strcpy(help, numero.c_str());
    return atoi(help);

}



void procesar(vekest &V) //Procedimiento principal del programa que procesa el archivo estudiante y lo transforma en un objeto estudiante
{
    ifstream archivo;
    archivo.open("estudiantes.csv", ios::in);
    if(archivo.is_open())
        {   string linea;
            while(getline(archivo, linea))
            {
                linea=RemoveChar(linea,'"'); //invocación de función que borra los "
                int iden ,i=0,notas[]={0,0,0,0,0,0,0,0};
                string codigo, segmento;
                stringstream help(linea);
                while(getline(help, segmento, ';' ))
                {
                    if(i==0) //Se guarda el número identificatorio
                    {
                        char *cst = new char [segmento.length()+1];
                        strcpy(cst, segmento.c_str());
                        iden = atoi(cst);
                    }
                    if(i==1) //Se guarda el nombre genérico del alumno
                    {
                        codigo = segmento;
                    }
                    if(i>1) //Se guardan las notas en un arreglo para el acceso más fácil
                    {
                        notas[i-2]=str_to_int(segmento); //Se invoca a la función que transforma los números con punto en números usables
                    }
                    i++;
                }
                estudiante aux(iden,codigo,notas[0],notas[1],notas[2],notas[3],notas[4],notas[5],notas[6],notas[7]); //Creación del estudiante con los datos recopilados
                V.push_back(aux); //Se añade el estudiante al vector
            }
        }
}


void shellsort_pg(vekest &V) //Shellsort que ordena por promedio general
{
    int n=V.size();
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i<n; i+=1)
        {
            estudiante aux=V[i];
            int j;
            for(j = i; j >= gap && V[j - gap].get_pg() > aux.get_pg(); j -= gap)
                V[j] = V[j - gap];
            V[j]= aux;
        }
    }
}

void shellsort_artes(vekest &V) //Shellsort que ordena por promedio artístico
{
    int n=V.size();
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i<n; i+=1)
        {
            estudiante aux=V[i];
            int j;
            for(j = i; j >= gap && V[j - gap].get_paryed() > aux.get_paryed(); j -= gap)
                V[j] = V[j - gap];
            V[j]= aux;
        }
    }
}

void shellsort_human(vekest &V) //Shellsort que ordena por promedio humanismo
{
    int n=V.size();
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i<n; i+=1)
        {
            estudiante aux=V[i];
            int j;
            for(j = i; j >= gap && V[j - gap].get_plehi() > aux.get_plehi(); j -= gap)
                V[j] = V[j - gap];
            V[j]= aux;
        }
    }
}

void shellsort_cientifico(vekest &V) //Shellsort que ordena por promedio técnico
{
    int n=V.size();
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i<n; i+=1)
        {
            estudiante aux=V[i];
            int j;
            for(j = i; j >= gap && V[j - gap].get_pmaci() > aux.get_pmaci(); j -= gap)
                V[j] = V[j - gap];
            V[j]= aux;
        }
    }
}

void mejores_gral(vekest &V) //Procedimiento que crea el archivo máximos.csv
{
    shellsort_pg(V); //Se ordenan los estudiantes por su promedio general de menor a mayor
    ofstream archivo("Maximos.csv");
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++) //Se escriben los últimos 100 estudiantes que por el ordenamiento son los 100 con promedio más alto
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";" + to_string(V[j].get_pg()) +'\n';
            archivo << aux;
        }

        int a=0;
        while(a<100) //Se borran los últimos 100 estudiantes del vector para catalogar los siguientes
        {
            V.pop_back();
            a++;
        }
        cout << "Archivo Maximos.csv creado con exito" << endl;
        archivo.close();

    }
}

void mejores_artes(vekest &V) //Procedimiento que crea el archivo artístico.csv
{
    shellsort_artes(V); //Se ordenan los estudiantes por su promedio artístico de menor a mayor
    ofstream archivo("Artistico.csv");
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++)  //Se escriben los últimos 100 estudiantes que por el ordenamiento son los 100 con promedio más alto
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";" + to_string(V[j].get_paryed()) +'\n';
            archivo << aux;
        }

        int a=0;
        while(a<100) //Se borran los últimos 100 estudiantes del vector para catalogar los siguientes
        {
            V.pop_back();
            a++;
        }
        cout << "Archivo Artistico.csv creado con exito" << endl;
        archivo.close();

    }
}

void mejores_humanismo(vekest &V) //Procedimiento que crea el archivo humanismo.csv
{
    shellsort_human(V);
    ofstream archivo("Humanismo.csv"); //Se ordenan los estudiantes por su promedio humanista de menor a mayor
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++) //Se escriben los últimos 100 estudiantes que por el ordenamiento son los 100 con promedio más alto
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";" + to_string(V[j].get_plehi()) +'\n';
            archivo << aux;
        }

        int a=0;
        while(a<100) //Se borran los últimos 100 estudiantes del vector para catalogar los siguientes
        {
            V.pop_back();
            a++;
        }
        cout << "Archivo Humanismo.csv creado con exito" << endl;
        archivo.close();

    }
}

void mejores_cientifico(vekest &V) //Procedimiento que crea el archivo tecnico.csv
{
    shellsort_cientifico(V); //Se ordenan los estudiantes por su promedio técnico de menor a mayor
    ofstream archivo("Tecnicos.csv");
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++) //Se escriben los últimos 100 estudiantes que por el ordenamiento son los 100 con promedio más alto
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";" + to_string(V[j].get_pmaci()) +'\n';
            archivo << aux;
        }

        int a=0;
        while(a<100) //Se borran los últimos 100 estudiantes del vector por si hubiese que hacer más listas
        {
            V.pop_back();
            a++;
        }
        cout << "Archivo Tecnicos.csv creado con exito" << endl;
        archivo.close();

    }
}

void programa(vekest &V) //Procedimiento que ejecuta todo
{
    procesar(V);
    mejores_gral(V);
    mejores_artes(V);
    mejores_humanismo(V);
    mejores_cientifico(V);
}


