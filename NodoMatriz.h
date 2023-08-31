#ifndef NODOMATRIZ_H_INCLUDED
#define NODOMATRIZ_H_INCLUDED
#include <string>
#include "Proyecto.h"
#include "Empleados.h"
#include "ListaDoble.h"

using namespace std;

class NodoMatriz{
public:
    NodoMatriz *Siguiente;
    NodoMatriz *Anterior;
    NodoMatriz *Abajo;
    NodoMatriz *Arriba;
    int PosY;
    int PosX;
    Proyecto *Proyecto_c;
    Empleado *Encargado_c;
    ListaDoble *Tareas;
    NodoMatriz(Proyecto *proyecto, Empleado *encargado, int posy, int posx);

    virtual ~NodoMatriz();
};



#endif // NODOMATRIZ_H_INCLUDED
