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


void shellsort(vekest &V, int indicador) //Shellsort para ordenar de menor a mayor por promedio, el indicador indica cual es el criterio a ordenar
{
    int n=V.size();
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i<n; i+=1)
        {
            estudiante aux=V[i];
            int j;
            switch(indicador){

            case 0: //ordena respecto al promedio general
                for(j = i; j >= gap && V[j - gap].get_pg() > aux.get_pg(); j -= gap)
                    V[j] = V[j - gap];
                break;
            case 1: //ordena respecto al promedio artístico
                for(j = i; j >= gap && V[j - gap].get_paryed() > aux.get_paryed(); j -= gap)
                    V[j] = V[j - gap];
                break;
            case 2: //ordena respecto al promedio humanista
                for(j = i; j >= gap && V[j - gap].get_plehi() > aux.get_plehi(); j -= gap)
                    V[j] = V[j - gap];
                break;
            case 3: //ordena respecto al promedio técnico
                for(j = i; j >= gap && V[j - gap].get_pmaci() > aux.get_pmaci(); j -= gap)
                    V[j] = V[j - gap];
                break;
            }
            V[j]= aux;
        }
    }

}

void mejores(vekest &V, int indicador, string nombre_archivo) //Procedimiento que escribe el archivo dependiendo del indicador
{
    shellsort(V,indicador);
    ofstream archivo(nombre_archivo+".csv");
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++) //Se escriben los últimos 100 estudiantes que por el ordenamiento son los 100 con promedio más alto
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";";
            switch(indicador){
            case 0: //Escribe el promedio general
                aux+= to_string(V[j].get_pg());
                break;
            case 1: //Escribe el promedio artístico
                aux+= to_string(V[j].get_paryed());
                break;
            case 2: //Escribe el promedio humanista
                aux+= to_string(V[j].get_plehi());
                break;
            case 3: //Escribe el promedio técnico
                aux+= to_string(V[j].get_pmaci());
                break;
            }
            aux+= '\n';
            archivo << aux;
        }

        int a=0;
        while(a<100) //Se borran los últimos 100 estudiantes del vector para catalogar los siguientes
        {
            V.pop_back();
            a++;
        }
        cout << "Archivo " << nombre_archivo << ".csv creado con exito" << endl;
        archivo.close();
    }
}

void programa(vekest &V) //Procedimiento que ejecuta todo
{
    procesar(V);
    mejores(V,0,"Maximos");
    mejores(V,1,"Artistico");
    mejores(V,2,"Humanismo");
    mejores(V,3,"Tecnico");
}


