#include "Wilk.h"

Wilk::Wilk(int x, int y): Zwierze(x, y)
{
	nazwa = "Wilk";
	sila = 9;
	inicjatywa = 5;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

Wilk *Wilk::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Wilk(x, y);
}