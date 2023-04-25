#pragma once
#include <iostream>
#include <sstream>
#include "Object.h"
#include "Lista.h"

using namespace std;

class Ruta:public Object{

public:
	Ruta();
	Ruta(string);
	string getID();
	string toString();
};

