#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"

using namespace std;

//Principio de Abierto/Cerrado.
//Se podrian hacer mas metodos usando los atributos del tiquete
//Por ejemplo "buscaTiquetePorRuta()"

class Tiquete :public Object {

private:
	string ruta;
	string bus;
	string cedula;

public:
	Tiquete(string, string, string, string);
	string getID();
	string getRuta();
	string getBus();
	string getCedula();
	string toString();
};
