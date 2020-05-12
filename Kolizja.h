#pragma once

#include "Organizm.h"

class Swiat;

class Kolizja
{
	Organizm **kolidujaceOrganizmy;
	int iloscKolidujacychOrganizmow;
public:
	Kolizja(Swiat *swiat, int x, int y);
	bool WystepujeKolizja();
	Organizm **GetKolidujaceOrganizmy();
};