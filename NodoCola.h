#ifndef NODOCOLA_H_INCLUDED
#define NODOCOLA_H_INCLUDED
#include "Proyecto.h"

class NodoCola{
public:
    NodoCola *Siguiente;
    Proyecto *Proyecto_C;
    std::string Prioridad;
    NodoCola(Proyecto *nuevoProyecto, std::string prioridad);
    virtual ~NodoCola();

};


#endif // NODOCOLA_H_INCLUDED
