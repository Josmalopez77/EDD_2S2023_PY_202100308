#ifndef NODOLISTA_H_INCLUDED
#define NODOLISTA_H_INCLUDED

#include <string>
#include "Empleados.h"
using namespace std;

class NodoLista
{
    public:
        Empleado *EmpleadoSistema;
        NodoLista *Siguiente;
        NodoLista *Anterior;
        NodoLista(std::string nombre, std::string password);
        virtual ~NodoLista();

    protected:

    private:
};



#endif // NODOLISTA_H_INCLUDED
