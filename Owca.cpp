#include <iostream>
#include "Owca.h"

using namespace std;

Owca::Owca(int x, int y): Zwierze(x, y)
{
	nazwa = "Owca";
	inicjatywa = 4;
	sila = 4;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

Owca *Owca::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Owca(x, y);
}