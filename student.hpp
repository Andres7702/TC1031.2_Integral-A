//
//  student.hpp
//  Pruebas
//
//  Created by Andrés Acevedo on 06/10/21.
//

#ifndef student_hpp
#define student_hpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include "dlist.hpp"
#include "Calificaciones.hpp"

using namespace std;

//CLASE estudiante: objeto de una lista que tiene atributos propios//

class student{
private:
    
    //CONSTRUCTORES//
    
    student();
    student(string,int,int);
    student(string,int,int,double,double,double,double,double,double,double,double);
    student(string, int, int,student*, student*);
    
    //VARIABLES DE ESTUDIANTE//
    
    string name;
    int ID;
    int grade;
    Calificaciones C;
    student *previous;
    student *next;
    
    friend class DList;
};

//CONSTRUCTORES//

student:: student(){
    name = "";
    ID = 0;
    grade = 0;
    next = 0;
    previous = 0;
    C = Calificaciones();
}

student:: student(string n, int i, int g){
    name = n;
    ID = i;
    grade = g;
    next = 0;
    previous = 0;
    C = Calificaciones();
}

student:: student(string n, int i, int g, double m, double f, double b, double q, double in, double e, double et, double d){
    name = n;
    ID = i;
    grade = g;
    next = 0;
    previous = 0;
    C = Calificaciones(m,f,b,q,in,e,et,d);
}

student:: student(string n, int i,  int g, student* nxt, student* prv){
    name = n;
    ID = i;
    grade = g;
    next = nxt;
    previous = prv;
    C = Calificaciones();
}
#endif /* student_hpp */

