#ifndef ABACO_H
#define ABACO_H
#include <iostream>

using namespace std;
#include "pila.h"
#include "lista.h"
#include "arbol.h"

class Abaco{
public:
	//abaco();
	void introducirColumnas(Lista& l);
	void introducirBolitasEnAbaco(Lista& l, int un, int de, int ce);
	void separar_numero(int& numero, int& c, int& d, int& u);
	//bool separar_hexadecimal(string hexa, int& dm, int& um, int& c, int& d, int& u);
	void verEstadoPilas(Lista& l);
	/*void suma(int u2, int d2, int c2, int mu2, int md2, int bolas);
	void resta(int u2, int d2, int c2, int mu2, int md2, int bolas);*/
	void vaciarLista(Lista labaco);
	bool abacoEstaVacio(Lista& l);
	void juntarAbacos(Lista& lista1, Lista& lista2);
	long bolasANumero(Lista& list);
	void introducirNumeroArbol(long num);
	void imprimirArbol();
	bool buscarNumeroEnArbol(long num);

	/*void sumaPila(int bolasMeter, char pila, char pilaSiguiente, int bolas);
	void restaPila(int bolasSacar, char pila, char pilaSiguiente, int bolas);*/

private:
	//Lista labaco;
	Arbol abin;
	Pila unidades;
	Pila decenas;
	Pila centenas;
	//Pila umillar;
	//Pila dmillar;

protected:
};

#endif
