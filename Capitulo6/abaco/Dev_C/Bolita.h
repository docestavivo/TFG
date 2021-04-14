#ifndef BOLITA_H
#define BOLITA_H
#include <string> 
#include <sstream>
using namespace std;

namespace patch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}

class Bolita {

	/*ATRIBUTOS*/


public:
	Bolita();
	Bolita(string color);

	string getColor();

private:
	string color;
};

#endif
