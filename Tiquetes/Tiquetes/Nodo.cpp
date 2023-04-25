#include "Nodo.h"

Nodo::Nodo(Object* ptrH, Nodo* sig)
	:objPtr(ptrH), siguiente(sig) {}

Nodo::~Nodo() {}

Object* Nodo::getObjeto() { 
	return objPtr; }

Nodo* Nodo::getSiguiente() { 
	return siguiente; }

void Nodo::setObjeto(Object* h) { 
	objPtr = h; }

void Nodo::setSiguiente(Nodo* s) { 
	siguiente = s; }
