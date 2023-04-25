#include "Tiquete.h"

Tiquete::Tiquete(string idd, string rut, string buss, string ced) :Object() {
	id = idd;
	ruta = rut;
	bus = buss;
	cedula = ced;
}

string Tiquete::getID() {
	return id;
}

string Tiquete::getRuta() {
	return ruta;
}

string Tiquete::getBus() {
	return bus;
}

string Tiquete::getCedula() {
	return cedula;
}

string Tiquete::toString() {
	stringstream s;
	s << "Tiquete #" << id << ": " << ruta << " " << bus << " " << cedula << endl << endl;
	return s.str();
}