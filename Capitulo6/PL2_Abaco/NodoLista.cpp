#include "stdafx.h"
#include "NodoLista.h"
#include "Pila.h"


NodoLista::NodoLista(Pila colum, char nom) {
	columna = colum;
	nombre = nom;

	siguiente = NULL;
	anterior = NULL;


}

char NodoLista::getNombre() {
	return nombre;
}

Pila NodoLista::getColumna() {
	return columna;
}

