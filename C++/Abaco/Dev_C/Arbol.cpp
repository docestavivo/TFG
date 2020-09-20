#include "table_printer.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include "Arbol.h"
#include "NodoLista.h"
#include <iostream> 


#if defined(USE_BOOST_KARMA)
#include <boost/spirit/include/karma.hpp>
namespace karma = boost::spirit::karma;
#endif
using bprinter::TablePrinter;


Arbol::Arbol()
{
	numeroNodos = 0;
	raiz = NULL;	
}


//sacado de los apuntes
void Arbol::insertarNodo(long numero)
{
    NodoArbol *padre = NULL;
    NodoArbol *actual = NULL;
    actual = raiz;
    while(!esVacio(actual) && numero!=actual->numero){
    	padre=actual;
    	if(numero > actual->numero){
    		actual=actual->derecho;
		}else{
			if(numero<actual->numero){
				actual=actual->izquierdo;
			}
		}
	}
	if(!esVacio(actual)){
		return;
	}if(esVacio(padre)){
		raiz = new NodoArbol(numero);
	}else if(numero<padre->numero){
		padre->izquierdo = new NodoArbol(numero);	
	}else if(numero>padre->numero){
		padre->derecho = new NodoArbol(numero);
	}
    numeroNodos++;

}


void Arbol::inOrden(NodoArbol * actual)
{

	if (actual != NULL)
	{
		inOrden(actual->izquierdo);
		cout << " (" << actual->numero << "), "<< " ";

		inOrden(actual->derecho);
	}

}

void Arbol::preOrden(NodoArbol * actual)
{
	if (actual)
	{
		cout << " (" << actual->numero << "), "<< " ";
		preOrden(actual->izquierdo);
		preOrden(actual->derecho);
	}
}

void Arbol::postOrden(NodoArbol * actual)
{
	if (actual != NULL)
	{

		postOrden(actual->izquierdo);
		postOrden(actual->derecho);
		cout << " (" << actual->numero << "), "<< " ";

	}
}



bool Arbol::esVacio(NodoArbol * actual)
{
	return actual == NULL;
}


NodoArbol * Arbol::verRaiz()
{
	return raiz;
}

//Sacado de http://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way

void Arbol::mostrarArbol(NodoArbol * nodo, int indent){
	 if (nodo != NULL) {
        if (nodo->derecho) 
            mostrarArbol(nodo->derecho, indent + 2);
        if (nodo->izquierdo) 
            mostrarArbol(nodo->izquierdo, indent + 2);
        if (indent) 
            cout << setw(indent) << ' ';
        cout << "(" << nodo->numero << ")" << "\n ";
    }
}

bool Arbol::buscarNumero(long num){
	NodoArbol *actual = NULL;
	actual=raiz;
	while(!esVacio(actual)){
		if(num == actual->numero){
			return true;
		}else if(num > actual->numero){
			actual=actual->derecho;
		}else if(num < actual->numero){
			actual=actual->izquierdo;
		}	
	}
	return false;
}
