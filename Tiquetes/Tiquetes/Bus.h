#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
#include "Object.h"
#include "Ruta.h"

using namespace std;

class Ruta;

class Bus:public Object{

private:
	Ruta* ruta = NULL;
	string nombre;
	int capacidad = 1;
	int asientosOcupados = 0;
	double disponibilidad = 0;

public:
	Bus(string, string, int, int, Ruta*);
	double calculaDisponibilidad(int);
	//gets
	string getID();
	string getNombre();
	int getCapacidad();
	int getAsientosOcupados();
	Ruta* getRuta();
	//sets
	void setAsientosOcupados(int);
	void setRuta(Ruta*);
	string toString();
	string toString(int);
};
