#pragma once
#ifndef PILA_H
#define PILA_H

#include "NodoPila.h"

#include <iostream>
#include <stdlib.h>


class Pila {


public:
	Pila();
	~Pila();

	void apilar(string color);
	void desapilar();
	bool esVacia();
	string verCima();
	int tamanoPila();
	pnodoPila getcima();

private:
	pnodoPila cima;
	char nombre;
};


#endif



