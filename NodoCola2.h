#ifndef NODOCOLA2_H_INCLUDED
#define NODOCOLA2_H_INCLUDED

#include "Proyecto.h"

class NodoCola2{
public:
    NodoCola2 *Siguiente;
    Proyecto *Proyecto_C;
    std::string Prioridad;
    NodoCola2(Proyecto *nuevoProyecto, std::string prioridad);
    virtual ~NodoCola2();

};


#endif // NODOCOLA2_H_INCLUDED
