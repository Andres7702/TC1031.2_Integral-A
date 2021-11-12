//Mi programa sera un manejador de grupos escolares.
//Se podran hacer listas de estudiantes que representaran los diferentes grupos de salon.
//Cada estudiante tendra sus propios atributos como nombre, id y grado que estan cursando.
//Cada que se agregue un estudiante se acomodara de manera adecuada dependiendo de su ID.
//En la lista tambien se podran eliminar estudiantes, cambiar datos, entre otras cosas.

//Tambien se puede manejar y ver informacion de los maestros.
//Los maestros se guardaran en una estructura de un Arbol AVL y de igual manera a los estudiantes,
//se puede coonsultar su informacion.


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include "dlist.hpp"
#include "student.hpp"
#include "Calificaciones.hpp"
#include "AVL.hpp"

using namespace std;


void menu_principal(){
    cout<<"0. Crear un grupo de estudiantes nuevo. \n";
    cout<<"1. Agregar estudiante a grupo. \n";
    cout<<"2. Agregar maestro. \n";
    cout<<"3. Ver estudiantes de un grupo. \n";
    cout<<"4. Ver todos los maestros. \n";
    cout<<"5. Buscar Estudiante. \n";
    cout<<"6. Buscar Maestro. \n";
    cout<<"7. Modificar Calificaciones. \n";
    cout<<"8. Eliminar Estudiante. \n";
    cout<<"9. Eliminar Maestro. \n";
    cout<<"\n";
}

void menu_Grupo(int s){
    cout<<"Seleccione un Grupo: \n";
    for(int i = 0; i < s; i++){
        cout<<i<<". "<<"Grupo "<<i<<"\n";
    }
}

void menu_calificaciones(){
    cout<<"0. Matematicas \n";
    cout<<"1. Fisica \n";
    cout<<"2. Biologia \n";
    cout<<"3. Quimica \n";
    cout<<"4. Ingles \n";
    cout<<"5 Español \n";
    cout<<"6. Etica \n";
    cout<<"7. Deportes \n";
}


int main() {
    
    //Creacion de lista de grupos y arbol Avl de maestros"
    DList *Grupos[10];
    AVL Maestros;
    
    bool cont = true;
    int size = 0;

    while(cont){
        int opcion;
        menu_principal();
        cin>>opcion;
        cout<<"\n";
        
        //CREA GRUPO NUEVO
        if(opcion == 0){
            Grupos[size++] = new DList();
            cout<<"Listo \n";
            cout<<"\n";
        }
        //AGREGA ESTUDIANTE A GRUPO
        else if(opcion == 1){
            
            bool cont = true;
            
            int opcion_grupo;
            string nombre;
            int ID;
            int grado;
            
            menu_Grupo(size);
            
            cin>>opcion_grupo;
            cout<<"\n";
            if(opcion_grupo < size){
                cout<<"Introduce Nombre Completo: \n";
                getline(cin, nombre);
                getline(cin, nombre);
                cout<<"Introuduce ID: \n";
                cin>>ID;
                cout<<"Introduce Grado: \n";
                cin>>grado;
                cout<<"Listo! \n \n";
                
                while(cont){
                    if (Grupos[opcion_grupo]->find(ID)) {
                        ID++;
                    }
                    else{
                        cont = false;
                    }
                }
                
                Grupos[opcion_grupo]->add_student(nombre, ID, grado);
            }
            else{
                cout<<"Ese Grupo no existe. \n";
                cout<<"\n";
            }
        }
        //AGREGA MAESTRO
        else if(opcion == 2){
            string nombre;
            int ID;
            string materia;
            string grado;
            
            cout<<"\n";
            cout<<"Introduce Nombre Completo: \n";
            getline(cin, nombre);
            getline(cin, nombre);
            cout<<"Introuduce ID: \n";
            cin>>ID;
            cout<<"Introduce Materia que enseña: \n";
            getline(cin, nombre);
            getline(cin, nombre);
            cout<<"Introduce Grado que enseña. \n";
            getline(cin, grado);
            cout<<"Listo \n \n";
            Maestros.add(nombre, ID, grado, materia);
        }
        //IMPRIME LISTA DE ESTUDIANTES DE UN SOLO GRUPO
        else if(opcion == 3){
            int opcion_grupo;
            
            menu_Grupo(size);
            
            cin>>opcion_grupo;
            cout<<"\n";
            if(opcion_grupo < size){
                Grupos[opcion_grupo]->toString();
                cout<<"\n";
                cout<<"\n";
            }
            else{
                cout<<"Ese Grupo no existe. \n";
                cout<<"\n";
            
            }
        }
        //IMPRIME MAESTROS
        else if(opcion == 4){
            cout<<"\n";
            cout<<Maestros.to_string();
            cout<<"\n";
            cout<<"\n";
        }
        //IMPRIME INFORMACION DE ESTUDIANTE CONSULTADO
        else if(opcion == 5){
            int opcion_grupo;
            
            menu_Grupo(size);
            
            cin>>opcion_grupo;
            cout<<"\n";
            if(opcion_grupo < size){
                
                int opcion_ID;
                cout<<"Introduce el ID del estudiante. \n";
                cin>>opcion_ID;
                
                Grupos[opcion_grupo]->check_info(opcion_ID);
                cout<<"\n";
                cout<<"\n";
            }
            else{
                cout<<"Ese Grupo no existe. \n";
                cout<<"\n";
            
            }
        }
        //IMRPIME INFORMACION DE MAESTRO CONSULTADO
        else if(opcion == 6){
            int opcion_ID;
            cout<<"Introduce el ID del maestro. \n";
            cin>>opcion_ID;
            
            cout<<Maestros.check_info(opcion_ID);
            cout<<"\n";
            cout<<"\n";
        }
        //MODIFICA CALIFICACION DE ESTUDIANTE SELECCIONADO
        else if(opcion == 7){
            int opcion_grupo;
            int opcion_materia;
            int ID;
            double calif;
            bool cont = true;
            
            menu_Grupo(size);
            
            cin>>opcion_grupo;
            cout<<"\n";
            if(opcion_grupo < size){
                cout<<"Introduce ID de estudiante: \n";
                cin>>ID;
                cout<<"\n";
                while(cont){
                    int opcion_continuar;
                    menu_calificaciones();
                    cout<<"\n";
                    cout<<"Introduce Numero de Materia: \n";
                    cin>>opcion_materia;
                    cout<<"Introduce Calificacion: \n";
                    cin>>calif;
                    cout<<"\n";
                    Grupos[opcion_grupo]->update_calificacion(ID, opcion_materia, calif);
                    cout<<"Deasea modificar otra calificacion? \n";
                    cout<<"1. Si \n";
                    cout<<"2. No \n";
                    cin>>opcion_continuar;
                    cout<<"\n";
                    if(opcion_continuar == 1){
                        cont = true;
                    }
                    else{
                        cont = false;
                    }
                }
            }
            else{
                cout<<"Ese Grupo no existe. \n";
                cout<<"\n";
            }
        }
        //ELIMINA ESTUDIANTE DE UN GRUPO
        else if(opcion == 8){
            
            int opcion_grupo;
            int ID;
            
            menu_Grupo(size);
            
            cin>>opcion_grupo;
            cout<<"\n";
            if(opcion_grupo < size){
                cout<<"Introduce ID de estudiante: \n";
                cin>>ID;
                cout<<"\n";
                if(Grupos[opcion_grupo]->find(ID)){
                    Grupos[opcion_grupo]->deleteAt(ID);
                }
                else{
                    cout<<"Ese estudiante no existe \n";
                    cout<<"\n";
                }
            }
            else{
                cout<<"Ese Grupo no existe. \n";
                cout<<"\n";
            }
        }
        //ELIMINA MAESTRA DE ARBOL
        else if(opcion == 9){
            int ID;
            cout<<"Introduce ID de profesor: \n";
            cin>>ID;
            cout<<"\n";
            if(Maestros.find(ID)){
                Maestros.remove(ID);
                cout<<"Listo! \n ";
                cout<<"\n";
            }
            else{
                cout<<"Ese maestro no existe. \n ";
                cout<<"\n";
            }
        }
        else{
            cout<<"Esa opcion no existe. \n";
            cout<<"\n";
        }
    
    }
}
