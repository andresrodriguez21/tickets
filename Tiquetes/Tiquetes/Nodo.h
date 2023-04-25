#pragma once
#include<iostream>
#include <sstream>
#include "Object.h"

using namespace std;

class Nodo {
private:
    Object* objPtr;
    Nodo* siguiente;
public:
    Nodo(Object*, Nodo*);
    virtual ~Nodo();
    Object* getObjeto();
    Nodo* getSiguiente();
    void setObjeto(Object*);
    void setSiguiente(Nodo*);
};

