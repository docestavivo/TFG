#pragma once
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <stdlib.h>

#include "Pila.h"
#include "NodoLista.h"

class Lista
{
public:
	Lista();
	~Lista();

	void insertarNodo(Pila columna, char nombre, char tipo);
	bool comprobarExistenciaColumna(char buscado);
	bool listaVacia();
	void borrarActual();
	bool borrarColumna(char buscado);
	void mostrarLista();

	void LmeterBolas(char buscado, string color);
	void apilarActual(string color);
	void LsacarBolas(char buscado);
	void desapilarActual();
	int LtamanoPila(char buscado);
	int tamanoActual();

private:
	pnodoLista cabeza, final;
	pnodoLista actual;
	int elementos;

};

#endif



