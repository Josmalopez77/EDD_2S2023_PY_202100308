#include "ListaEmpleados.h"
#include <iostream>

ListaEmpleados::ListaEmpleados() : primero(nullptr), ultimo(nullptr) {}

void ListaEmpleados::agregar_empleado(int codigo, const std::string& nombre, const std::string& password, const std::string& tipo) {
    Empleado* nuevo_empleado = new Empleado(codigo, nombre, password, tipo);
    if (!primero) {
        primero = nuevo_empleado;
        ultimo = nuevo_empleado;
    } else {
        nuevo_empleado->siguiente = primero;
        nuevo_empleado->anterior = ultimo;
        ultimo->siguiente = nuevo_empleado;
        primero->anterior = nuevo_empleado;
        ultimo = nuevo_empleado;
    }
}

void ListaEmpleados::mostrar_empleados() {
    if (!primero) {
        std::cout << "La lista de empleados está vacía." << std::endl;
        return;
    }

    Empleado* actual = primero;
    do {
        std::cout << "Código: " << actual->codigo << ", Nombre: " << actual->nombre
                  << ", Tipo: " << actual->tipo << std::endl;
        actual = actual->siguiente;
    } while (actual != primero);
}

ListaEmpleados::~ListaEmpleados() {
    Empleado* actual = primero;
    while (actual) {
        Empleado* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
        if (actual == primero) {
            break;
        }
    }
}
