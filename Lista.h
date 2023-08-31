#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "NodoLista.h"
#include <string>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Lista
{
    public:
        NodoLista *Primero;
        int Tamanio;
        void Insertar(std::string nombre, std::string password);
        void VerLista();
        void LeerArchivo(std::string nombre_archivo);
        void Graficar_Lista();
        Lista();
        virtual ~Lista();

    protected:

    private:
};


#endif // LISTA_H_INCLUDED
