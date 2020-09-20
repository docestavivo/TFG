#include <cstring>
#include <string>
#include <iostream>

using namespace std;
#include "Abaco.h"
#include "pila.h"
#include "lista.h"


void Abaco::separar_numero(int& numero, int& c, int& d, int& u) {
	c = numero / 100;
	d = (numero - (c * 100)) / 10;
	u = (numero - (c * 100 + d * 10));

	cout << c << " - " << d << " - " << u << "\n";

}

void Abaco::introducirColumnas(Lista& l) {
	l.insertarNodo(unidades, 'A', 'p');
	l.insertarNodo(decenas, 'B', 'p');
	l.insertarNodo(centenas, 'C', 'p');
}

void Abaco::introducirBolitasEnAbaco(Lista& l, int un, int de, int ce)
{
	while (un != 0) {
		l.LmeterBolas('A', "azul");
		un--;
	}

	while (de != 0) {
		l.LmeterBolas('B', "morado");
		de--;
	}

	while (ce != 0) {
		l.LmeterBolas('C', "amarillo");
		ce--;
	}
}

void Abaco::verEstadoPilas(Lista& l) {
	cout << "Hay " << l.LtamanoPila('A') << " bolitas azules. (UNIDADES)";
	cout << "\nHay " << l.LtamanoPila('B') << " bolitas moradas. (DECENAS)";
	cout << "\nHay " << l.LtamanoPila('C') << " bolitas amarillas. (CENTENAS)";
	cout << "\nHay " << l.LtamanoPila('D') << " bolitas azules. (UNIDADES DE MILLAR)";
	cout << "\nHay " << l.LtamanoPila('E') << " bolitas moradas. (DECENAS DE MILLAR)";
	cout << "\nHay " << l.LtamanoPila('F') << " bolitas amarillas. (CENTENAS DE MILLAR)\n";
}

void Abaco::vaciarLista(Lista labaco) {
	labaco.~Lista();
}

bool Abaco::abacoEstaVacio(Lista& l){
	if(l.LesVacia()){
		return true;
	}
	return false;
}

void Abaco::juntarAbacos(Lista& lista1, Lista& lista2){
	lista1.concatenarListas(lista1, lista2);
}

long Abaco::bolasANumero(Lista& list){
	int f,e,d,c,b,a;
	long numero;
	
	f = list.LtamanoPila('F')*100000;
	e = list.LtamanoPila('E')*10000;
	d = list.LtamanoPila('D')*1000;
	c = list.LtamanoPila('C')*100;
	b = list.LtamanoPila('B')*10;
	a = list.LtamanoPila('A');
	
	numero = f+d+e+c+b+a;
	
	return numero;
}

void Abaco::introducirNumeroArbol(long num){
	abin.insertarNodo(num);
}

void Abaco::imprimirArbol(){
	abin.mostrarArbol(abin.verRaiz(), 0);
}

bool Abaco::buscarNumeroEnArbol(long num){
	return abin.buscarNumero(num);
}
