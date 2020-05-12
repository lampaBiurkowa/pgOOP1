#include <iostream>
#include "BarszczSosnowskiego.h"
#include "Swiat.h"

using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y) : Roslina(x, y)
{
	id = "barszczSosnowskiego";
	sila = 10;
}

void BarszczSosnowskiego::Akcja(Swiat *swiat)
{
	for (int i = -1; i < 2; i++)
		for (int j = - 1; j < 2; j++)
			if (swiat -> CzyPoleZajete(x + i, y + j) && (i != 0 || j != 0))
			{
				Organizm *organizm = swiat -> GetOrganizmNaPozycji(x + i, y + j);
				if (organizm == NULL)
					continue;

				swiat -> DodajKomunikat(id + " zabija " + organizm -> GetId());
				swiat -> UsunOrganizm(organizm);
			}
}

void BarszczSosnowskiego::Kolizja(Swiat *swiat, Organizm *organizm)
{
	swiat -> UsunOrganizm(organizm);
	swiat -> DodajKomunikat(organizm -> GetId() + " zjadl " + id + " i nie zyje");
}

void BarszczSosnowskiego::Rysuj()
{
	cout<<"b";
}

BarszczSosnowskiego *BarszczSosnowskiego::zwrocInstancjeRosliny(int x, int y)
{
	return new BarszczSosnowskiego(x, y);
}