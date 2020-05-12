#pragma once

#include "Organizm.h"

class Swiat;

class Kolizja
{
	const int MAX_ORGANIZMOW_KOLIDUJACYCH = 2;
	int iloscKolidujacychOrganizmow;
	Organizm **kolidujaceOrganizmy;

	void inicjuj();
public:
	Kolizja();
	Organizm **GetKolidujaceOrganizmy();
	void SzukajKolizji(Swiat *swiat, int x, int y);
	bool WystepujeKolizja();
	~Kolizja();
};