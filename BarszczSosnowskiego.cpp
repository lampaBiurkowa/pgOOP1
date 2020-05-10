#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(unsigned int x, unsigned int y) : Roslina(x, y)
{
	id = "barszczSosnowskiego";
	sila = 10;
}

Roslina *BarszczSosnowskiego::zwrocInstancjeRosliny(unsigned int x, unsigned int y)
{
	return new BarszczSosnowskiego(x, y);
}

void BarszczSosnowskiego::Akcja(Swiat *swiat)
{
	for (int i = -1; i < 2; i++)
		for (int j = - 1; j < 2; j++)
			if (swiat -> CzyPoleZajete(x + i, y + j))
				swiat -> UsunOrganizm(swiat -> GetOrganizmNaPozycji(x + i, y + j));
}

void BarszczSosnowskiego::Kolizja(Swiat *swiat, Organizm *organizm)
{
	swiat -> UsunOrganizm(organizm);
}

void BarszczSosnowskiego::Rysuj()
{
	cout<<"b";
}