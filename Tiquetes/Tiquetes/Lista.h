#pragma once
#include<iostream>
#include <sstream>
#include <fstream>
#include "Nodo.h"
#include "Excepcion.h"

using namespace std;

class Lista {
private:
    Nodo* actual;
    int cont;
public:
    Lista();
    virtual ~Lista();
    string convierteAstring(int);
    int converteAint(string);

    int getCont();
    Object* getObject();
    Object* getObject(string);
    void ingresaObjeto(Object*);
    void borraObjeto(string);
    bool existe(string);
    //Principio de Sustitución de Liskov
    string verRutas();
    //
    string toString();
    void guardaAforo(int);
    void guardaRutas();
    void guardaBuses();
    void guardaTiquetes();
    int cargaAforo();
    Lista* cargaRutas(Lista*);
    Lista* cargaBuses(Lista*);
    Lista* cargaTiquetes(Lista*);
};
