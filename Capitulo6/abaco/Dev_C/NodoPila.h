#ifndef NODOPILA_H
#define NODOPILA_H

#include <iostream> 
#include <string>

using namespace std;

class NodoPila
{

public:
	NodoPila(string colorBola, NodoPila *sig);
	string getColorPila();


private:
	string colorBolita;
	NodoPila *siguiente;
	friend class Pila;
};

typedef NodoPila *pnodoPila;


#endif
