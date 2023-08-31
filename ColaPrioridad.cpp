#include "ColaPrioridad.h"

ColaPrioridad::ColaPrioridad(){
    this->Primero = 0;
    this->Tamanio = 0;
}

ColaPrioridad::~ColaPrioridad()
{
    //dtor
}

void ColaPrioridad::Encolar(std::string Nombre, std::string Tipo_Prioridad){
    int numero_proyecto = 100 + this->Tamanio;
    Proyecto *nuevoProyecto = new Proyecto("PY-"+std::to_string(numero_proyecto),Nombre);
    NodoCola *nuevoNodo = new NodoCola(nuevoProyecto, Tipo_Prioridad);
    if(this->Primero==0){
        this->Primero = nuevoNodo;
        this->Tamanio++;
    }else{
        NodoCola *aux = this->Primero;
        while(aux->Siguiente){
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevoNodo;
        this->Tamanio++;
    }
}

void ColaPrioridad::VerProyectos(){
    NodoCola *aux = this->Primero;
    int contador = 0;
    while(aux){
        cout<< aux->Proyecto_C->Codigo <<endl;
        cout<< aux->Proyecto_C->Nombre <<endl;
        aux = aux->Siguiente;
        contador++;
    }
}

void ColaPrioridad::Desencolar(){
    if(this->Primero){
        this->Primero = this->Primero->Siguiente;
    }
}
