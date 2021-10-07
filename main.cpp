//Mi programa sera un manejador de grupos escolares.
//Se podran hacer listas de estudiantes que representaran los diferentes grupos de salon.
//Cada estudiante tendra sus propios atributos como nombre, id y grado que estan cursando.
//Cada que se agregue un estudiante se acomodara de manera adecuada dependiendo de su ID.
//En la lista tambien se podran eliminar estudiantes, cambiar datos, entre otras cosas.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include "dlist.hpp"
#include "student.hpp"

using namespace std;




int main() {
    
    //Creacion de lista "Grupo A"
    DList GrupoA;
    
    //Se agregan estudiantes a la lista con ID desordenados.
    //Esto para demostrar que la lista los acomoda de manera automatica.
    GrupoA.add_student("Andres", 4, 1);
    GrupoA.add_student("Diego", 2, 1);
    
    cout<<"\n";
    cout<<"EJEMPLO 1";
    cout<<"\n";
    GrupoA.toString();
    
    
    //Se modifica el grado de Andres y se elimina Diego de la lista.
    GrupoA.update(1, 3);
    GrupoA.deleteAt(0);
    
    cout<<"\n";
    cout<<"EJEMPLO 2";
    cout<<"\n";
    GrupoA.toString();
    
    
    //Se agregan mas estudiantes  a la lista y se acomodan en orden.
    GrupoA.add_student("Monica", 3, 1);
    GrupoA.add_student("Elian", 1, 1);
    GrupoA.add_student("Valeria", 7, 1);
    GrupoA.add_student("Sebastian", 5, 1);
    GrupoA.add_student("Salvador", 5, 1);
    
    cout<<"\n";
    cout<<"EJEMPLO 3";
    cout<<"\n";
    GrupoA.toString();
    
}
