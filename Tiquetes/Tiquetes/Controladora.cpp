#include "Controladora.h"
#include "Object.h"
#include "Bus.h"
#include "Ruta.h"
#include "Tiquete.h"

Controladora::Controladora() {
}

void Controladora::setAforo() {
	ptrUsuario->setAforo();
}

void Controladora::limpiaVariables() {
	cin.clear();
	cin.ignore(255, '\n');
}

void Controladora::cargaInfo() {
	int aforo = flota->cargaAforo();
	ptrUsuario->setAforo(aforo);
	rutas = rutas->cargaRutas(rutas);
	tiquetes = tiquetes->cargaTiquetes(tiquetes);
	flota = flota->cargaBuses(flota);
	cout << "Informacion cargada exitosamente";
}

void Controladora::guardaInfo() {
	system("cls");
	int aforo = ptrUsuario->getAforo();
	flota->guardaAforo(aforo);
	rutas->guardaRutas();
	flota->guardaBuses();
	tiquetes->guardaTiquetes();
	cout << "Informacion guardada exitosamente" << endl;
	system("pause");
	exit(0);
}

void Controladora::menuPrincipal() {
	limpiaVariables();
	system("cls");
	int opc;
	try {
	cout << "	Aforo al " << ptrUsuario->getAforo() << " %" << endl << endl;
	cout << "	Menu principal" << endl;
	cout << "1. Configuracion" << endl;
	cout << "2. Reserva de tiquetes" << endl;
	cout << "3. Reportes" << endl;
	cout << "4. Salir" << endl;
	cout << "Digite la opcion: ";

	if (cin >> opc) {
	
			switch (opc) {
			case 1:
			menuConfiguracion();
			break;

			case 2:
			menuReservaDeTiquetes();
			break;

			case 3:
			menuReportes();
			break;

			case 4:
			limpiaVariables();
			guardaInfo();
			exit(0);
			break;

			default:
			menuPrincipal();
			break;
	}
	}	
	
		else {
		throw new Excepcion();
		}
	
	}//try

	catch (Excepcion* e) {
		e->palabraDigitada();
		limpiaVariables();
		menuPrincipal();
	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		limpiaVariables();
		menuPrincipal();
	}
}

//1
void Controladora::menuConfiguracion() {
	system("cls");
	int opc;
	try {
	cout << "	Aforo al " << ptrUsuario->getAforo() << " %" << endl << endl;
	cout << "	Configuracion" << endl;
	cout << "1. Modificar aforo" << endl;
	cout << "2. Ver buses" << endl;
	cout << "3. Ver rutas" << endl;
	cout << "4. Ingresar bus" << endl;
	cout << "5. Ingresar ruta" << endl;
	cout << "6. Asociar bus con ruta" << endl;
	cout << "7. Regresar" << endl;
	cout << "Digite la opcion: ";

		if (cin >> opc) {
	
			switch (opc) {
			case 1:
			modificarAforo();
			limpiaVariables();
			menuConfiguracion();
			break;

			case 2:
			verLista(flota);
			menuConfiguracion();
			break;

			case 3:
			verLista(rutas);
			menuConfiguracion();
			break;

			case 4:
			this->flota = ingresarBus();
			menuConfiguracion();
			break;

			case 5:
			this->rutas = ingresarRuta();
			menuConfiguracion();
			break;

			case 6:
			this->flota = asociarBusConRuta();
			menuConfiguracion();
			break;

			case 7:
			menuPrincipal();
			break;

			default:
			menuPrincipal();
			break;
			}	
	}

	else {

		throw new Excepcion();
	}

	}//try

	catch (Excepcion* e) {
		e->palabraDigitada();
		limpiaVariables();
		menuPrincipal();
	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		limpiaVariables();
		menuConfiguracion();
	}

}
 
void Controladora::verLista(Lista* lista){
	ptrUsuario->verLista(lista);
}

void Controladora::modificarAforo() {
	ptrUsuario->setAforo();
}

Lista* Controladora::ingresarBus() {
	return ptrUsuario->ingresarBus(flota);
}

Lista* Controladora::ingresarRuta() {
	return ptrUsuario->ingresarRuta(rutas);
}

Lista* Controladora::asociarBusConRuta() {
	return ptrUsuario->asociarBusConRuta(flota, rutas);
}

//2
void Controladora::menuReservaDeTiquetes() {
	system("cls");
	int opc;
	try {
	cout << "	Aforo al " << ptrUsuario->getAforo() << " %" << endl << endl;
	cout << "	Reserva de tiquetes" << endl;
	cout << "1. Reservar" << endl;
	cout << "2. Regresar" << endl;
	cout << "Digite la opcion: ";
	
	if(cin >> opc){
	switch (opc) {
	case 1:
		this->flota = reservar();
		menuReservaDeTiquetes();
		break;

	case 2:
		menuPrincipal();
		break;

	default:
		menuPrincipal();
		break;
	}	
	}

	else {

		throw new Excepcion();
	}

	}//try

	catch (Excepcion* e) {
		e->palabraDigitada();
		limpiaVariables();
		menuPrincipal();
	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		limpiaVariables();
		menuReservaDeTiquetes();
	}
}

Lista* Controladora::reservar() {
	return ptrUsuario->reservar(flota, tiquetes);
	//menuReservaDeTiquetes();
}

//3
void Controladora::menuReportes() {
	system("cls");
	int opc;
	try {
	cout << "	Aforo al " << ptrUsuario->getAforo() << " %" << endl << endl;
	cout << "	Reportes" << endl;
	cout << "1. Ver tiquetes" << endl;
	cout << "2. Ver disponibilidad por ruta" << endl;
	cout << "3. Regresar" << endl;
	cout << "Digite la opcion: ";
	
	if (cin >> opc) {
		switch (opc) {
		case 1:
		verLista(tiquetes);
		menuReportes();
		break;

		case 2:
		disponibilidadPorRuta();
		menuReportes();
		break;
		case 3:
		menuPrincipal();
		break;

		default:
		menuPrincipal();
		break;
		}
	}

	else {
		throw new Excepcion();
	}
	}//try

	catch (Excepcion* e) {
		e->palabraDigitada();
		limpiaVariables();
		menuPrincipal();
	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		limpiaVariables();
		menuReportes();
	}
}

void Controladora::disponibilidadPorRuta() {
	ptrUsuario->disponibilidadPorRuta(flota);
	menuReportes();
}