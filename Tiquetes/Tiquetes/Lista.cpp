#include "Lista.h"
#include "Bus.h"
#include "Ruta.h"
#include "Tiquete.h"

#define DELIMITACAMPO '/'

Lista::Lista() {
    actual = NULL;
    cont = 0;
}
Lista:: ~Lista() {
}

string Lista::convierteAstring(int num) {
    string numero(to_string(num));
    return numero;
}

int Lista::converteAint(string num) {
    stringstream s(num);
    int numero;
    s >> numero;
    return numero;
}

int Lista::getCont() {
    return cont;
}

Object* Lista::getObject() {
    Nodo* primero = actual;
    Nodo* aux;
    while (actual != NULL) {

        aux = actual;

        actual = actual->getSiguiente();

        return aux->getObjeto();
    }
    actual = primero;
}

Object* Lista::getObject(string id) {
    Nodo* primero = actual;
    Nodo* aux;
 
    while (actual != NULL) {
        if (actual->getObjeto()->getID()==id) {
            aux = actual;
            actual = primero;
            return aux->getObjeto();
        }
        else {
            this->actual = actual->getSiguiente();
        }
    }
    actual = primero;
}

void Lista::ingresaObjeto(Object* objPtr) {
    Nodo* ptrNodo = new Nodo(objPtr, actual);
    ptrNodo->setObjeto(objPtr);
    ptrNodo->setSiguiente(actual);
    actual = ptrNodo;
    cont++;
}



void Lista::borraObjeto(string id) {
    Nodo* anterior = NULL;
    Nodo* primero = actual;
    while ((actual) && (actual->getObjeto()->getID() == id)) {
        anterior = actual;
        actual = actual->getSiguiente();
    }
    if ((!actual) || (actual->getObjeto()->getID() != id)) {
        return;
    }
    else {
        if (!anterior) {
            primero = actual->getSiguiente();
        }
        else {
            anterior->setSiguiente(actual->getSiguiente());
        }
    }
}

bool Lista::existe(string id) {
    Nodo* primero = actual;

    while (actual != NULL) {

        if (actual->getObjeto()->getID() == id) {
            actual = primero;
            return true;
        }
        else {
            this->actual = actual->getSiguiente();
        }
    }
    actual = primero;
    return false;
}


string Lista::toString() {
    Nodo* primero = actual;
    stringstream s;
    while (actual != NULL) { 
        s << actual->getObjeto()->toString(); 
        this->actual = actual->getSiguiente(); 
    }
    actual = primero;
    return s.str();
}

string Lista::verRutas() {
    Nodo* primero = actual;
    Bus* bus = NULL;
    stringstream s;
    while (actual != NULL) {
        if (Bus* b = dynamic_cast<Bus*>(actual->getObjeto())) {
            s << b->toString(1);
            this->actual = actual->getSiguiente();
        }
        else {
            this->actual = actual->getSiguiente();
        }

    }
    actual = primero;
    return s.str();

}


//archivos
void Lista::guardaAforo(int afo) {
    Nodo* primero = actual;
    string aforo = "";
    ofstream Aforo("aforo.txt");
    try {
        if (Aforo) {

            aforo = convierteAstring(afo);

            Aforo << aforo;
        }
        else {
            throw new Excepcion();
        }
    }

    catch (Excepcion* e) {
        e->guardaArchivo("aforo");
    }

    catch (...) {
        cout << "Error indeterminado" << endl;
    }

    Aforo.close();
    actual = primero;
}



void Lista::guardaRutas() {
    Object* objRuta;
    Nodo* primero = actual;
    ofstream Rutas("rutas.txt");
    try {
        if (Rutas) {
            while (actual != NULL) {
            objRuta = actual->getObjeto();
            Ruta* ruta = dynamic_cast<Ruta*>(objRuta);
            string id = ruta->getID();

            Rutas << DELIMITACAMPO << id;
            actual = actual->getSiguiente();
            }
        }
        else {
            throw new Excepcion();
        }
    }
    
    catch (Excepcion * e) {
        e->guardaArchivo("rutas");
    }

    catch (...) {
        cout << "Error indeterminado" << endl;
    }

    Rutas.close();
    actual = primero;
}

void Lista::guardaBuses() {
    Object* objBus;
    Nodo* primero = actual;
    ofstream Buses("buses.txt");
    try {
        if (Buses) {
            while (actual != NULL) {
                objBus = actual->getObjeto();
                Bus* bus = dynamic_cast<Bus*>(objBus);
                string placa = bus->getID();
                string nombre = bus->getNombre();
                string asientosOcupados = convierteAstring(bus->getAsientosOcupados());
                string capacidad = convierteAstring(bus->getCapacidad());
                string ruta = bus->getRuta()->getID();

                Buses << DELIMITACAMPO;
                Buses << placa << DELIMITACAMPO;
                Buses << nombre << DELIMITACAMPO;
                Buses << asientosOcupados << DELIMITACAMPO;
                Buses << capacidad << DELIMITACAMPO;
                Buses << ruta;
                actual = actual->getSiguiente();
            }
        }
        else {
            throw new Excepcion();
        }
    }
    catch (Excepcion* e) {
        e->guardaArchivo("buses");
    }

    catch (...) {
        cout << "Error indeterminado" << endl;
    }


    Buses.close();
    actual = primero;
}

void Lista::guardaTiquetes() {
    Object* objTiquete;
    Nodo* primero = actual;
    ofstream Tiquetes("tiquetes.txt");
    try {
        if (Tiquetes) {
        while (actual != NULL) {
        objTiquete = actual->getObjeto();
        Tiquete* tiquete = dynamic_cast<Tiquete*>(objTiquete);
        string numTiquete = tiquete->getID();
        string ruta = tiquete->getRuta();
        string bus = tiquete->getBus();
        string cedula = tiquete->getCedula();

        Tiquetes << DELIMITACAMPO;
        Tiquetes << numTiquete << DELIMITACAMPO;
        Tiquetes << ruta << DELIMITACAMPO;
        Tiquetes << bus << DELIMITACAMPO;
        Tiquetes << cedula;

        actual = actual->getSiguiente();
        }


        }
        else {
            throw new Excepcion();
        }

    }

    catch (Excepcion* e) {
        e->guardaArchivo("tiquetes");
    }

    catch (...) {
        cout << "Error indeterminado" << endl;
    }


    Tiquetes.close();
    actual = primero;
}


int Lista::cargaAforo() {
    string afo = "";
    int aforo = 0;
    ifstream Aforo("aforo.txt", ios::in);

    try {
        if (Aforo) {
            Aforo >> afo;
        }
        else {
            throw new Excepcion();
        }

    }
    catch (Excepcion* e) {
        e->cargaArchivo("aforo");
    }

    catch (...) {
        cout << "Error indeterminado" << endl;
    }
    aforo = converteAint(afo);
    Aforo.close();
    return aforo;

}

Lista* Lista::cargaRutas(Lista* ListaRutas) {

    string id, nada;
    Nodo* primero = actual;
    ifstream Rutas("rutas.txt", ios::in);   

    try {
        if (Rutas) {
        getline(Rutas, nada, DELIMITACAMPO);

        while (!Rutas.eof()) {

            getline(Rutas, id, DELIMITACAMPO);
            Object* ruta = new Ruta(id);
            ListaRutas->ingresaObjeto(ruta);
        }
        }
        else {
            throw new Excepcion();
        }

    }
        catch (Excepcion* e) {
            e->cargaArchivo("rutas");
        }

        catch (...) {
            cout << "Error indeterminado" << endl;
        }

        Rutas.close();
        return ListaRutas;
}

Lista* Lista::cargaBuses(Lista* ListaBuses) {
    string nada, id, nombre, asientos, cap, rutaS;
    Nodo* primero = actual; 
    ifstream Buses("buses.txt", ios::in);
    try {
        if (Buses) {
        getline(Buses, nada, DELIMITACAMPO);

        while (!Buses.eof()) {
        getline(Buses, id, DELIMITACAMPO);
        getline(Buses, nombre, DELIMITACAMPO);
        getline(Buses, asientos, DELIMITACAMPO);
        getline(Buses, cap, DELIMITACAMPO);
        getline(Buses, rutaS, DELIMITACAMPO);

        int asientosOcupados = converteAint(asientos);
        int capacidad = converteAint(cap);

        Ruta* ruta = new Ruta(rutaS);
        Object* tiquet = new Bus(id, nombre, asientosOcupados, capacidad, ruta);
        ListaBuses->ingresaObjeto(tiquet);
        }


        }

        else {
            throw new Excepcion();
        }

    }
    catch (Excepcion* e) {
        e->guardaArchivo("buses");
    }

    catch (...) {
        cout << "Error indeterminado" << endl;
    }

    Buses.close();
    return ListaBuses;
}

Lista* Lista::cargaTiquetes(Lista* ListaTiquetes) {

    string nada, id, ruta, bus, cedula;
    Nodo* primero = actual;
    ifstream Tiquetes("tiquetes.txt", ios::in);

    try {
        if (Tiquetes) {
        getline(Tiquetes, nada, DELIMITACAMPO);

        while (!Tiquetes.eof()) {
            getline(Tiquetes, id, DELIMITACAMPO);
            getline(Tiquetes, ruta, DELIMITACAMPO);
            getline(Tiquetes, bus, DELIMITACAMPO);
            getline(Tiquetes, cedula, DELIMITACAMPO);

            Object* tiquet = new Tiquete(id, ruta, bus, cedula);
            ListaTiquetes->ingresaObjeto(tiquet);

        }
        }

        else {
            throw new Excepcion();
        }

    }

    catch (Excepcion* e) {
        e->guardaArchivo("tiquetes");
    }

    catch (...) {
        cout << "Error indeterminado" << endl;
    }

    Tiquetes.close();
    return ListaTiquetes;
}
