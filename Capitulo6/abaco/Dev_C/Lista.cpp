#include "Lista.h"

#include <iostream> 

Lista::Lista() {
	cabeza = actual = final = NULL;
	cabeza1 = cabeza2 = final1 = final2 = NULL;
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
		elementos++;
	}
	
	else if (tipoInsercion == 'f')
	{
		aux = new NodoLista(columna, nombre);
		aux->anterior = final;
		final->siguiente = aux;
		final = aux;
		elementos++;
	}
	
	else if (tipoInsercion == 'p') {
		aux = new NodoLista(columna, nombre);
		aux->siguiente = cabeza;
		cabeza->anterior = aux;
		cabeza = aux;
		elementos++;
	}
}

// true si la lista esta vacia.
bool Lista::listaVacia(){
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

void Lista::mostrarLista(){
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

bool Lista::LesVacia(){
	if (cabeza == NULL)
		return true;

	return false;
}

void Lista::concatenarListas(Lista& l1, Lista& l2){
	actual1 = l1.cabeza;
	actual2 = l2.cabeza;
	final2=l2.final;
	char a=70;
	int i;

	for(i=70;i>67;i--){
		cout << "\nEs la columna antigua " << actual1->getNombre();
		actual1->setNombre(a);
		cout << "\nEs la columna nueva " << actual1->getNombre() << "\n";	
		a--;
		actual1 = actual1->siguiente;
	}
	
	actual1 = l1.cabeza;
	while(actual1->siguiente != NULL){
		actual1 = actual1->siguiente;
	}

//	cout << "\nEs la columna " << actual1->getNombre();	
	actual1->siguiente = actual2; // lista1 apunta al primer nodo de la lista
	l2.cabeza=NULL;
	l2.final=NULL;
//	cout << "\nEs la nueva columna " << actual1->siguiente->getNombre();
//	cout << "\nLa lista 2 tiene " << LtamanoPila('C'); 
//	cout << "\nLa lista 1 tiene " << LtamanoPila('E'); 
//	cout << "\nLa lista 1 tiene " << LtamanoPila('C'); 
    //return l1; // lista concatenada queda en lista1 original
}
