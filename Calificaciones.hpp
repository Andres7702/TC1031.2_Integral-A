

#ifndef Calificaciones_hpp
#define Calificaciones_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Clase Materia: son objetos con dos atributos nombre y calificacion.

class Materia{
private:
    
    //Varibales
    string nombre;
    float calificacion;
    
    //Constructores
    Materia();
    Materia(string, float);
    
    friend class Calificaciones;
};

//Constructores
Materia::Materia(){
    nombre = " ";
    calificacion = 0;
}

Materia::Materia(string n, float c){
    nombre = n;
    calificacion = c;
}



//Clase Calificaciones es un una clase que contiene un array de objetos tipo Materia.
//Esto array de calificaciones se asignara a cada estudiante y asi se podra desplegar calificaciones

class Calificaciones{
    
public:
    //Constructores
    Calificaciones();
    Calificaciones(double,double,double,double,double,double,double,double);
    
    //Metodo de impresion
    std::string toString() const;
    
    //Metodo de acceso de datos
    void update_calificacion(int,double);
    Materia prioridad();
    
private:
    //Variables
    Materia data[8];
    string peor_calif() const;
};

//Constructores
Calificaciones::Calificaciones(){
    data[0] = Materia("Matematicas",0);
    data[1] = Materia("Fisica",0);
    data[2] = Materia("Biologia",0);
    data[3] = Materia("Quimica",0);
    data[4] = Materia("Ingles",0);
    data[5] = Materia("Español",0);
    data[6] = Materia("Etica",0);
    data[7] = Materia("Deportes",0);
}

Calificaciones::Calificaciones(double m, double f, double b, double q, double i, double e, double et, double d){
    data[0] = Materia("Matematicas",m);
    data[1] = Materia("Fisica",f);
    data[2] = Materia("Biologia",b);
    data[3] = Materia("Quimica",q);
    data[4] = Materia("Ingles",i);
    data[5] = Materia("Español",e);
    data[6] = Materia("Etica",et);
    data[7] = Materia("Deportes",d);
}

//funcion update_calificacion: cambia la calificacion de una materia
void Calificaciones::update_calificacion(int pos, double cal){
    if(pos >= 0 && pos < 8){
        data[pos].calificacion = cal;
    }
}

//Devuelve la peor calificaciones
string Calificaciones::peor_calif() const{
    int aux = 100;
    int pos = 0;
    for(int i = 0; i < 8; i++){
        if(data[i].calificacion < aux){
            aux = data[i].calificacion;
            pos = i;
        }
    }
    return(data[pos].nombre);
}

//Imprime las calificaciones completas
std::string Calificaciones::toString() const{
    std::stringstream aux;
    aux<<"\n";
    aux<<"Calificaciones: \n";
    int sum = 0;
    for(int i = 0; i < 8; i++){
        sum += data[i].calificacion;
        aux<<data[i].nombre;
        aux<<"   ";
        aux<<data[i].calificacion;
        aux<<"\n";
    }
    if(sum <= 40){
        return(aux.str());
    }
    else{
        aux<<"\n";
        aux<<"Dar prioridad a : "<<peor_calif();
        aux<<"\n";
        return(aux.str());
    }
}


#endif /* Calificaciones_hpp */
