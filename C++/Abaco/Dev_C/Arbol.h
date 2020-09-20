#ifndef ARBOL_H
#define ARBOL_H

#include "NodoArbol.h"
#include <iostream>
#include <stdlib.h>

#include "table_printer.h"
#define _USE_MATH_DEFINES
#include <math.h>


#include "Arbol.h"
#include <iostream> 


#if defined(USE_BOOST_KARMA)
#include <boost/spirit/include/karma.hpp>
namespace karma = boost::spirit::karma;
#endif
using bprinter::TablePrinter;

class Arbol
{
public:
	Arbol();
	bool esVacio(NodoArbol * nodo);
	NodoArbol * verRaiz();

	void insertarNodo(long numero);
		
	void inOrden(NodoArbol * nodo);
	void preOrden(NodoArbol * nodo);
	void postOrden(NodoArbol * nodo);
	bool buscarNumero(long num);
	void mostrarArbol(NodoArbol * nodo, int indent);
	

private:
	NodoArbol * raiz;
	int numeroNodos;
};

#endif
