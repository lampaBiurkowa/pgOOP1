#include "Swiat.h"
#include "Zolw.h"

Zolw::Zolw(int x, int y) : Zwierze(x, y)
{
	nazwa = "Zolw";
	inicjatywa = 1;
	sila = 2;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

void Zolw::Akcja(Swiat *swiat)
{
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
		if (organizm -> GetSila() <= MAKSYMALNA_SILA_DO_ODPARCIA)
		{
			((Zwierze *)(organizm)) -> Cofnij();
			swiat -> DodajKomunikat(nazwa + " odpiera atak " + organizm -> GetNazwa());
		}
}

Zolw *Zolw::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Zolw(x, y);
}