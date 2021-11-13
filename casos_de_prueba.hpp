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

void casos_de_prueba(){
    
    //Creacion de lista "Grupo"
    DList Grupo;
    
    //Se agregan estudiantes a la lista con ID desordenados.
    //Esto para demostrar que la lista los acomoda en orden de manera automatica.
    
    cout<<"\n";
    cout<<"\n";
    cout<<"EJEMPLO 1";
    cout<<"\n";
    Grupo.add_student("Diego", 2, 1);
    Grupo.add_student("Monica", 3, 1);
    Grupo.add_student("Elian", 1, 1);
    Grupo.add_student("Valeria", 7, 1);
    Grupo.add_student("Sebastian", 5, 1);
    Grupo.add_student("Salvador", 4, 1);
    Grupo.add_student("Pablo", 6, 1);
    Grupo.toString();
    
    
    //se elimina Diego, Pablo y Monica de la lista.
    cout<<"\n";
    cout<<"\n";
    cout<<"EJEMPLO 2";
    cout<<"\n";
    Grupo.deleteAt(2);
    Grupo.deleteAt(6);
    Grupo.deleteAt(3);
    Grupo.toString();
    
    
    //Se agregan Calificaciones a estudiantes.
    
    cout<<"\n";
    cout<<"\n";
    cout<<"EJEMPLO 3";
    cout<<"\n";
    
    Grupo.update_calificacion(1,0,100);
    Grupo.update_calificacion(1,1,90);
    Grupo.update_calificacion(1,2,85);
    Grupo.update_calificacion(1,3,40);
    Grupo.update_calificacion(1,4,70);
    Grupo.update_calificacion(1,5,73);
    Grupo.update_calificacion(1,6,87);
    Grupo.update_calificacion(1,7,100);
    
    Grupo.update_calificacion(4,0,02);
    Grupo.update_calificacion(4,1,80);
    Grupo.update_calificacion(4,2,77);
    Grupo.update_calificacion(4,3,90);
    Grupo.update_calificacion(4,4,93);
    Grupo.update_calificacion(4,5,63);
    Grupo.update_calificacion(4,6,78);
    Grupo.update_calificacion(4,7,99);
    
    
    Grupo.update_calificacion(5,0,70);
    Grupo.update_calificacion(5,1,89);
    Grupo.update_calificacion(5,2,66);
    Grupo.update_calificacion(5,3,79);
    Grupo.update_calificacion(5,4,70);
    Grupo.update_calificacion(5,5,77);
    Grupo.update_calificacion(5,6,69);
    Grupo.update_calificacion(5,7,0);
    
    Grupo.update_calificacion(7,0,55);
    Grupo.update_calificacion(7,1,67);
    Grupo.update_calificacion(7,2,89);
    Grupo.update_calificacion(7,3,48);
    Grupo.update_calificacion(7,4,59);
    Grupo.update_calificacion(7,5,22);
    Grupo.update_calificacion(7,6,88);
    Grupo.update_calificacion(7,7,100);
    
    Grupo.toString();
    
    //Imprimimos informacion de un solo estudiante (Valeria ID 7)
    cout<<"\n";
    cout<<"\n";
    cout<<"EJEMPLO 4";
    cout<<"\n";
    Grupo.check_info(7);
    
    //Creamos Arbol AVL de Maestros y lo llenamos.
    
    AVL Maestros;
    
    cout<<"\n";
    cout<<"\n";
    cout<<"EJEMPLO 5";
    cout<<"\n";
    
    Maestros.add("Luis",1,"1","Matematicas");
    Maestros.add("Jaime",4,"1","Deportes");
    Maestros.add("Rosa", 3, "1", "Fisica");
    Maestros.add("Liliana",1,"1","Matematicas");
    cout<<Maestros.to_string();
    
    //Borramos maestros de arbol;
    
    cout<<"\n";
    cout<<"\n";
    cout<<"EJEMPLO 6";
    cout<<"\n";
    
    Maestros.remove(1);
    Maestros.remove(2);
    
    cout<<Maestros.to_string();
    
    //Imprimimos informacion de un solo maestro (Rosa ID 3)
    
    cout<<"\n";
    cout<<"\n";
    cout<<"EJEMPLO 7";
    cout<<"\n";
    cout<<Maestros.check_info(3);
    
    cout<<"\n Checar archivo casos_de_prueba.hpp para explicacion de ejemplos. \n"<<"\n";
}


