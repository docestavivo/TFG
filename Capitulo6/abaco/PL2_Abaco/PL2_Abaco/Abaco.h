#pragma once

#ifndef ABACO_H
#define ABACO_H
#include <iostream>

using namespace std;
#include <array>
#include "pila.h"
#include "lista.h"

class Abaco
{
public:
	//abaco();
	void introducirColumnas(Lista l);
	void introducirBolitasEnAbaco(Lista &l, int un, int de, int ce);
	void separar_numero(int& numero, int& c, int& d, int& u);
	//bool separar_hexadecimal(string hexa, int& dm, int& um, int& c, int& d, int& u);
	void verEstadoPilas(Lista labaco);
	/*void suma(int u2, int d2, int c2, int mu2, int md2, int bolas);
	void resta(int u2, int d2, int c2, int mu2, int md2, int bolas);*/
	void vaciarLista(Lista labaco);

	/*void sumaPila(int bolasMeter, char pila, char pilaSiguiente, int bolas);
	void restaPila(int bolasSacar, char pila, char pilaSiguiente, int bolas);*/

private:
	Pila unidades;
	Pila decenas;
	Pila centenas;
	//Pila umillar;
	//Pila dmillar;

protected:
};

#endif

