#ifndef TAREA_H_INCLUDED
#define TAREA_H_INCLUDED
#include <string>

using namespace std;

class Tarea{
public:
    std::string Codigo;
    std::string Nombre;
    Tarea(std::string id, std::string nombre);
    virtual ~Tarea();
};


#endif // TAREA_H_INCLUDED
