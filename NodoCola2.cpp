#include "NodoCola2.h"

NodoCola2::NodoCola2(Proyecto *nuevoProyecto, std::string prioridad){
    this->Siguiente = 0;
    this->Proyecto_C = nuevoProyecto;
    this->Prioridad = prioridad;
}
NodoCola2::~NodoCola2(){
//Destructor
}
