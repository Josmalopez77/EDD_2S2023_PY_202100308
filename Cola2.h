#ifndef COLA2_H_INCLUDED
#define COLA2_H_INCLUDED
#include <vector>
#include <algorithm>
#include <fstream>
#include "NodoCola2.h"
#include "Proyecto.h"
#include <string>
#include <iostream>
using namespace std;

class Cola2{
public:
    NodoCola2 *Primero;
    int Tamanio;
    void Encolar(std::string nombre, std::string Tipo_Prioridad);
    void VerProyectos();
    void Generar_Grafico();
    Cola2();
    virtual ~Cola2();
};



#endif // COLA2_H_INCLUDED
