#pragma once
#include <iostream>
#include <sstream>

using namespace std;
//Principio de responsabilidad unica
class Object{

protected:
	string id;

public:
	virtual string getID() = 0;
	virtual string toString() = 0;
};

