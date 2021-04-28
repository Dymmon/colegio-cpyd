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

void procesar(stack<estudiante> &s)
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
                s.push(aux);
                //aux.mostrar();
            }
        }
}

void ver_stack(stack<estudiante> s)
{
    stack<estudiante> aux;
    while(!s.empty())
    {
        estudiante a = s.top();
        s.pop();
        aux.push(a);
        a.mostrar();
        cout << endl;
    }
    while(!aux.empty())
    {
        s.push(aux.top());
        aux.pop();
    }

}


