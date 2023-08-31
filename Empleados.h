#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

#include <string>
using namespace std;

class Empleado
{
    public:
        std::string Nombre;
        std::string Password;
        std::string Codigo;
        std::string Puesto;
        Empleado(std::string nombre, std::string password);
        virtual ~Empleado();


};



#endif // EMPLEADOS_H_INCLUDED
