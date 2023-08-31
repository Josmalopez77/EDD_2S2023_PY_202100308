#include <iostream>
#include <string>
#include "Lista.h"
#include "ColaPrioridad.h"
#include "Matriz.h"
#include "Cola2.h"
#include "ListaDoble.h"

using namespace std;

int main(){
    Lista *lista = new Lista();
    ListaDoble *listaDoble = new ListaDoble();
    ColaPrioridad *cola = new ColaPrioridad();
    Cola2 *cola2 = new Cola2();
    Matriz *matriz = new Matriz();
    bool OMaster = true;
    string user, pass;
    while(OMaster){
    cout<<"********** EDD ProjectUp **********"<<endl;
    cout<<"usuario: ";
    cin>> user;
    cout<<"Passwrod: ";
    cin>> pass;

    if(user == "Jose" && pass == "Jose"){
        bool MAdmin = true;
        while(MAdmin){
            int OAdmin;
            cout<<"********** EDD ProjectUp **********"<<endl;
            cout<<"**********   Bienvenido "<<user<<" **********"<<endl;
            cout<<"1. Cargar Empleados"<<endl;
            cout<<"2. Crear Proyecto"<<endl;
            cout<<"3. Asignar Proyecto"<<endl;
            cout<<"4. Crear Tarea"<<endl;
            cout<<"5. Asignar Tareas"<<endl;
            cout<<"6. Graficar Matriz"<<endl;
            cout<<"7. Graficar Cola"<<endl;
            cout<<"8. Graficar Lista Circular"<<endl;
            cout<<"9. Graficar Lista Doble"<<endl;
            cout<<"10. Generar JSON"<<endl;
            cout<<"11. Salir"<<endl;
            cin>> OAdmin;

            //***********MENU CARGA DE EMPLEADOS ****************
            if(OAdmin == 1){
                bool MCE = true;
                int OMCE;
                while(MCE){
                    string nombre, pass;
                    int puesto;
                    cout<<"********** EDD ProjectUp **********"<<endl;
                    cout<<"**********    Bienvenido "<<user<<" **********"<<endl;
                    cout<<"********Menu Carga de Empleados *******"<<endl;
                    cout<<"1. Carga Manual"<<endl;
                    cout<<"2. Crear Masiva"<<endl;
                    cout<<"3. Salir"<<endl;
                    cin>>OMCE;
                    // MENU AGREGAR MANUALMENTE TRABAJADORES
                    if(OMCE == 1){
                        cout<<"Nombre: ";
                        getline(cin >> ws,nombre);
                        cout<<"Password: ";
                        getline(cin >> ws,pass);
                        if(puesto>3){
                            cout<<"Selecciona un puesto valido"<<endl;
                        }else{
                        lista->Insertar(nombre,pass);
                        lista->VerLista();
                        cout<<"Trabajador Registrado Exitosamente"<<endl;
                        cout<< nombre<<pass<<puesto<<endl;
                        }
                    }else if(OMCE == 2){
                        string nameFile;
                        cout<<"Escribe el nombre de tu archivo"<<endl;
                        cin>> nameFile;
                        lista->LeerArchivo(nameFile);
                        lista->VerLista();

                    }

                    if(OMCE == 3){
                        MCE = false;
                    }
                }
                // ******** MENU CREAR PROYECTO *******
            }else if(OAdmin == 2){
                    string nombre, tipo;
                    cout<<"********** EDD ProjectUp **********"<<endl;
                    cout<<"**********    Bienvenido "<<user<<" **********"<<endl;
                    cout<<"********Menu DE PROYECTO *******"<<endl;
                    cout<<"Nombre de Proyecto: ";
                    cin >> nombre;
                    cout<<"Tipo de Prioridad: ";
                    cin >> tipo;
                    cola->Encolar(nombre, tipo);
                    cola2->Encolar(nombre, tipo);
                    cola->VerProyectos();
            }else if(OAdmin == 3){
                    string name, code;
                    cout<<"********** EDD ProjectUp **********"<<endl;
                    cout<<"**********    Bienvenido "<<user<<" **********"<<endl;
                    cout<<"********Menu DE Asignar Proyecto *******"<<endl;

                    cout<<"Seleccione el nombre del empleado: "<<endl;
                    lista->VerLista();
                    getline(cin >> ws,name);
                    cout<<"Seleccione el codigo del proyecto: "<<endl;
                    cola2->VerProyectos();
                    getline(cin >> ws,code);
                    matriz->asignarProyecto(name, code);

            }else if(OAdmin == 4){
                    string nombre_tarea, codigo_tarea;
                    cout<<"********** EDD ProjectUp **********"<<endl;
                    cout<<"**********    Bienvenido "<<user<<" **********"<<endl;
                    cout<<"********Menu DE Crear Tareas *******"<<endl;

                    cola2->VerProyectos();
                    cout<<"Seleccione el codigo del proyecto: "<<endl;
                    cin>> codigo_tarea;
                    cout<<"Ingrese el nombre de la tarea: "<<endl;
                    cin>> nombre_tarea;
                    listaDoble->Insertar(codigo_tarea, nombre_tarea,"");
                    matriz->Insertar_Tareas(listaDoble);
                    cout<<"Tarea Creada Correctamente"<<endl;
                    matriz->Tareas->Mostrar_Tareas(codigo_tarea);

            }else if(OAdmin == 5){
                    string codigo_proyecto, codigo_tarea, empleados;
                    cout<<"********** EDD ProjectUp **********"<<endl;
                    cout<<"**********    Bienvenido "<<user<<" **********"<<endl;
                    cout<<"********Menu De Asignar Tareas *******"<<endl;

                    cout<<"Seleccione el codigo del proyecto: "<<endl;
                    listaDoble->Imprimir_Proyectos();
                    cin>>codigo_proyecto;

                    cout<<"Seleccione el nombre de la tarea: "<<endl;
                    listaDoble->Mostrar_Tareas(codigo_proyecto);
                    cin>>codigo_tarea;

                    cout<<"Seleccione el nombre del empleado: "<<endl;
                    lista->VerLista();
                    getline(cin >> ws,empleados);

                    listaDoble->Asignar(codigo_proyecto, codigo_tarea, empleados);

            }else if(OAdmin == 6){
                    matriz->Graficar();
            }else if(OAdmin == 0){
                    cout<<"OKKKKKKKKKKKKKKK"<<endl;
                     while(cola->Primero)
    {
        matriz->insertar_proyecto(cola);
        cola->Desencolar();
    }
                    cola->VerProyectos();
                    matriz->insertar_empleado(lista);
            }else if(OAdmin == 7){
                    cola2->VerProyectos();
                    cola2->Generar_Grafico();

            }else if(OAdmin == 8){
                    lista->Graficar_Lista();
            }else if(OAdmin == 9){
                    listaDoble->Generar_Grafico();
            }else if(OAdmin == 10){
                    matriz->Generar_JSON(cola2);
            }
                else if(OAdmin == 11){
                MAdmin = false;
                OMaster = false;
            }else{
                cout<<"Seleccione una opcion valida"<<endl;
            }
        }
    }else{
        cout<<"No Aceptado";
    }
    }

    return 0;
}

