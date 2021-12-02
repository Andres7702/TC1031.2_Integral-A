//Mi programa sera un manejador de grupos escolares.
//Se podran hacer listas de estudiantes que representaran los diferentes grupos de salon.
//Cada estudiante tendra sus propios atributos como nombre, id y grado que estan cursando.
//Cada que se agregue un estudiante se acomodara de manera adecuada dependiendo de su ID.
//En la lista tambien se podran eliminar estudiantes, cambiar datos, entre otras cosas.

//Tambien se puede manejar y ver informacion de los maestros.
//Los maestros se guardaran en una estructura de un Arbol AVL y de igual manera a los estudiantes,
//se puede coonsultar su informacion.


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include "dlist.hpp"
#include "student.hpp"
#include "Calificaciones.hpp"
#include "AVL.hpp"
using std::cerr;
using std::endl;
using std::ofstream;
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
    cout<<"10. Guardar lista en arhivo. \n";
    cout<<"11. PROFE SELECCIONE ESTA: AUTOLLENADO PARA EJEMPLOS. \n";
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
            getline(cin, materia);
            getline(cin, materia);
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
                cout<<Grupos[opcion_grupo]->toString();
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
        //Escribe la informacion de un grupo de estudiantes o de los maestros en un archivo de texto
        else if(opcion == 10){
            
            string imp = "0";
            string file;
            
            int opcion_imprime;
            cout<<"Que vas a imprimir: \n";
            cout<<"1. Grupo de Alumnos \n";
            cout<<"2. Grupo de Maestros \n";
            
            cin>>opcion_imprime;
            cout<<"\n";
            
            if(opcion_imprime == 1){
                int opcion_grupo;
                
                menu_Grupo(size);
                
                cin>>opcion_grupo;
                cout<<"\n";
                if(opcion_grupo < size){
                    imp = Grupos[opcion_grupo]->toString();
                    file = "Alumnos.txt";;
                }
                else{
                    cout<<"Ese Grupo no existe. \n";
                    cout<<"\n";
                
                }
            }
            else if(opcion_imprime == 2){
                imp = Maestros.to_string();
                file = "Maestros .txt";
            }
            else{
                cout<<"Esa opcion no existe. \n";
                cout<<"\n";
            }
            
            if(imp != "0"){
                std::ofstream archivo;

                archivo.open(file);
                if( archivo ) {
                    for (int i = 0; i < imp.size(); ++i)
                    archivo << imp[i];
                    archivo.close();
                    cout << "¡Listo!" << endl;
                    cout << "\n" << endl;
                }
                else{
                    cout << "Error: file could not be opened" << endl;
                }
            }
        }
        //Llenado de listas para ejemplo
        else if(opcion == 11){
            Grupos[size++] = new DList();
            
            Grupos[size-1]->add_student("Andrés Acevedo", 1, 1);
            Grupos[size-1]->update_calificacion(1, 0, 100);
            Grupos[size-1]->update_calificacion(1, 1, 100);
            Grupos[size-1]->update_calificacion(1, 2, 100);
            Grupos[size-1]->update_calificacion(1, 3, 0);
            Grupos[size-1]->update_calificacion(1, 4, 100);
            Grupos[size-1]->update_calificacion(1, 5, 100);
            Grupos[size-1]->update_calificacion(1, 6, 100);
            Grupos[size-1]->update_calificacion(1, 7, 100);
            Grupos[size-1]->add_student("Diego Ramirez", 2, 1);
            Grupos[size-1]->update_calificacion(2, 0, 100);
            Grupos[size-1]->update_calificacion(2, 1, 100);
            Grupos[size-1]->update_calificacion(2, 2, 100);
            Grupos[size-1]->update_calificacion(2, 3, 100);
            Grupos[size-1]->update_calificacion(2, 4, 100);
            Grupos[size-1]->update_calificacion(2, 5, 0);
            Grupos[size-1]->update_calificacion(2, 6, 100);
            Grupos[size-1]->update_calificacion(2, 7, 100);
            Grupos[size-1]->add_student("Renata Medina", 3, 1);
            Grupos[size-1]->update_calificacion(3, 0, 100);
            Grupos[size-1]->update_calificacion(3, 1, 0);
            Grupos[size-1]->update_calificacion(3, 2, 100);
            Grupos[size-1]->update_calificacion(3, 3, 100);
            Grupos[size-1]->update_calificacion(3, 4, 100);
            Grupos[size-1]->update_calificacion(3, 5, 100);
            Grupos[size-1]->update_calificacion(3, 6, 100);
            Grupos[size-1]->update_calificacion(3, 7, 100);
            Grupos[size-1]->add_student("Elian Raya", 4, 1);
            Grupos[size-1]->update_calificacion(4, 0, 100);
            Grupos[size-1]->update_calificacion(4, 1, 100);
            Grupos[size-1]->update_calificacion(4, 2, 100);
            Grupos[size-1]->update_calificacion(4, 3, 100);
            Grupos[size-1]->update_calificacion(4, 4, 100);
            Grupos[size-1]->update_calificacion(4, 5, 100);
            Grupos[size-1]->update_calificacion(4, 6, 100);
            Grupos[size-1]->update_calificacion(4, 7, 0);
            Grupos[size-1]->add_student("Valeria Flores", 5, 1);
            Grupos[size-1]->update_calificacion(5, 0, 100);
            Grupos[size-1]->update_calificacion(5, 1, 100);
            Grupos[size-1]->update_calificacion(5, 2, 100);
            Grupos[size-1]->update_calificacion(5, 3, 100);
            Grupos[size-1]->update_calificacion(5, 4, 100);
            Grupos[size-1]->update_calificacion(5, 5, 0);
            Grupos[size-1]->update_calificacion(5, 6, 100);
            Grupos[size-1]->update_calificacion(5, 7, 100);
            Grupos[size-1]->add_student("Salvador Vivas", 6, 1);
            Grupos[size-1]->update_calificacion(6, 0, 100);
            Grupos[size-1]->update_calificacion(6, 1, 100);
            Grupos[size-1]->update_calificacion(6, 2, 100);
            Grupos[size-1]->update_calificacion(6, 3, 100);
            Grupos[size-1]->update_calificacion(6, 4, 0);
            Grupos[size-1]->update_calificacion(6, 5, 100);
            Grupos[size-1]->update_calificacion(6, 6, 100);
            Grupos[size-1]->update_calificacion(6, 7, 100);
            
            Grupos[size++] = new DList();
            
            Grupos[size-1]->add_student("Alan Razo", 1, 2);
            Grupos[size-1]->update_calificacion(1, 0, 100);
            Grupos[size-1]->update_calificacion(1, 1, 0);
            Grupos[size-1]->update_calificacion(1, 2, 100);
            Grupos[size-1]->update_calificacion(1, 3, 100);
            Grupos[size-1]->update_calificacion(1, 4, 100);
            Grupos[size-1]->update_calificacion(1, 5, 100);
            Grupos[size-1]->update_calificacion(1, 6, 100);
            Grupos[size-1]->update_calificacion(1, 7, 100);
            Grupos[size-1]->add_student("Sebastian Camacho", 2, 2);
            Grupos[size-1]->update_calificacion(2, 0, 100);
            Grupos[size-1]->update_calificacion(2, 1, 100);
            Grupos[size-1]->update_calificacion(2, 2, 100);
            Grupos[size-1]->update_calificacion(2, 3, 100);
            Grupos[size-1]->update_calificacion(2, 4, 100);
            Grupos[size-1]->update_calificacion(2, 5, 100);
            Grupos[size-1]->update_calificacion(2, 6, 100);
            Grupos[size-1]->update_calificacion(2, 7, 0);
            Grupos[size-1]->add_student("Paulina Lopez", 3, 2);
            Grupos[size-1]->update_calificacion(3, 0, 100);
            Grupos[size-1]->update_calificacion(3, 1, 100);
            Grupos[size-1]->update_calificacion(3, 2, 0);
            Grupos[size-1]->update_calificacion(3, 3, 100);
            Grupos[size-1]->update_calificacion(3, 4, 100);
            Grupos[size-1]->update_calificacion(3, 5, 100);
            Grupos[size-1]->update_calificacion(3, 6, 100);
            Grupos[size-1]->update_calificacion(3, 7, 100);
            Grupos[size-1]->add_student("Diego Medina", 4, 2);
            Grupos[size-1]->update_calificacion(4, 0, 100);
            Grupos[size-1]->update_calificacion(4, 1, 100);
            Grupos[size-1]->update_calificacion(4, 2, 100);
            Grupos[size-1]->update_calificacion(4, 3, 100);
            Grupos[size-1]->update_calificacion(4, 4, 100);
            Grupos[size-1]->update_calificacion(4, 5, 100);
            Grupos[size-1]->update_calificacion(4, 6, 0);
            Grupos[size-1]->update_calificacion(4, 7, 100);
            Grupos[size-1]->add_student("Monica Ayala", 5, 2);
            Grupos[size-1]->update_calificacion(5, 0, 100);
            Grupos[size-1]->update_calificacion(5, 1, 100);
            Grupos[size-1]->update_calificacion(5, 2, 100);
            Grupos[size-1]->update_calificacion(5, 3, 0);
            Grupos[size-1]->update_calificacion(5, 4, 100);
            Grupos[size-1]->update_calificacion(5, 5, 100);
            Grupos[size-1]->update_calificacion(5, 6, 100);
            Grupos[size-1]->update_calificacion(5, 7, 100);
            
            Maestros.add("Luis Rios", 1, "1","Matematicas");
            Maestros.add("Benjamin Valdes", 1, "1","Deportes");
            Maestros.add("Erica Ramirez", 1, "1","Español");
            Maestros.add("Victor Rojo", 1, "1","Etica");
            Maestros.add("Ivana Chavez", 1, "1","Deportes");
            
            cout<<"LISTO \n \n";
        }
        else{
            cout<<"Esa opcion no existe. \n";
            cout<<"\n";
        }
    }
}
