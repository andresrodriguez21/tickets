#include "Bus.h"

Bus::Bus(string idd, string nom, int asientos, int cap, Ruta* rutta) :Object() {
	id = idd;
	nombre = nom;
	asientosOcupados = asientos;
	capacidad = cap;
	disponibilidad = calculaDisponibilidad(asientosOcupados);
	ruta = rutta;
}

double Bus::calculaDisponibilidad(int nuevosPasajeros) {
	double dispo = (nuevosPasajeros * static_cast<double>(100)) / capacidad;
	return dispo;
}

string Bus::getID() {
	return id;
}

string Bus::getNombre() {
	return nombre;
}

int Bus::getCapacidad() {
	return capacidad;
}

int Bus::getAsientosOcupados() {
	return asientosOcupados;
}

Ruta* Bus::getRuta() {
	return ruta;
}

void Bus::setAsientosOcupados(int nuevoNumero) {
	asientosOcupados = nuevoNumero;
}

void Bus::setRuta(Ruta* rutta) {
	ruta = rutta;
}

string Bus::toString() {
	stringstream s;
	s << "Placa  : " << id << endl;
	s << "Tipo   : " << nombre << endl;
	s << "Ocupado: " << calculaDisponibilidad(asientosOcupados) << " %" << " " << "( " << asientosOcupados << " de " << capacidad << " )" << endl;

	if (ruta->getID() != "ninguna") {

		s << "Ruta   : " << ruta->getID() << endl;
	}
	s << endl;
	s << "-----------------------------------" << endl;
	s << endl;
	return s.str();
}

string Bus::toString(int x) {
	stringstream s;
	if (ruta->getID() != "ninguna") {
		s << "Placa  : " << id << endl;
		s << "Tipo   : " << nombre << endl;
		s << "Ocupado: " << calculaDisponibilidad(asientosOcupados) << " %" << " " << "( " << asientosOcupados << " de " << capacidad << " )" << endl;
		s << "Ruta   : " << ruta->getID() << endl;
		s << endl;
		s << "-----------------------------------" << endl;
		s << endl;
	}
	return s.str();
}