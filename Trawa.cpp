#include <iostream>
#include "Trawa.h"

using namespace std;

Trawa::Trawa(int x, int y) : Roslina(x, y)
{
	nazwa = "Trawa";
	sila = 0;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

Trawa *Trawa::zwrocInstancjeRosliny(int x, int y)
{
	return new Trawa(x, y);
}