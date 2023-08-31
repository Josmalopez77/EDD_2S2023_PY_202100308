#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED
#include <string>

using namespace std;

class Proyecto{
public:
    std::string Nombre;
    std::string Codigo;
    Proyecto(std::string codigo, std::string nombre);
    virtual ~Proyecto();
};


#endif // PROYECTO_H_INCLUDED
