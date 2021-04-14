#include "stdafx.h"
#include "Lista.h"
#include <iostream> 

Lista::Lista() {
	cabeza = actual = final = NULL;
	elementos = 0;
}

Lista::~Lista() {
	pnodoLista aux;
	while (cabeza) {
		aux = cabeza;
		cabeza = cabeza->siguiente;
		delete aux;
	}
	actual = NULL;
}

void Lista::insertarNodo(Pila columna, char nombre, char tipoInsercion) { //f final    p principio

	NodoLista *aux;

	tipoInsercion;
	if (listaVacia())
	{
		cabeza = new NodoLista(columna, nombre);
		final = cabeza;

	}
	else if (tipoInsercion == 'f')
	{
		aux = new NodoLista(columna, nombre);
		aux->anterior = final;
		final->siguiente = aux;
		final = aux;


	}
	else if (tipoInsercion == 'p') {
		aux = new NodoLista(columna, nombre);
		aux->siguiente = cabeza;
		cabeza->anterior = aux;
		cabeza = aux;


	}
}

// true si la lista esta vacia.
bool Lista::listaVacia()
{
	return cabeza == NULL;
}

void Lista::borrarActual()
{
	if (actual) {
		if (elementos == 1) //solo hay un elemento
		{
			pnodoLista aux;
			aux = cabeza;
			cabeza = NULL;
			final = NULL;
			delete aux;
			elementos--;
		}
		else { //hay mas de un elemento
			if (actual == cabeza) //si es la cabeza
			{
				cabeza = actual->siguiente;
				actual->siguiente->anterior = NULL;
				delete actual;
				elementos--;
			}
			else if (actual == final) //si es el ultimo
			{
				final = actual->anterior;
				actual->anterior->siguiente = NULL;
				delete actual;
				elementos--;
			}
			else //esta entre medias
			{

				actual->anterior->siguiente = actual->siguiente;
				actual->siguiente->anterior = actual->anterior;
				delete actual;
				elementos--;
			}
		}
	}

}

bool Lista::borrarColumna(char buscado)
{
	actual = cabeza;
	while (actual)
	{
		if (actual->getNombre() == buscado)  //columna encontrada
		{
			borrarActual(); //llamamos al metodo de borrar actual
			return true; //ha sido borrado
		}
		actual = actual->siguiente;

	}

}





//comprobar que la columna no exista ya en la lista
bool Lista::comprobarExistenciaColumna(char buscado)
{
	pnodoLista auxiliar = cabeza;
	bool existeColumna = false;
	while (auxiliar)
	{
		if (auxiliar->getNombre() == buscado) //la columna ya esta en la lista
		{
			existeColumna = true;
			return true;
		}
		auxiliar = auxiliar->siguiente;
	}


	return false;


}

void Lista::mostrarLista() {
	pnodoLista aux;
	aux = cabeza;
	while (aux) {
		cout << aux->getNombre() << " -> ";
		aux = aux->siguiente;
	}
	cout << endl;
}

void Lista::apilarActual(string color) {
	return actual->columna.apilar(color);
}

void Lista::LmeterBolas(char buscado, string color) {
	actual = cabeza;

	while (actual)
	{
		if (actual->nombre == buscado) //la columna ya esta en la lista
		{
			apilarActual(color);
		}
		actual = actual->siguiente;
	}

}

void Lista::desapilarActual() {
	return actual->columna.desapilar();
}

void Lista::LsacarBolas(char buscado) {
	actual = cabeza;

	while (actual)
	{
		if (actual->nombre == buscado) //la columna ya esta en la lista
		{
			desapilarActual();
		}
		actual = actual->siguiente;
	}

}



int Lista::tamanoActual() {
	return actual->columna.tamanoPila();
}

int Lista::LtamanoPila(char buscado) {

	actual = cabeza;

	while (actual)
	{
		if (actual->nombre == buscado) //la columna ya esta en la lista
		{
			return tamanoActual();
		}
		actual = actual->siguiente;
	}
}




