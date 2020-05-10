#include "Trawa.h"
#include <iostream>

using namespace std;

Trawa::Trawa(unsigned int x, unsigned int y) : Roslina(x, y)
{
	id = "trawa";
	sila = 0;
}

Roslina* Trawa::zwrocInstancjeRosliny(unsigned int x, unsigned int y)
{
	return new Trawa(x, y);
}

void Trawa::Rysuj()
{
	cout<<"t";
}