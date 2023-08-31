#ifndef NODOLISTADOBLE_H_INCLUDED
#define NODOLISTADOBLE_H_INCLUDED

#include <string>

using namespace std;

class NodoListaDoble{
public:
    std::string Codigo;
    std::string Nombre_Tarea;
    std::string Codigo_Encargado;
    NodoListaDoble *Siguiente;
    NodoListaDoble *Anterior;
    NodoListaDoble(std::string codigo, std::string nombre_tarea, std::string codigo_encargado);
    virtual ~NodoListaDoble();
};



#endif // NODOLISTADOBLE_H_INCLUDED
