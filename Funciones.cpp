#include "Funciones.h"


estudiante::estudiante()
{
    identificador=0;
    codigo="";
    lenguaje=0;
    ingles=0;
    matematica=0;
    ciencias=0;
    historia=0;
    tecnologia=0;
    arte=0;
    ed_fisica=0;
    prom_gral=0;
    prom_artyed=0;
    prom_matycien=0;
}

estudiante::estudiante(int ident, string cod, int leng, int ing, int mat, int cien, int hist, int tecn, int art, int ed_fis)
{
    identificador = ident;
    codigo = cod;
    lenguaje = leng;
    ingles = ing;
    matematica = mat;
    ciencias = cien;
    historia = hist;
    tecnologia = tecn;
    arte = art;
    ed_fisica = ed_fis;
    prom_gral = (lenguaje + ingles + matematica + ciencias + historia + tecnologia + arte + ed_fisica)/8;
    prom_artyed = (arte + ed_fisica)/2;
    prom_lengyhist = (lenguaje + historia)/2;
    prom_matycien = (matematica + ciencias)/2;
    //ctor
}

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

void estudiante::mostrar()
{
    cout << "codigo: " << codigo << endl << "promedio general: " << prom_gral << endl << "promedio artistico: "<< prom_artyed << endl << "promedio humanista: " << prom_lengyhist << endl << "promedio cientifico: " << prom_matycien << endl;
}

estudiante::~estudiante()
{
    //dtor
}

string RemoveChar(string str, char c)
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

int str_to_int(string s)
{
    stringstream texto(s);
    string aux, numero="";
    while(getline(texto,aux,'.'))
        numero+=aux;
    char *help = new char [numero.length()+1];
    strcpy(help, numero.c_str());
    return atoi(help);

}



void procesar(vekest &V)
{
    ifstream archivo;
    archivo.open("estudiantes.csv", ios::in);
    if(archivo.is_open())
        {   string linea;
            while(getline(archivo, linea))
            {
                linea=RemoveChar(linea,'"');
                int iden ,i=0,notas[]={0,0,0,0,0,0,0,0};
                string codigo, segmento;
                stringstream help(linea);
                while(getline(help, segmento, ';' ))
                {
                    if(i==0)
                    {
                        char *cst = new char [segmento.length()+1];
                        strcpy(cst, segmento.c_str());
                        iden = atoi(cst);
                    }
                    if(i==1)
                    {
                        codigo = segmento;
                    }
                    if(i>1)
                    {
                        notas[i-2]=str_to_int(segmento);
                    }
                    i++;
                }
                estudiante aux(iden,codigo,notas[0],notas[1],notas[2],notas[3],notas[4],notas[5],notas[6],notas[7]);
                V.push_back(aux);
                //aux.mostrar();
            }
        }
}

void ver_vector(vekest V)
{
    for(int i=0; i<V.size(); i++)
    {
        V[i].mostrar();
        cout << endl;
    }
}

void shellsort_pg(vekest &V)
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

void shellsort_artes(vekest &V)
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

void shellsort_human(vekest &V)
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

void shellsort_cientifico(vekest &V)
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

void mejores_gral(vekest &V)
{
    shellsort_pg(V);
    ofstream archivo("Maximos.csv");
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++)
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";" + to_string(V[j].get_pg()) +'\n';
            archivo << aux;
        }

        int a=0;
        while(a<100)
        {
            V.pop_back();
            a++;
        }
        archivo.close();

    }
}

void mejores_artes(vekest &V)
{
    shellsort_artes(V);
    ofstream archivo("Artistico.csv");
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++)
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";" + to_string(V[j].get_paryed()) +'\n';
            archivo << aux;
        }

        int a=0;
        while(a<100)
        {
            V.pop_back();
            a++;
        }
        archivo.close();

    }
}

void mejores_humanismo(vekest &V)
{
    shellsort_human(V);
    ofstream archivo("humanismo.csv");
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++)
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";" + to_string(V[j].get_plehi()) +'\n';
            archivo << aux;
        }

        int a=0;
        while(a<100)
        {
            V.pop_back();
            a++;
        }
        archivo.close();

    }
}

void mejores_cientifico(vekest &V)
{
    shellsort_cientifico(V);
    ofstream archivo("tecnicos.csv");
    if(archivo.is_open())
    {
        int i=V.size();
        for(int j = i-100;j<i;j++)
        {
            string aux ="";
            aux += to_string(V[j].get_iden()) + ";" + V[j].get_codigo() + ";" + to_string(V[j].get_pmaci()) +'\n';
            archivo << aux;
        }

        int a=0;
        while(a<100)
        {
            V.pop_back();
            a++;
        }
        archivo.close();

    }
}


