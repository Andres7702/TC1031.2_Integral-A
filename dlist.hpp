

#ifndef list_hpp
#define list_hpp
#include <stdio.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include "student.hpp"
#include "Calificaciones.hpp"

using namespace std;

//CLASE DLIST: Manejador de objetos de tipo estudiante//

class DList {
public:
    
    //CONSTRUCTORES//
    
    DList();
    DList(const DList&);

    //METODOS//
    
    void add_student(string,int,int);
    void update_year() const;
    bool find(int) const;
    void deleteAt(int);
    string toString() const;
    void check_info(int) const;
    void update_calificacion(int,int,double);

private:
    
    void addFirst(string, int,int);
    void addSecond(string, int,int);
    void deleteFirst();
    bool empty() const;
    
    //VARIABLES DE LIST//
    
    student *head; //Apuntador al inicio de la lista
    student *tail;
    int size; //Variable de tamaño de lista

};

//DEFINICION DE CONSTRUCTORES//

DList::DList() : head(0), size(0), tail(0) {}


//empty: devuelve true si no hay ningun elemento en la lista//

bool DList::empty() const {
    return (head == 0);
}


//addFirst: Crea un estudiante nuevo con un valor recibido y despues lo hace head de la lista.//

void DList::addFirst(string n, int i, int g){
    student *newstudent;

    newstudent = new student(n,i,g);
    newstudent->next = head;
    newstudent->previous = head;
    
    head = newstudent;
    tail = newstudent;
}

//addSecond: Crea un estudiante nuevo con un valor recibido y lo hace head o tail de la lista//
//dependiendo de cual sea mayor.//

void DList::addSecond(string n, int i, int g){
    student *newstudent;

    newstudent = new student(n,i,g);
    if(newstudent->ID < head->ID){
        newstudent->next = head;
        newstudent->previous = 0;
        head->previous = newstudent;
        head->next = 0;
        tail = head;
        head = newstudent;
    }
    else{
        newstudent->next = 0;
        newstudent->previous = head;
        head->next = newstudent;
        tail = newstudent;
    }
}


//insertion: Recibe un valor y crea un estudiante nuevo y lo agrega a la lista dependiendo de su ID//

void DList::add_student(string n, int i, int g){
    student *newstudent, *p;
    
    
    p = head;

    
    if(empty()){
        addFirst(n, i, g);
    }
    else if(size == 1){
        addSecond(n,i,g);
    }
    else{
        newstudent = new student(n,i,g);
        
        while(p->next != 0 && p->next->ID < newstudent->ID){
            p = p->next;
        }
        
        if(p->previous != 0){
            cout<<p->previous->ID;
        }
        if(p->next != 0){
            cout<<p->next->ID;
        }

        if(p->next == 0){
            if(p->ID > newstudent->ID){
                
                newstudent->next = p;
                newstudent->previous = p->previous;
                p->previous->next = newstudent;
                p->previous = newstudent;
            }
            else{
                newstudent->previous = p;
                p->next = newstudent;
                tail = newstudent;
            }
        }
        else if(p->previous == 0){
            if(p->ID > newstudent->ID){
                newstudent->next = p;
                newstudent->previous = 0;
                p->previous = newstudent;
                head = newstudent;
            }
            else{
                newstudent->next = p->next;
                newstudent->previous = p;
                p->next->previous = newstudent;
                p->next = newstudent;
            }
        }
        else{
            newstudent->next = p->next;
            newstudent->previous = p;
            p->next->previous = newstudent;
            p->next = newstudent;
            
        }
    }
    size++;
}


//find checa si ya existe un ID//

bool DList::find(int i) const {
    student *p;
    
    p = head;
    
    while (p != 0){
        if (p->ID == i){
            return true;
        }
        p = p->next;
    }
    return false;
}


void DList::update_calificacion(int e, int p, double c){
    student *k;
    
    k = head;
    
    while (k != 0 && k->ID != e){
            k = k->next;
    }
    if(k != 0){
        k->C.update_calificacion(p,c);
    }
    else{
        cout<<"Ese alumno no existe. \n";
        cout<<"\n";
    }
        
}


//deleteAt: Recibe un valor de posicion y elimina ese estudiante de la lista//

void DList::deleteAt(int i) {
    student *p1;
    student *p2;
    
    p1 = head;
    
    while(p1->next != 0 && p1->next->ID != i){
        p1 = p1->next;
    }
    if(p1->previous == 0 && p1->next == 0){
        head = 0;
    }
    else if(head->ID == i){
        deleteFirst();
    }
    else if(p1->next == 0){
        p1->previous->next = 0;
    }
    else{
        p2 = p1;
        
        p2 = p2->next;
        
        p1->next = p2->next;
        
        if(p2->next != 0){
            p2->next->previous = p1;
        }
        
        delete p2;
        
        size--;
    }
}

//deleteFirst: Elimina el primer elemento de una lista y cambia el head al segundo valor//

void DList::deleteFirst(){
    student *p;

    p = head;

    head = p->next;
    p->next->previous = 0;

    delete p;
    size--;
}

//toString: imprime los datos de todos los estudiantes de la lista//


string DList::toString() const {
    std::stringstream aux;
    student *p;
    p = head;
    aux<<"----------------------------------";
    while (p != 0) {
        aux << "\n";
        aux <<"Name: "<<p->name;
        aux << "\n";
        aux<<"ID: "<<p->ID;
        aux << "\n";
        aux<<"grade: "<<p->grade;
        aux << "\n";
        aux<<(p->C.toString());
        if (p->next != 0) {
            aux << "\n";
        }
        aux<<"----------------------------------";
        p = p->next;
    }
    return aux.str();
}

void DList::check_info(int i) const{
    std::stringstream aux;
    student *p;
    p = head;
    
    while(p != 0 && p->ID != i){
        p = p->next;
    }
    if(p == 0){
        aux<<"\n";
        aux<<"\n";
        aux<<"Ese Alumno no existe";
        aux<<"\n";
        cout<<aux.str();
    }
    else{
        aux<<"----------------------------------";
        aux << "\n";
        aux <<"Name: "<<p->name;
        aux << "\n";
        aux<<"ID: "<<p->ID;
        aux << "\n";
        aux<<"grade: "<<p->grade;
        aux << "\n";
        aux<<(p->C.toString());
        aux<<"----------------------------------";
        
        cout<<aux.str();
    }
}

#endif /* dlist_hpp */
