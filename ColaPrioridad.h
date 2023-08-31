#ifndef COLAPRIORIDAD_H_INCLUDED
#define COLAPRIORIDAD_H_INCLUDED
#include "NodoCola.h"
#include "Proyecto.h"
#include <string>
#include <iostream>
using namespace std;

class ColaPrioridad{
public:
    NodoCola *Primero;
    int Tamanio;
    void Encolar(std::string nombre, std::string Tipo_Prioridad);
    void Desencolar();
    void VerProyectos();
    ColaPrioridad();
    virtual ~ColaPrioridad();
};


#endif // COLAPRIORIDAD_H_INCLUDED
