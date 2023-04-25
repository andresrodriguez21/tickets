#include "Ruta.h"

Ruta::Ruta(){
	id = "";
}

Ruta::Ruta(string idd) :Object() {
	id = idd;
}

string Ruta::getID() {
	return id;
}

string Ruta::toString() {
	stringstream s;
	s << id << endl << endl;
	return s.str();
}