#include "stdafx.h"
#include "NodoPila.h"
#include <iostream> 
#include <string>

using namespace std;

// CONSTRUCTOR pone los atributos del nodo al valor recibido.

NodoPila::NodoPila(string colorBola, NodoPila *sig)
{
	colorBolita = colorBola;
	siguiente = sig;
}

string NodoPila::getColorPila()
{
	return colorBolita;
}
