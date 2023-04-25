#pragma once
#include<iostream>
#include <sstream>
#include<exception>
using namespace std;

class Excepcion : public exception { // Mi clase MiExcepción esta heredando de la clase excpetion...
public:
	Excepcion();
	void palabraDigitada();
	void guardaArchivo(string);
	void cargaArchivo(string);
};