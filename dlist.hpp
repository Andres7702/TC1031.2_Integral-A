

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

//CLASE DLIST: Manejador de objetos de tipo estudiante//

class DList {
public:
    
    //CONSTRUCTORES//
    
    DList();
    DList(const DList&);

    //METODOS//
    
    void add_student(string,int,int);
    void update(int, int) const;
    int search(string) const;
    void deleteAt(int);
    void toString() const;

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
    
    bool cont = true;
    
    p = head;
    
    if(empty()){
        addFirst(n, i, g);
    }
    else if(size == 1){
        addSecond(n,i,g);
    }
    else{
        newstudent = new student(n,i,g);
        
        while(p->next != 0 && cont){
            if(p->ID == newstudent->ID){
                newstudent->ID = (newstudent->ID)+1;
            }
            else if(p->ID < newstudent->ID){
                p = p->next;
            }
            else{
                cont = false;
            }
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


//search: Recibe un nombre y devuelve ID//

int DList::search(string n) const {
    student *p;
    
    p = head;
    int aux = p->ID;
    
    while (p != 0){
        if (p->name == n){
            return aux;
        }
        p = p->next;
    }
    return -1;
}


//update: recibe un int de posicion y un valor de grado. Cambia el valor actual de grado por el nuevo//

void DList::update(int pos, int g) const{
    int aux = 0;
    student *p;
    
    if (pos > 0 or pos <= size){
        p = head;
        
        while (aux != pos){
            p = p->next;
            aux++;
        }
        
        p->grade = g;
    }
}


//deleteAt: Recibe un valor de posicion y elimina ese estudiante de la lista//

void DList::deleteAt(int pos) {
    student *p1;
    student *p2;
    
    p1 = head;
    int aux = 0;
    
    if ((pos > 0 or pos <= size) and size > 0){
        
        if(pos == 0){
            
            deleteFirst();
        }
        
        else{
            
            while (aux != pos-1){
                p1 = p1->next;
                aux++;
            }
            
            p2 = p1;
            
            p2 = p2->next;
            
            p1->next = p2->next;
            
            p2->next->previous = p1;
            
            delete p2;
            
            size--;
        }
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


void DList::toString() const {
    std::stringstream aux;
    student *p;
    p = head;
    while (p != 0) {
        aux <<"Name: "<<p->name;
        aux << "\n";
        aux<<"ID: "<<p->ID;
        aux << "\n";
        aux<<"grade: "<<p->grade;
        aux << "\n";
        if (p->next != 0) {
            aux << "\n";
        }
        p = p->next;
    }
    cout<<aux.str();
}

#endif /* dlist_hpp */
