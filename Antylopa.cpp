#include "Antylopa.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

Antylopa::Antylopa(unsigned int x, unsigned int y) : Zwierze(x, y)
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
	bool czyMozeUciec = rand() % 2;
	if (czyMozeUciec && czyMaGdzieUciec(swiat))
	{
		bool ucieczkaUdana = false;
		while (!ucieczkaUdana)
			ucieczkaUdana = sprubojUciec(swiat);
	}
}

bool Antylopa::czyMaGdzieUciec(Swiat *swiat)
{
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0)
				continue;

			if (!swiat -> CzyPoleZajete(previousX + i, previousY + j))
				return true;
		}

	return false;
}

bool Antylopa::sprubojUciec(Swiat *swiat)
{
	int zmianaX = rand() % 3 - 1;
	int zmianaY = rand() % 3 - 1;

	if (zmianaX == 0 && zmianaY == 0)
		return false;

	if (!swiat -> CzyPoleZajete (x + zmianaX, y + zmianaY))
		return false;

	return SprubojPrzesunacO(zmianaX, zmianaY, swiat);
}

void Antylopa::Rysuj()
{
	cout<<"A";
}