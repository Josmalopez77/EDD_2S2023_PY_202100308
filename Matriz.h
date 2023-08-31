#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "NodoMatriz.h"
#include "NodoLista.h"
#include "ColaPrioridad.h"
#include "Proyecto.h"
#include "Empleados.h"
#include "Lista.h"
#include "Cola2.h"
#include "json.hpp"


using json= nlohmann::json;

using namespace std;

class Matriz{
public:
    NodoMatriz *Raiz;
    int CoordenadaX;
    int CoordenadaY;
    void insertar_elemento(std::string proyecto, std::string encargado, int x, int y);
    NodoMatriz *nueva_columna(int x);
    NodoMatriz *nueva_fila(int y);
    NodoMatriz *insertar_fila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila);
    NodoMatriz *insertar_columna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna);
    NodoMatriz *buscarF(int y);
    NodoMatriz *buscarC(int x);
    ListaDoble *Tareas;
    void Graficar();
    void insertar_proyecto(ColaPrioridad *cola);
    void insertar_empleado(Lista *lista);
    NodoMatriz *nueva_columna_1(int x, Proyecto *proyecto);
    NodoMatriz *nueva_fila_1(int y, Empleado *empleado);
    void asignarProyecto(std::string nombre_empleado, std::string codigo_proyecto);
    NodoMatriz *buscarF_1(std::string nombre);
    NodoMatriz *buscarC_1(std::string codigo);
    void Insertar_Tareas(ListaDoble *Tareas);
    void Generar_JSON(Cola2 *cola);
    Matriz();
    virtual ~Matriz();
};


#endif // MATRIZ_H_INCLUDED
