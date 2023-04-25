#include "Usuario.h"
#include "Bus.h"
#include "Ruta.h"
#include "Tiquete.h"

Usuario::Usuario() {
	aforo = 80;
}

double Usuario::getAforo() {
	return aforo;
}

void Usuario::setAforo(int nuevoAforo) {
	aforo = nuevoAforo;
}

//1
void Usuario::setAforo() {
	system("cls");
	double afo;
	try {
	cout << "Aforo al " << aforo << " %" << endl << endl;
	cout << "Nuevo valor: ";
	

		if (cin >> afo) {
			if ((afo >= 0) && (afo <= 100)) {
				aforo = afo;
			}
			else {
				cout << "Error. Digite un numero entre 0 y 100" << endl;
				system("pause");
			}
		}

	else {
		throw new Excepcion();
	}
	}

	catch(Excepcion* e) {
		e->palabraDigitada();
	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		system("pause");
	}

}

void Usuario::verLista(Lista* lista){
	system("cls");
	cout << lista->toString() << endl;
	system("pause");
}

Lista* Usuario::ingresarBus(Lista* lista) {
	system("cls");
	cin.ignore();
	string placa, nombre;
	int capacidad = 0;
	cout << "Digite la placa    : ";
	getline(cin, placa, '\n');

	if (lista->existe(placa)) {
		cout << "Error. El bus ya existe" << endl;
		system("pause");
	}
	else {

		try {
			cout << "Digite la capacidad: ";

			if ((cin >> capacidad) && (capacidad > 0)) {
				cout << "Digite el tipo     : ";
				cin >> nombre;

				Ruta* ninguna = new Ruta("ninguna");
				Object* bus = new Bus(placa, nombre, 0, capacidad, ninguna);
				lista->ingresaObjeto(bus);
				cout << "Bus ingresado" << endl;
				system("pause");

			}
			else {
				throw new Excepcion();
			}

		}

	catch (Excepcion* e) {
		 e->palabraDigitada();
	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		system("pause");
	}
	}
	return lista;
}

Lista* Usuario::ingresarRuta(Lista* lista) {
	system("cls");
	cin.ignore();
	string rutaS;
	cout << "Digite la ruta: ";
	getline(cin, rutaS, '\n');
	Object* ruta = new Ruta(rutaS);
	if (lista->existe(rutaS)) {
		cout << "Error. La ruta ya existe" << endl;
		system("pause");
	}
	else {
	lista->ingresaObjeto(ruta);
	cout << "Ruta ingresada" << endl;
	system("pause");
	}
	return lista;
}

Lista* Usuario::asociarBusConRuta(Lista* flota, Lista* rutas) {
	system("cls");
	cin.ignore();
	string rutaS;
	string placa;

	cout << flota->toString() << endl << endl;
	cout << "Digite la placa del bus: ";
	getline(cin, placa, '\n');

	system("cls");
	cout << rutas->toString() << endl << endl;
	cout << "Digite la ruta a asignar: ";
	getline(cin, rutaS, '\n');

	if ((flota->existe(placa)) && (rutas->existe(rutaS) && (placa != rutaS))) {
		//Se extraen los objetos
		Object* objRuta = rutas->getObject(rutaS);
		Object* objBus = flota->getObject(placa);
		//Se le hacen downcast
		Bus* bus = dynamic_cast<Bus*>(objBus);
		Ruta * ruta = dynamic_cast<Ruta*>(objRuta);

		//Setea ruta a bus
		bus->setRuta(ruta);

		cout << "Ruta asignada" << endl;
		system("pause");
		//Elimina el bus antiguo
		flota->borraObjeto(placa);
		//Ingresa el nuevo con la ruta asignada
		flota->ingresaObjeto(bus);
		//flota->borraObjeto(placa); //hay que ver

	}
	else {
		cout << "Error. Bus y/o ruta no existe" << endl;
		cout << "O placa del bus es igual a nombre de ruta" << endl;
		system("pause");
	}
	return flota;
}

//2

Lista* Usuario::reservar(Lista* flota, Lista* tiquetes) {
	system("cls");
	cin.ignore();
	cout << "	Aforo al " << aforo << " %" << endl << endl;
	string placa = "";
	string cedula, ruta;
	int nuevosPasajeros = 0;
	int cantBusesTotal = flota->getCont();
	int capacidad = 0;
	int asientosOcupados = 0;
	double disponibilidad = 0;
	double disponibilidad2 = 0;

	cout << flota->verRutas() << endl;
	cout << "Digite la PLACA del bus: ";
	getline(cin, placa, '\n');

	//if #1
	if (flota->existe(placa)) {
		system("cls");
		Object* objBus = flota->getObject(placa);
		Bus* bus = dynamic_cast<Bus*>(objBus);
		Bus* nuevoBus = NULL;

		//Extrae atributos 
		placa = bus->getID();
		ruta = bus->getRuta()->getID();
		capacidad = bus->getCapacidad();
		asientosOcupados = bus->getAsientosOcupados();
		disponibilidad = bus->calculaDisponibilidad(asientosOcupados); //%

		//		No este lleno				Tenga ruta
		//if #2
		if ((disponibilidad != 100) && (ruta != "ninguna")) { 

				cout << "Cantidad de pasajeros: ";

				try{
				//if #3
				if (cin >> nuevosPasajeros) { 

				int suma = asientosOcupados + nuevosPasajeros;
				disponibilidad2 = bus->calculaDisponibilidad(suma);

				//Evita crear tiquetes en buses sin capacidad respetando el aforo
				//if #4
				if ((disponibilidad2 <= aforo) && (suma <= capacidad) && (nuevosPasajeros > 0)) {
						cin.ignore();
					for (int j = 0; j < nuevosPasajeros; j++) {

						cout << endl;
						cout << "Cedula del pasajero " << j + 1 << ": ";
						getline(cin, cedula, '\n');

						int numero = tiquetes->getCont() + 1;
						string numTiquete(std::to_string(numero));

						Object* tiquet = new Tiquete(numTiquete, ruta, placa, cedula);

						tiquetes->ingresaObjeto(tiquet);
						cout << endl;
						cout << "Pasajero ingresado. Su tiquete:" << endl;
						cout << tiquet->toString();
						system("pause");

						}//for j

						nuevoBus = bus;
						nuevoBus->setAsientosOcupados(suma);

						//Borra el antiguo bus
						flota->borraObjeto(placa);
						//Ingresa el bus con la cantidad de pasajeros seteada
						flota->ingresaObjeto(nuevoBus);


				}//#4

				else {
					cout << endl;
					cout << "Error. No hay espacio para " << nuevosPasajeros << " personas. Verifique aforo" << endl;
					cout << "O no ingreso ningun pasajero" << endl;
					system("pause");
				}
		
		}//#3

					else {
							throw new Excepcion();
					}

				}//try

				catch (Excepcion* e) {
					e->palabraDigitada();
				}

				catch (...) {
					cout << "Error indeterminado" << endl;
					system("pause");
				}

				}//#2 

				else {
					cout << "Bus lleno o el bus no tiene ruta" << endl;
					system("pause");
				}

		}//#1

		else {
			cout << "Error. El bus no existe" << endl;
			system("pause");
		}
	return flota;
	}

//3
void Usuario::disponibilidadPorRuta(Lista* flota){
	system("cls");
	cout << "	Rutas disponibles" << endl << endl;
	cout << flota->verRutas();
	system("pause");
}
