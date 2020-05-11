#include "Lis.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

Lis::Lis(int x, int y): Zwierze(x, y)
{
	id = "lis";
	inicjatywa = 7;
	sila = 3;
}

void Lis::Akcja(Swiat *swiat)
{
	previousX = x;
	previousY = y;

	if (!czyMozeSieRuszyc(swiat))
		return;

	while (swiat -> CzyPoleZajete(x, y) && swiat -> GetOrganizmNaPozycji(x, y) -> GetSila() > sila)
	{
		Cofnij();
		sprubojWykonacRuch(swiat);
	}
}

bool Lis::czyMozeSieRuszyc(Swiat *swiat)
{
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0)
				continue;

			if (!swiat -> CzyPoleZajete(previousX + i, previousY + j))
				return true;
			else if (swiat -> GetOrganizmNaPozycji(previousX + i, previousY + j) -> GetSila() <= sila)
				return true;
		}

	return false;
}

void Lis::Rysuj()
{
	cout<<"L";
}