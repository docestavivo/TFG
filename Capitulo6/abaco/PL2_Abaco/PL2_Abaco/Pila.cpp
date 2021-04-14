#include "stdafx.h"
#include "Pila.h"

//constructor, pone la cima a null
Pila::Pila()
{
	cima = NULL;
	nombre = 'X';
}

Pila::~Pila() {
	if (!esVacia()) {
		NodoPila *actual = cima;
		NodoPila *temp;
		while (actual != 0) {
			temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
	}
}

// recibe color y apila
void Pila::apilar(string color)
{
	// nuevo puntero a NodoPila
	pnodoPila nuevo;
	/* Crear un nodo nuevo, el campo siguiente del nodo nuevo sera nuestra actual cima */
	nuevo = new NodoPila(color, cima);
	/* la cima de nuestra pila es en nuevo nodo */
	cima = nuevo;
}




//metodo para sacar el puntero a nodo de la cima (no saca elemento).
string Pila::verCima()
{
	return cima->getColorPila();
}


//quita la cima de la pila 
void Pila::desapilar()
{

	if (!esVacia()) // si no esta vacia
	{
		//pnodoPila auxiliar para liberar el nodo que desapilemos
		pnodoPila aux;
		// el aux apunta a la cima
		aux = cima;
		// la nueva cima es el siguiente en la pila
		cima = cima->siguiente;
		//evitar el borradoo en cascada
		aux->siguiente = NULL;
		//liberamos de memoria el nodo borrado
		delete (aux);
	}


}

// comprueba si la pila esta vacia.
bool Pila::esVacia()
{
	if (cima == NULL)
		return true;

	return false;

}

int Pila::tamanoPila() {

	pnodoPila aux;
	int n = 0;
	aux = NULL;

	if (aux == NULL) {
		return n;
	}
	else {
		aux = cima;  // -->>Me daba error en el Visual Studio de que no iniciaba AUX con un valor.
		while (aux != NULL) {
			aux = aux->siguiente;
			n++;
		}
	}

	return n;
}


pnodoPila Pila::getcima() {
	return cima;
}








