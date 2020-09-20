#include "Bolita.h"

#include <iostream>
#include <string>

Bolita::Bolita()
{

}

Bolita::Bolita(string colorr) {
	color = colorr;
}

string Bolita::getColor() {
	return color;
}

