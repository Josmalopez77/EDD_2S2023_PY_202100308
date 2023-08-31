#include "Lista.h"
#include <iostream>

using namespace std;

Lista::Lista(){
    this->Primero = 0;
    this->Tamanio = 0;
}
Lista::~Lista()
{
    //destructor
}


void Lista::Insertar(std::string nombre, std::string password)
{
    NodoLista *nuevo = new NodoLista(nombre, password);
    int numero_empleado = 1 + this->Tamanio;
    std::string codigo = (numero_empleado < 100 ? (numero_empleado < 10 ? "SC-00"+std::to_string(numero_empleado) : "SC-0"+std::to_string(numero_empleado)): "SC-"+std::to_string(numero_empleado));
    nuevo->EmpleadoSistema->Codigo = codigo;
    if(this->Primero == 0)
    {

        nuevo->Anterior = nuevo;
        nuevo->Siguiente = nuevo;
        /*Nos volamos esto*/
        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoLista *aux = this->Primero;
        int contador = 1;
        while(this->Tamanio > contador)
        {
            aux = aux->Siguiente;
            contador++;
        }
        nuevo->Anterior = aux;
        nuevo->Siguiente = this->Primero;//No existe en doble enlazada
        aux->Siguiente = nuevo;
        this->Primero->Anterior = nuevo; //No exites ne doble enlazada
        this->Tamanio++;
    }
}

void Lista::VerLista()
{
    NodoLista *aux = this->Primero;
    int contador = 0;
    while(this->Tamanio > contador)
    {
        cout<< aux->EmpleadoSistema->Codigo << endl;
        cout<< aux->EmpleadoSistema->Nombre << endl;
        cout<< aux->EmpleadoSistema->Password << endl;
        cout<< aux->EmpleadoSistema->Puesto << endl;
        aux = aux->Siguiente;
        contador++;
    }
}

void Lista::LeerArchivo(std::string nombre_archivo)
{
    try
    {
        ifstream lectura;
        lectura.open(nombre_archivo, ios::in);
        bool encabezado = false;
        for(std::string fila; std::getline(lectura,fila);)
        {
            std::stringstream lineas(fila);
            std::string nombre;
            std::string password;
            if(encabezado)
            {
                getline(lineas, nombre, ',');
                getline(lineas, password, ',');
                this->Insertar(nombre, password);
            }
            else{
                encabezado = true;
            }

        }
    }
    catch(exception)
    {
        cout << "No se pudo leer el archivo" << endl;
    }
}

void Lista::Graficar_Lista(){
    std::ofstream archivoDot("lista.dot");
    if (!archivoDot.is_open()) {
        std::cout << "No se pudo crear el archivo DOT." << std::endl;
        return;
    }

    archivoDot << "digraph ListaCircular {" << std::endl;
    archivoDot << "rankdir=LR;" << std::endl;

    NodoLista* aux = this->Primero;
    int contador = 0;
    while (this->Tamanio > contador) {
        archivoDot << "    \"" << aux->EmpleadoSistema->Nombre << "\";" << std::endl;
        aux = aux->Siguiente;
        contador++;
    }

    // Conectar los nodos en un ciclo cerrado.
    aux = this->Primero;
    contador = 0;
    while (this->Tamanio > contador) {
        archivoDot << "    \"" << aux->EmpleadoSistema->Nombre << "\" -> ";
        archivoDot << "\"" << aux->Siguiente->EmpleadoSistema->Nombre << "\";" << std::endl;
        aux = aux->Siguiente;
        contador++;
    }

    archivoDot << "}" << std::endl;
    archivoDot.close();

    // Ejecutar Graphviz para generar la imagen.
    std::system("dot -Tpng lista.dot -o lista.png");
    std::cout << "Imagen generada como lista.png" << std::endl;
}
