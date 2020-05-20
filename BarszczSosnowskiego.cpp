#include <iostream>
#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include "Zwierze.h"

using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y) : Roslina(x, y)
{
	nazwa = "Barszcz Sosnowskiego";
	sila = 10;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

void BarszczSosnowskiego::Akcja(Swiat *swiat)
{
	for (int i = -ZASIEG_ZNISZCZEN; i <= ZASIEG_ZNISZCZEN; i++)
		for (int j = -ZASIEG_ZNISZCZEN; j <=ZASIEG_ZNISZCZEN ; j++)
		{
			if ((i == 0 && j == 0) || (i != 0 && j != 0) || !swiat -> CzyPunktMiesciSieNaMapie(x + j, y + i))
				continue;

			if (!swiat -> CzyPoleZajete(x + i, y + j))
				continue;

			Organizm *organizm = swiat -> GetOrganizmNaPozycji(x + i, y + j);
			if (organizm == NULL || dynamic_cast<Zwierze *>(organizm) == nullptr)
				continue;

			swiat -> DodajKomunikat(nazwa + " zabija " + organizm -> GetNazwa());
			swiat -> UsunOrganizm(organizm);
		}
}

void BarszczSosnowskiego::Kolizja(Swiat *swiat, Organizm *organizm)
{
	if (dynamic_cast<Zwierze *>(organizm) != nullptr)
	{
		swiat -> UsunOrganizm(organizm);
		swiat -> DodajKomunikat(organizm -> GetNazwa() + " zjadl " + nazwa + " i nie zyje");
	}
}

BarszczSosnowskiego *BarszczSosnowskiego::zwrocInstancjeRosliny(int x, int y)
{
	return new BarszczSosnowskiego(x, y);
}