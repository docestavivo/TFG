#ifndef NODOARBOL_H
#define NODOARBOL_H


class NodoArbol
{
private:
	
	friend class Arbol;
	NodoArbol *izquierdo;
	NodoArbol *derecho;
		
public:
	long numero;
	NodoArbol(long numero);
};

#endif
