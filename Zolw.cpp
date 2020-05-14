#include "Zolw.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

Zolw::Zolw(int x, int y) : Zwierze(x, y)
{
	id = "zolw";
	inicjatywa = 1;
	sila = 2;
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
	if (dynamic_cast<Zwierze *>(organizm) != nullptr)
		if (organizm -> GetSila() < 5)
		{
			((Zwierze *)(organizm)) -> Cofnij();
			swiat -> DodajKomunikat(id + " odpiera atak " + organizm -> GetId());
		}
}

void Zolw::Rysuj()
{
	cout<<"Z";
}

Zolw *Zolw::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Zolw(x, y);
}