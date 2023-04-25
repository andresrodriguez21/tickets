#include "Excepcion.h"

Excepcion::Excepcion() {

}

void Excepcion::palabraDigitada() {
	cout << endl;
	cout << "Error. Digite una opcion valida." << endl;
	system("pause");
}

void Excepcion::guardaArchivo(string archivo) {
	cout << endl;
	cout << "Error. No fue posible guardar el archivo de " << archivo << endl;
	system("pause");
}

void Excepcion::cargaArchivo(string archivo) {
	cout << endl;
	cout << "Error. No fue posible cargar el archivo de " << archivo << endl;
	system("pause");
}