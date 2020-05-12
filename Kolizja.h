#pragma once

#include "Organizm.h"

class Swiat;

class Kolizja
{
	Organizm **kolidujaceOrganizmy;
	int iloscKolidujacychOrganizmow;

	void inicjuj();
public:
	Kolizja();
	void SzukajKolizji(Swiat *swiat, int x, int y);
	bool WystepujeKolizja();
	Organizm **GetKolidujaceOrganizmy();
};