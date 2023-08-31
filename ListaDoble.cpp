#include "ListaDoble.h"

ListaDoble::ListaDoble(){
    this->Primero =0;
    this->Tamanio = 0;
}
ListaDoble::~ListaDoble()
{
    //dtor
}

void ListaDoble::Insertar( std::string codigo, std::string nombre_tarea, std::string codigo_encargado){
    NodoListaDoble *nuevo = new NodoListaDoble(codigo, nombre_tarea, codigo_encargado);
    if(this->Primero==0){
        this->Primero = nuevo;
        this->Tamanio++;
    }else{
        NodoListaDoble *aux = this->Primero;
        while(aux->Siguiente){
            aux = aux->Siguiente;
            cout<<"TAREA CREADA CORRECTAMENTE"<<endl;
        }
        nuevo->Anterior = aux;
        aux->Siguiente = nuevo;
        this->Tamanio++;
        cout<<"TAREA CREADA CORRECTAMENTE"<<endl;
    }
}

void ListaDoble::Asignar(std::string codigo, std::string nombre_tarea, std::string encargado){
    if(this->Primero){
        NodoListaDoble *aux= this->Primero;
        while(aux){
            if(aux->Codigo.compare(codigo)==0 && aux->Nombre_Tarea.compare(nombre_tarea)==0){
                aux->Codigo_Encargado = encargado;
                cout<<"TAREA ASIGNADA CORRECTAMENTE"<<endl;
                break;
            }
            aux = aux->Siguiente;
        }
    }
}

void ListaDoble::Mostrar_Tareas(std::string codigo){
    NodoListaDoble *aux = this->Primero;
    bool encontrado = false;
    while (aux) {
        if (aux->Codigo.compare(codigo) == 0) {
            std::cout << "Nombre de tarea: " << aux->Nombre_Tarea << std::endl;
            encontrado = true;
        }
        aux = aux->Siguiente;
    }

    if (!encontrado) {
        std::cout << "No se encontraron tareas para el proyecto con código " << codigo << std::endl;
    }
}

void ListaDoble::Imprimir_Proyectos(){
    std::set<std::string> codigos_proyectos;

    NodoListaDoble *aux = this->Primero;
    while (aux) {
        codigos_proyectos.insert(aux->Codigo);
        aux = aux->Siguiente;
    }

    for (const std::string &codigo : codigos_proyectos) {
        std::cout << "Codigo: " << codigo << std::endl;
    }
}

void ListaDoble::Generar_Grafico(){
    std::ofstream archivoDot("lista_doble.dot");

    if (archivoDot.is_open()) {
        archivoDot << "digraph ListaDoble {" << std::endl;

        NodoListaDoble *current = this->Primero;
        while (current) {
            archivoDot << "    \"" << current->Codigo << "\" [label=\"Codigo: " << current->Codigo << "\\nTarea: " << current->Nombre_Tarea << "\"];" << std::endl;

            if (current->Anterior) {
                archivoDot << "    \"" << current->Anterior->Codigo << "\" -> \"" << current->Codigo << "\";" << std::endl;
            }

            current = current->Siguiente;
        }

        archivoDot << "}" << std::endl;
        archivoDot.close();

        system("dot -Tpng lista_doble.dot -o lista_doble.png");
        std::cout << "Imagen generada y guardada en lista_doble.png" << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo DOT" << std::endl;
    }
}
