#pragma once
#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Pila.h"

class NodoLista
{
public:
	NodoLista(Pila colum, char nom); //constructor
	Pila columna;
	char nombre;
	char getNombre();
	Pila getColumna();


private:
	NodoLista *siguiente;
	NodoLista *anterior;
	friend class Lista;
	friend class Abaco;
};

typedef NodoLista *pnodoLista;

#endif


