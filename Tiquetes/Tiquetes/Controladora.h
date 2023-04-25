#pragma once
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Usuario.h"
#include "Lista.h"
#include "Excepcion.h"

using namespace std;

//Controla menu y listas, delega los metodos a la clase Usuario
class Controladora{

private:
	Lista* flota = new Lista();
	Lista* rutas = new Lista();
	Lista* tiquetes = new Lista();
	Usuario* ptrUsuario = new Usuario();

public:
	Controladora();
	void setAforo();
	void limpiaVariables();

	void cargaInfo();
	void guardaInfo();
	void menuPrincipal();

	//1
	void menuConfiguracion();
	void modificarAforo();
	void verLista(Lista*);
	Lista* ingresarBus();
	Lista* ingresarRuta();
	Lista* asociarBusConRuta();
	//2
	void menuReservaDeTiquetes();
	Lista* reservar();
	//3
	void menuReportes();
	void disponibilidadPorRuta();
	//4 Salir
};
