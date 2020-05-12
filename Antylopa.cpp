#include <iostream>
#include "Antylopa.h"
#include "Swiat.h"

using namespace std;

Antylopa::Antylopa(int x, int y) : Zwierze(x, y)
{
	id = "antylopa";
	inicjatywa = 4;
	sila = 4;
}

void Antylopa::Akcja(Swiat *swiat)
{
	previousX = x;
	previousY = y;
	bool moved = false;
	while (!moved)
		moved = sprubojWykonacRuch(swiat, 2);
}

void Antylopa::Kolizja(Swiat *swiat, Organizm *organizm)
{
	const int SZANSA_NA_UCIECZKE_W_PROCENTACH = 50;
	bool czyMozeUciec = rand() % (100 / SZANSA_NA_UCIECZKE_W_PROCENTACH);
	if (czyMozeUciec && czyMaGdzieUciec(swiat))
	{
		bool ucieczkaUdana = false;
		while (!ucieczkaUdana)
			ucieczkaUdana = sprobujUciec(swiat);

		swiat -> DodajKomunikat(id + "ucieka przed " + organizm -> GetId());
	}
}

bool Antylopa::czyMaGdzieUciec(Swiat *swiat)
{
	for (int i = -KROK_UCIECZKI; i <= KROK_UCIECZKI; i++)
		for (int j = -KROK_UCIECZKI; j <= KROK_UCIECZKI; j++)
		{
			if (i == 0 && j == 0)
				continue;

			if (!swiat -> CzyPoleZajete(previousX + i, previousY + j))
				return true;
		}

	return false;
}

bool Antylopa::sprobujUciec(Swiat *swiat)
{
	int zmianaX = rand() % (KROK_UCIECZKI * 2 + 1) - KROK_UCIECZKI;
	int zmianaY = rand() % (KROK_UCIECZKI * 2 + 1) - KROK_UCIECZKI;

	if (zmianaX == 0 && zmianaY == 0)
		return false;

	if (swiat -> CzyPoleZajete (x + zmianaX, y + zmianaY))
		return false;

	return SprubojPrzesunacO(zmianaX, zmianaY, swiat);
}

void Antylopa::Rysuj()
{
	cout<<"A";
}

Antylopa *Antylopa::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Antylopa(x, y);
}