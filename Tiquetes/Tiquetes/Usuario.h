#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Excepcion.h"
#include "Lista.h"
#include "Bus.h"

using namespace std;
//Principio de Segregación de la Interfaz
//Ejecuta los metodos que la clase controladora le delega
class Usuario {

public:
	double aforo;

public:
	Usuario();
	double getAforo();
	void setAforo(int);
	//Metodos delegados
	void setAforo();
	void verLista(Lista*);
	Lista* ingresarBus(Lista*);
	Lista* ingresarRuta(Lista*);
	Lista* asociarBusConRuta(Lista*, Lista*);
	Lista* reservar(Lista*, Lista*);
	void disponibilidadPorRuta(Lista*);
};