#include "stdafx.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
#include <array>
#include "Abaco.h"
#include "pila.h"
#include "lista.h"


void Abaco::separar_numero(int& numero, int& c, int& d, int& u) {
	c = numero / 100;
	d = (numero - (c * 100)) / 10;
	u = (numero - (c * 100 + d * 10));

	cout << c << " - " << d << " - " << u << "\n";

}

void Abaco::introducirColumnas(Lista l) {
	l.insertarNodo(unidades, 'A', 'p');
	l.insertarNodo(decenas, 'B', 'p');
	l.insertarNodo(centenas, 'C', 'p');
}

void Abaco::introducirBolitasEnAbaco(Lista &l, int un, int de, int ce)
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

void Abaco::verEstadoPilas(Lista labaco) {
	cout << "\nHay " << labaco.LtamanoPila('A') << " bolitas azules. (UNIDADES)";
	cout << "\nHay " << labaco.LtamanoPila('B') << " bolitas moradas. (DECENAS)";
	cout << "\nHay " << labaco.LtamanoPila('C') << " bolitas amarillas. (CENTENAS)";
}

void Abaco::vaciarLista(Lista labaco) {
	labaco.~Lista();
}





//void Abaco::sumaPila(int bolasMeter, char pila, char pilaSiguiente, int bolas) {
//	int tamano = labaco.LtamanoPila(pila);
//	int i = 0;
//
//	if (bolasMeter == 0) {
//		cout << "Hay " << tamano << " bolas. \n";
//	}
//	else {
//		labaco.LmeterBolas(pila, "azul");
//		tamano++;
//		bolasMeter--;
//		if (tamano<(bolas)) {
//			if (tamano == bolas) {
//				sumaPila(bolasMeter, pila, pilaSiguiente, bolas);
//			}
//			else {
//				sumaPila(bolasMeter, pila, pilaSiguiente, bolas);
//			}
//		}if (tamano >= (bolas) && (pila != 'E')) {
//			for (i; (i<bolas); i += 1) {
//				labaco.LsacarBolas(pila);
//				tamano--;
//			}
//			labaco.LmeterBolas(pilaSiguiente, "morada");
//			sumaPila(bolasMeter, pila, pilaSiguiente, bolas);
//		}
//	}
//
//}
//
//void Abaco::suma(int u2, int d2, int c2, int mu2, int md2, int bolas) {
//
//	sumaPila(u2, 'A', 'B', bolas);
//	sumaPila(d2, 'B', 'C', bolas);
//	sumaPila(c2, 'C', 'D', bolas);
//	sumaPila(mu2, 'D', 'E', bolas);
//	sumaPila(md2, 'E', 'E', bolas);
//
//}
//
//void Abaco::restaPila(int bolasSacar, char pila, char pilaSiguiente, int bolas) {
//	int tamano = labaco.LtamanoPila(pila);
//	int tamanosig = labaco.LtamanoPila(pilaSiguiente);
//	int i = 0;
//
//	while (bolasSacar != 0) {
//		if (tamano>bolasSacar) {
//			labaco.LsacarBolas(pila);
//			tamano--;
//			bolasSacar--;
//		}if (tamano<bolasSacar && pila != 'E') {
//			if (tamano != bolas) {
//				while (tamano != 0) {
//					labaco.LsacarBolas(pila);
//					tamano--;
//					bolasSacar--;
//				}
//				labaco.LsacarBolas(pilaSiguiente);
//				for (i = 0; tamano<bolas; i++) {
//					labaco.LmeterBolas(pila, "azul");
//					tamano++;
//				}
//			}
//		}
//	}
//
//	cout << "Hay " << tamano << " bolas.\n";
//
//}
//
//
//void Abaco::resta(int u2, int d2, int c2, int mu2, int md2, int bolas) {
//
//	restaPila(u2, 'A', 'B', bolas);
//	restaPila(d2, 'B', 'C', bolas);
//	restaPila(c2, 'C', 'D', bolas);
//	restaPila(mu2, 'D', 'E', bolas);
//	restaPila(md2, 'E', 'E', bolas);
//}
//
//bool Abaco::separar_hexadecimal(string hexa, int& dm, int& um, int& c, int& d, int& u) {
//	int n;
//	char x;
//	bool correcto = true;
//
//	for (int i = 0; hexa[i] != '\0'; i++) {
//		n = (int)hexa[i];
//		if (i == 4) {
//			if (n == 65 || n == 97) {
//				u = 10;
//			}
//			else if (n == 66 || n == 98) {
//				u = 11;
//			}
//			else if (n == 67 || n == 99) {
//				u = 12;
//			}
//			else if (n == 68 || n == 100) {
//				u = 13;
//			}
//			else if (n == 69 || n == 101) {
//				u = 14;
//			}
//			else if (n == 70 || n == 102) {
//				u = 15;
//			}
//			else if (n == 48) {
//				u = 0;
//			}
//			else if (n == 49) {
//				u = 1;
//			}
//			else if (n == 50) {
//				u = 2;
//			}
//			else if (n == 51) {
//				u = 3;
//			}
//			else if (n == 52) {
//				u = 4;
//			}
//			else if (n == 53) {
//				u = 5;
//			}
//			else if (n == 54) {
//				u = 6;
//			}
//			else if (n == 55) {
//				u = 7;
//			}
//			else if (n == 56) {
//				u = 8;
//			}
//			else if (n == 57) {
//				u = 9;
//			}
//			else {
//				correcto = false;
//			}
//		}if (i == 3) {
//			if (n == 65 || n == 97) {
//				um = 10;
//			}
//			else if (n == 66 || n == 98) {
//				d = 11;
//			}
//			else if (n == 67 || n == 99) {
//				d = 12;
//			}
//			else if (n == 68 || n == 100) {
//				d = 13;
//			}
//			else if (n == 69 || n == 101) {
//				d = 14;
//			}
//			else if (n == 70 || n == 102) {
//				d = 15;
//			}
//			else if (n == 48) {
//				d = 0;
//			}
//			else if (n == 49) {
//				d = 1;
//			}
//			else if (n == 50) {
//				d = 2;
//			}
//			else if (n == 51) {
//				d = 3;
//			}
//			else if (n == 52) {
//				d = 4;
//			}
//			else if (n == 53) {
//				d = 5;
//			}
//			else if (n == 54) {
//				d = 6;
//			}
//			else if (n == 55) {
//				d = 7;
//			}
//			else if (n == 56) {
//				d = 8;
//			}
//			else if (n == 57) {
//				d = 9;
//			}
//			else {
//				correcto = false;
//			}
//		}if (i == 2) {
//			if (n == 65 || n == 97) {
//				c = 10;
//			}
//			else if (n == 66 || n == 98) {
//				c = 11;
//			}
//			else if (n == 67 || n == 99) {
//				c = 12;
//			}
//			else if (n == 68 || n == 100) {
//				c = 13;
//			}
//			else if (n == 69 || n == 101) {
//				c = 14;
//			}
//			else if (n == 70 || n == 102) {
//				c = 15;
//			}
//			else if (n == 48) {
//				c = 0;
//			}
//			else if (n == 49) {
//				c = 1;
//			}
//			else if (n == 50) {
//				c = 2;
//			}
//			else if (n == 51) {
//				c = 3;
//			}
//			else if (n == 52) {
//				c = 4;
//			}
//			else if (n == 53) {
//				c = 5;
//			}
//			else if (n == 54) {
//				c = 6;
//			}
//			else if (n == 55) {
//				c = 7;
//			}
//			else if (n == 56) {
//				c = 8;
//			}
//			else if (n == 57) {
//				c = 9;
//			}
//			else {
//				correcto = false;
//			}
//		}if (i == 1) {
//			if (n == 65 || n == 97) {
//				um = 10;
//			}
//			else if (n == 66 || n == 98) {
//				um = 11;
//			}
//			else if (n == 67 || n == 99) {
//				um = 12;
//			}
//			else if (n == 68 || n == 100) {
//				um = 13;
//			}
//			else if (n == 69 || n == 101) {
//				um = 14;
//			}
//			else if (n == 70 || n == 102) {
//				um = 15;
//			}
//			else if (n == 48) {
//				um = 0;
//			}
//			else if (n == 49) {
//				um = 1;
//			}
//			else if (n == 50) {
//				um = 2;
//			}
//			else if (n == 51) {
//				um = 3;
//			}
//			else if (n == 52) {
//				um = 4;
//			}
//			else if (n == 53) {
//				um = 5;
//			}
//			else if (n == 54) {
//				um = 6;
//			}
//			else if (n == 55) {
//				um = 7;
//			}
//			else if (n == 56) {
//				um = 8;
//			}
//			else if (n == 57) {
//				um = 9;
//			}
//			else {
//				correcto = false;
//			}
//		}if (i == 0) {
//			if (n == 65 || n == 97) {
//				dm = 10;
//			}
//			else if (n == 66 || n == 98) {
//				dm = 11;
//			}
//			else if (n == 67 || n == 99) {
//				dm = 12;
//			}
//			else if (n == 68 || n == 100) {
//				dm = 13;
//			}
//			else if (n == 69 || n == 101) {
//				dm = 14;
//			}
//			else if (n == 70 || n == 102) {
//				dm = 15;
//			}
//			else if (n == 48) {
//				dm = 0;
//			}
//			else if (n == 49) {
//				dm = 1;
//			}
//			else if (n == 50) {
//				dm = 2;
//			}
//			else if (n == 51) {
//				dm = 3;
//			}
//			else if (n == 52) {
//				dm = 4;
//			}
//			else if (n == 53) {
//				dm = 5;
//			}
//			else if (n == 54) {
//				dm = 6;
//			}
//			else if (n == 55) {
//				dm = 7;
//			}
//			else if (n == 56) {
//				dm = 8;
//			}
//			else if (n == 57) {
//				dm = 9;
//			}
//			else {
//				correcto = false;
//
//			}
//		}
//	}
//
//	cout << dm << " - " << d << " - " << u << "\n";
//	return correcto;
//
//}






