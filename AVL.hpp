#ifndef AVL_H_
#define AVL_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;


//Clase Maestro: son nodos de la clase arbol AVL con sus funciones respectivas
//ademas de tener atributos propios de maestro como nombre, id, etc.
class Maestro {
private:
    //Variables de Maestro
    string name;
    int ID;
    string group;
    string materia;
    
    //Variables AVL
    Maestro *right;
    Maestro *left;
    int level, balance;
    Maestro* predecesor();

public:
    //Constructor
    Maestro(string, int, string, string);
    
    //Metodos de Arbol
    void add(string,int,string,string);
    bool find(int);
    void remove(int);
    void removeChilds();
    
    //Metodos de impresion
    void to_string(std::stringstream&) const;
    void check_info(std::stringstream&, int) const;
    
    //Metodos de balanceo
    int max_depth();
    Maestro* check_tree(int*, Maestro*, bool*);
    Maestro* balance_tree();
    Maestro* rot_left(Maestro* );
    Maestro* rot_right(Maestro* );
    Maestro* rot_left_right(Maestro* );
    Maestro* rot_right_left(Maestro* );
    friend class AVL;
};

//Constructor
Maestro::Maestro(string n, int i, string g, string m) : name(n), ID(i), group(g), materia(m),left(0), right(0), level(0), balance(0) {}


//Metodo add: agrega un nodo al arbol.
void Maestro::add(string n, int i, string g, string m) {
    if (i < ID) {
        if (left != 0) {
            left->add(n,i,g,m);
        } else {
            left = new Maestro(n,i,g,m);
        }
    } else {
        if (right != 0) {
            right->add(n,i,g,m);
        } else {
            right = new Maestro(n,i,g,m);
        }
    }
}

//Metodo find checa que un valor exista dentro del arbol
bool Maestro::find(int i) {
    if (i == ID) {
        return true;
    } else if (i < ID) {
        return (left != 0 && left->find(i));
    } else if (i > ID) {
        return (right != 0 && right->find(i));
    }
    else{
        return false;
    }
}

//Predecesor: consigue el nodo de arbol que sea su predecesor y lo devuelve sin ninguna conexion a otro nodo
Maestro* Maestro::predecesor() {
    Maestro *le, *ri;

    le = left;
    ri = right;

    if (left == 0) {
        if (right != 0) {
            right = 0;
        }
        return ri;
    }

    if (left->right == 0) {
        left = left->left;
        le->left = 0;
        return le;
    }

    Maestro *parent, *child;
    parent = left;
    child = left->right;
    while (child->right != 0) {
        parent = child;
        child = child->right;
    }
    parent->right = child->left;
    child->left = 0;
    return child;
}

void Maestro::remove(int i) {
    Maestro * succ, *old;

    if (i < ID) {
        if (left != 0) {
            if (left->ID == i) {
                old = left;
                succ = left->predecesor();
                if (succ != 0) {
                    succ->left = old->left;
                    succ->right = old->right;
                }
                left = succ;
                delete old;
            } else {
                left->remove(i);
            }
        }
    } else if (i > ID) {
        if (right != 0) {
            if (right->ID == i) {
                old = right;
                succ = right->predecesor();
                if (succ != 0) {
                    succ->left = old->left;
                    succ->right = old->right;
                }
                right = succ;
                delete old;
            } else {
                right->remove(i);
            }
        }
    }
}

//Elimina hijos de nodo
void Maestro::removeChilds() {
    if (left != 0) {
        left->removeChilds();
        delete left;
        left = 0;
    }
    if (right != 0) {
        right->removeChilds();
        delete right;
        right = 0;
    }
}

//imprime el arbol completo
void Maestro::to_string(std::stringstream &aux) const {
    if (left != 0) {
        left->to_string(aux);
    }
    if (aux.tellp() != 1) {
        aux << " ";
    }
    aux<<"\n";
    aux<<"----------------------";
    aux<<"\n";
    aux << "Nombre: "<<name;
    aux<<"\n";
    aux << "ID: "<<ID;
    aux<<"\n";
    aux << "Grupo: "<<group;
    aux<<"\n";
    aux << "Materia: "<<materia;
    aux<<"\n";
    aux<<"----------------------";
    aux<<"\n";
    
    if (right != 0) {
        right->to_string(aux);
    }
}

//Imprime la informacion de un solo nodo
void Maestro::check_info(std::stringstream &aux, int i) const{
    if(i == ID){
        aux<<"\n";
        aux<<"----------------------";
        aux<<"\n";
        aux << "Nombre: "<<name;
        aux<<"\n";
        aux << "ID: "<<ID;
        aux<<"\n";
        aux << "Grupo: "<<group;
        aux<<"\n";
        aux << "Materia: "<<materia;
        aux<<"\n";
        aux<<"----------------------";
        aux<<"\n";
    }
    else if(i < ID && left != 0){
        left->check_info(aux, i);
    }
    else if(i > ID && right != 0){
        right->check_info(aux, i);
    }
    else{
        aux<<"\n";
        aux<<"No existe este Maestro";
        aux<<"\n";
    }
}

//Metodos de balanceo
int Maestro::max_depth() {
    int le =0 , ri = 0;
    if (left != 0)
        le = left->max_depth() + 1;
    if (right != 0)
        ri = right->max_depth() + 1;
    if(le > ri)
        level = le;
    else
        level = ri;
    balance = le - ri;
    return level;
}

Maestro* Maestro::check_tree(int *check_val, Maestro *parent, bool *checked) {
    Maestro *le = 0, *ri = 0, *a = 0;
    if (left != 0)
        le = left->check_tree(check_val,this,checked);
    if (right != 0)
        ri = right->check_tree(check_val,this,checked);
    if (*checked == false){
        if (balance > 1){
            a = balance_tree();
            *check_val = ID;
            *checked = true;
            if(parent != 0){
                parent->left = a;
            }
        }else if (balance < -1){
            a = balance_tree();
            *check_val = ID;
            *checked = true;
            if(parent != 0){
                parent->right = a;
            }
        }
    }
    return a;
}

Maestro* Maestro::balance_tree() {
    Maestro *a = this, *le =left, *ri =right;
    if (balance > 0) {
        if (le->balance > 0){
            a = rot_right(a);
        }else{
            a = rot_left_right(a);
        }
    }else{
        if (ri->balance < 0){
            a = rot_left(a);
        }else{
            a = rot_right_left(a);
        }
    }
    return a;
}

Maestro* Maestro::rot_left(Maestro* a){
    Maestro *b, *temp = 0;
        b = a->right;
        if (b->left != 0)
            temp = b->left;
        b->left = a;
        if(temp != 0){
            a->right = temp;
        }else{
            a->right = 0;
    }
    return b;
}

Maestro* Maestro::rot_right(Maestro* a){
    Maestro *b, *temp = 0;
        b = a->left;
        if (b->right != 0)
            temp = b->right;
        b->right = a;
        if(temp != 0){
            a->left = temp;
        }else{
            a->left = 0;
    }
    return b;
}

Maestro* Maestro::rot_left_right(Maestro* a){
    a->left = rot_left(a->left);
    a = rot_right(a);
    return a;
}

Maestro*  Maestro::rot_right_left(Maestro* a){
    a->right = rot_right(a->right);
    a = rot_left(a);
    return a;
}


//Clase AVL es un arbol AVL manejador de objetos de tipo Maestro
class AVL {
private:
    Maestro *root;

public:
    //Constructores
    AVL();
    ~AVL();
    
    //Metodos
    bool empty() const;
    void add(string,int,string,string);
    bool find(int) const;
    void remove(int);
    void removeAll();
    
    //Metodos de impresion
    std::string to_string() const;
    std::string check_info(int) const;
};

//Constructores
AVL::AVL() : root(0) {}

AVL::~AVL() {
    removeAll();
}

//Checa si el arbol esta vacio
bool AVL::empty() const {
    return (root == 0);
}

//add: agrega un nodo al arbol ademas que llama a las funciones de balanceo
void AVL::add(string n, int i, string g, string m) {
    bool cont = true;
    if (root != 0) {
        while(cont){
            if (root->find(i)) {
                i++;
            }
            else{
                cont = false;
            }
        }
        Maestro *temp;
        int check_val = 0;
        bool aux = false;
        root->add(n,i,g,m);
        root->max_depth();
        temp = root->check_tree(&check_val, 0, &aux);
        if (check_val == root->ID){
            root = temp;
        }
        root->max_depth();
    } else {
        root = new Maestro(n,i,g,m);
    }
}

//remove elimina a un nodo del arbol y llama a las funciones de balanceo
void AVL::remove(int i) {
    if (root != 0) {
        if (i == root->ID) {
            Maestro *succ = root->predecesor();
            if (succ != 0) {
                succ->left = root->left;
                succ->right = root->right;
            }
            delete root;
            root = succ;
        } else {
            root->remove(i);
        }
        if(!empty()){
            root->max_depth();
            Maestro *temp;
            int check_val = 0;
            bool aux = false;
            temp = root->check_tree(&check_val, 0, &aux);
            if (check_val == root->ID){
                root = temp;
            }
            root->max_depth();
        }
    }
}

//Elimina todo el arbol
void AVL::removeAll() {
    if (root != 0) {
        root->removeChilds();
    }
    delete root;
    root = 0;
}

//Checa si un valor existe dentro del arbol
bool AVL::find(int val) const {
    if (root != 0) {
        return root->find(val);
    } else {
        return false;
    }
}

//imprime el arbol completo
std::string AVL::to_string() const {
    std::stringstream aux;

    if (!empty()) {
        root->to_string(aux);
    }
    else{
        aux<<"No hay maestros. ";
    }
    return aux.str();
}

//imprime informacion de un solo maestro
std::string AVL::check_info(int i) const {
    std::stringstream aux;

    if (!empty()) {
        root->check_info(aux, i);
    }
    else{
        aux<<"No hay maestros. ";
    }
    return aux.str();
}

#endif /* AVL_H_ */
