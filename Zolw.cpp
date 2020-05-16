#include <iostream>
#include "Swiat.h"
#include "Zolw.h"

using namespace std;

Zolw::Zolw(int x, int y) : Zwierze(x, y)
{
	nazwa = "zolw";
	inicjatywa = 1;
	sila = 2;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

void Zolw::Akcja(Swiat *swiat)
{
	const int SZANSE_NA_POZOSTANIE_W_MIEJSCU_W_PROCENTACH = 75;
	int czyStoiWMiejscu = rand() % 100 < SZANSE_NA_POZOSTANIE_W_MIEJSCU_W_PROCENTACH;
	if (czyStoiWMiejscu)
		return;

	bool czySiePoruszyl = false;
	while (!czySiePoruszyl)
		czySiePoruszyl = sprubojWykonacRuch(swiat);
}

void Zolw::Kolizja(Swiat *swiat, Organizm *organizm)
{
	Zwierze::Kolizja(swiat, organizm);
	if (dynamic_cast<Zwierze *>(organizm) != nullptr)
		if (organizm -> GetSila() < 5)
		{
			((Zwierze *)(organizm)) -> Cofnij();
			swiat -> DodajKomunikat(nazwa + " odpiera atak " + organizm -> GetNazwa());
		}
}

Zolw *Zolw::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Zolw(x, y);
}