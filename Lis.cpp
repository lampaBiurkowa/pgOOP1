#include <iostream>
#include "Lis.h"
#include "Swiat.h"

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

	do
	{
		Cofnij();
		bool czySiePoruszyl = false;
		while (!czySiePoruszyl)
			czySiePoruszyl = sprubojWykonacRuch(swiat);
	} while (swiat -> CzyPoleZajete(x, y) && swiat -> GetOrganizmNaPozycji(x, y) -> GetSila() > sila);

}

bool Lis::czyMozeSieRuszyc(Swiat *swiat)
{
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (previousX + j < 0 || previousX + j >= swiat -> GetSzerokosc() || previousY + i < 0 || previousY + i >= swiat -> GetWysokosc())
				continue;

			if (!swiat -> CzyPoleZajete(previousX + j, previousY + i))
				return true;
			else if (swiat -> GetOrganizmNaPozycji(previousX + j, previousY + i) -> GetSila() <= sila)
				return true;
		}

	return false;
}

void Lis::Rysuj()
{
	cout<<"L";
}

Lis *Lis::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Lis(x, y);
}