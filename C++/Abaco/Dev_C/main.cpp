// PL2_Abaco.cpp : Defines the entry point for the console application.
//
#include <iostream>

#include "Pila.h"
#include "Lista.h"
#include "Abaco.h"

/* PRÁTICA 2 REALIZADA POR:

Nombre: ESTEFANÍA MARTÍN ROJAS
DNI: 73133122-E
Asignatura: ESTRUCTURAS DE DATOS.
Curso: 2017-18 */


int main(int argc, char** argv) {

	Lista labaco0, labaco1, labaco2, labaco3, labaco4, labaco5, labaco6, labaco7, labaco8, labaco9, list1, list2;
	//long numeroAB0, numeroAB1, numeroAB2, numeroAB3, numeroAB4, numeroAB5, numeroAB6, numeroAB7, numeroAB8, numeroAB9;
	Lista arrayAbacos[] = {labaco0, labaco1, labaco2, labaco3, labaco4, labaco5, labaco6, labaco7, labaco8, labaco9};
	//long arrayNumeros[] = {numeroAB0, numeroAB1, numeroAB2, numeroAB3, numeroAB4, numeroAB5, numeroAB6, numeroAB7, numeroAB8, numeroAB9};
	int numero;
	long numeroAB, buscado;
	int narray, n, i;
	int opcion1, opcion2;
	int cen = 0, dec = 0, uni = 0;

		Abaco calculadora;

		cout << "*** BIENVENIDO *** \n";
		cout << "Dispone de 10 abacos. Que abacos desea rellenar? Eliga del 0 al 9.\n";
		cout << "Cuando desee dejar de utilizar abacos, escriba 88.\n";
		while (narray!=88){
			cout << "\nOpcion: ";
			cin >> narray;
			for(n = 0; n<10; ++n){
			//arrayNumeros[n] = 0;
			if (n==narray){
				calculadora.introducirColumnas(arrayAbacos[n]);
				cout << "Ha elegido el abaco numero " << narray << "\n";
				cout << "Introduzca un numero entre el 0 y el 999: \n";
				cin >> numero;
				
				while (numero>999 || numero<0) {
					cout << "\n** ERROR **\n";
					cout << "Introduzca un numero del 0 al 999: ";
					cin >> numero;
				}
				
			//	arrayNumeros[n] = numero;
				calculadora.separar_numero(numero, cen, dec, uni);
				calculadora.introducirBolitasEnAbaco(arrayAbacos[n], uni, dec, cen);
				calculadora.verEstadoPilas(arrayAbacos[n]);
				break;
				}
			}	
		}
		
		cout << "\nHA PULSADO 88.";
		
		cout << "\nEstado de los 10 abacos:";
		for(i = 0; i<10; ++i){
			cout << "\nABACO " << i << ": \n";
			calculadora.verEstadoPilas(arrayAbacos[i]);
		}
		
		cout << "\nQue abacos desea concatenar? Eliga un numero entre el 0 y el 9.:";
		cout << "\nSolo se permiten abacos llenos.";
		cout << "\nIMPORTANTE: Se vaciara la segunda lista.";
		cout << "\nOpcion 1:\n";
		cin >> opcion1;
		while (opcion1<0 || opcion1>9 || (calculadora.abacoEstaVacio(arrayAbacos[opcion1]))){
			cout << "\nERROR.";
			cout << "\nEliga un abaco entre el 0 y el 9 LLENO.";
			cout << "\nOpcion 1:\n";
			cin >> opcion1;
		}
		
		cout << "\nSegundo abaco. Ahora eliga un numero entre el 0 y el 9.";
		cout << "\nSolo se permiten abacos llenos.";
		cout << "\nOpcion 2:\n";
		cin >> opcion2;
		while (opcion2<0 || opcion2>9 || (calculadora.abacoEstaVacio(arrayAbacos[opcion2]))){
			cout << "\nERROR.";
			cout << "\nEliga un abaco entre el 0 y el 9 LLENO.";
			cout << "\nOpcion 2:\n";
			cin >> opcion2;
		}
		
		calculadora.juntarAbacos(arrayAbacos[opcion1], arrayAbacos[opcion2]);
		cout << "\n"
		
		for(i = 0; i<10; ++i){
			numeroAB = calculadora.bolasANumero(arrayAbacos[i]);
			cout << "\nEl numero introducido en la pila " << i << " es " << numeroAB << "\n";
			calculadora.introducirNumeroArbol(numeroAB);
		}
		
		calculadora.imprimirArbol();
		
		cout << "\nQue numero desea buscar en el arbol?:";
		cin >> buscado;
		if (calculadora.buscarNumeroEnArbol(buscado)){
			cout << "\nESTE NUMERO EXISTE.";
		}else{
			cout << "\nESTE NUMERO NO EXISTE.";
		}

		//pausamos
		system("pause");
		//system("cls");
		//limpiamos el stream al haber encontrado errores en pruebas
		fflush(stdin);
		cout << endl << endl;
		
	}
