#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(int x, int y) : Zwierze(x, y)
{
	nazwa = "antylopa";
	inicjatywa = 4;
	sila = 4;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

void Antylopa::Akcja(Swiat *swiat)
{
	previousX = x;
	previousY = y;
	bool czyUdaloSiePoruszyc = false;
	while (!czyUdaloSiePoruszyc)
		czyUdaloSiePoruszyc = sprubojWykonacRuch(swiat, 2);
}

void Antylopa::Kolizja(Swiat *swiat, Organizm *organizm)
{
	Zwierze::Kolizja(swiat, organizm);

	if (dynamic_cast<Zwierze *>(organizm) == nullptr)
		return;

	bool czyMozeUciec = rand() % (100 / SZANSA_NA_UCIECZKE_W_PROCENTACH);
	if (czyMozeUciec && czyMaGdzieUciec(swiat))
	{
		bool ucieczkaUdana = false;
		while (!ucieczkaUdana)
			ucieczkaUdana = sprobujUciec(swiat);

		swiat -> DodajKomunikat(nazwa + "ucieka przed " + organizm -> GetNazwa());
	}
}

bool Antylopa::czyMaGdzieUciec(Swiat *swiat)
{
	for (int i = -KROK_UCIECZKI; i <= KROK_UCIECZKI; i++)
		for (int j = -KROK_UCIECZKI; j <= KROK_UCIECZKI; j++)
		{
			if ((i == 0 && j == 0) || (i != 0 && j != 0) || !swiat -> CzyPunktMiesciSieNaMapie(previousX + j, previousY + i))
				continue;

			if (!swiat -> CzyPoleZajete(previousX + j, previousY + i))
				return true;
		}

	return false;
}

bool Antylopa::sprobujUciec(Swiat *swiat)
{
	int zmianaX = rand() % (KROK_UCIECZKI * 2 + 1) - KROK_UCIECZKI;
	int zmianaY = rand() % (KROK_UCIECZKI * 2 + 1) - KROK_UCIECZKI;

	if ((zmianaX == 0 && zmianaY == 0) || (zmianaX != 0 && zmianaY != 0))
		return false;

	if (swiat -> CzyPoleZajete (x + zmianaX, y + zmianaY))
		return false;

	return SprubojPrzesunacO(zmianaX, zmianaY, swiat);
}

Antylopa *Antylopa::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Antylopa(x, y);
}