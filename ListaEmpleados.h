#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H

#include "Empleado.h"

class ListaEmpleados {
private:
    Empleado* primero;
    Empleado* ultimo;

public:
    ListaEmpleados();
    ~ListaEmpleados();

    void agregar_empleado(int codigo, const std::string& nombre, const std::string& password, const std::string& tipo);
    void mostrar_empleados();
};

#endif // LISTAEMPLEADOS_H
