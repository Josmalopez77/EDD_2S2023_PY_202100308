#include "Cola2.h"

Cola2::Cola2(){
    this->Primero = 0;
    this->Tamanio = 0;
}

Cola2::~Cola2()
{
    //dtor
}

void Cola2::Encolar(std::string Nombre, std::string Tipo_Prioridad){
    int numero_proyecto = 100 + this->Tamanio;
    Proyecto *nuevoProyecto = new Proyecto("PY-"+std::to_string(numero_proyecto),Nombre);
    NodoCola2 *nuevoNodo = new NodoCola2(nuevoProyecto, Tipo_Prioridad);
    if(this->Primero==0){
        this->Primero = nuevoNodo;
        this->Tamanio++;
    }else{
        NodoCola2 *aux = this->Primero;
        while(aux->Siguiente){
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevoNodo;
        this->Tamanio++;
    }
}

void Cola2::VerProyectos(){
    NodoCola2 *aux = this->Primero;
    int contador = 0;
    while(aux){
        cout<< aux->Proyecto_C->Codigo <<endl;
        cout<< aux->Proyecto_C->Nombre <<endl;
        cout<< aux->Prioridad<<endl;
        aux = aux->Siguiente;
        contador++;
    }
}

void Cola2::Generar_Grafico(){
std::ofstream archivoDot("cola_prioridad.dot");

    if (archivoDot.is_open()) {
        archivoDot << "digraph G {\n";
        archivoDot << "rankdir=LR;\n"; // Cambia la dirección de la disposición a izquierda-derecha

        NodoCola2 *aux = this->Primero;
        std::vector<NodoCola2*> prioridadA, prioridadB, prioridadC;

        // Clasificar y ordenar los proyectos según su prioridad
        while (aux) {
            if (aux->Prioridad == "A") {
                prioridadA.push_back(aux);
            } else if (aux->Prioridad == "B") {
                prioridadB.push_back(aux);
            } else if (aux->Prioridad == "C") {
                prioridadC.push_back(aux);
            }
            aux = aux->Siguiente;
        }

        auto cmp = [](const NodoCola2 *a, const NodoCola2 *b) {
            return a->Proyecto_C->Codigo < b->Proyecto_C->Codigo;
        };
        std::sort(prioridadA.begin(), prioridadA.end(), cmp);
        std::sort(prioridadB.begin(), prioridadB.end(), cmp);
        std::sort(prioridadC.begin(), prioridadC.end(), cmp);

        // Combinar todos los proyectos en un solo vector en el orden deseado
        std::vector<NodoCola2*> proyectos;
        proyectos.insert(proyectos.end(), prioridadA.begin(), prioridadA.end());
        proyectos.insert(proyectos.end(), prioridadB.begin(), prioridadB.end());
        proyectos.insert(proyectos.end(), prioridadC.begin(), prioridadC.end());

        // Generar los nodos en el gráfico
        for (NodoCola2 *nodo : proyectos) {
            archivoDot << "  \"" << nodo->Proyecto_C->Codigo << "\" [label=\"" << nodo->Proyecto_C->Codigo << "\\n" << nodo->Proyecto_C->Nombre << "\", shape=box];\n";
        }

        // Generar conexiones entre los nodos en el gráfico
        for (size_t i = 0; i < proyectos.size() - 1; ++i) {
            archivoDot << "  \"" << proyectos[i]->Proyecto_C->Codigo << "\" -> \"" << proyectos[i + 1]->Proyecto_C->Codigo << "\";\n";
        }

        archivoDot << "}\n";
        archivoDot.close();

        // Generar la imagen usando Graphviz
        system("dot -Tjpg cola_prioridad.dot -o cola_prioridad.jpg");
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir el gráfico." << std::endl;
    }
}

