#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include "NodoListaDoble.h"
#include <string>
#include <iostream>
#include <set>
#include <fstream>

using namespace std;

class ListaDoble{
public:
    NodoListaDoble *Primero;
    int Tamanio;
    void Insertar(std::string codigo, std::string nombre_tarea, std::string codigo_encargado);
    void Asignar(std::string codigo, std::string nombre_tarea, std::string encargado);
    void Mostrar_Tareas(std::string codigo);
    void Imprimir_Proyectos();
    void Generar_Grafico();
    ListaDoble();
    virtual ~ListaDoble();
};



#endif // LISTADOBLE_H_INCLUDED
