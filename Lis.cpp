#include "Lis.h"
#include "Swiat.h"

Lis::Lis(int x, int y) : Zwierze(x, y)
{
	nazwa = "lis";
	inicjatywa = 7;
	sila = DOMYSLNA_SILA;
	znakASCII = IDENTYFIKATOR_PLIKU;
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
	const int KROK = 1;
	for (int i = -KROK; i <= KROK; i++)
		for (int j = -KROK; j <= KROK; j++)
		{
			if ((i == 0 && j == 0) || (i != 0 && j != 0) || !swiat -> CzyPunktMiesciSieNaMapie(previousX + j, previousY + i))
				continue;

			if (!swiat -> CzyPoleZajete(previousX + j, previousY + i))
				return true;
			else if (swiat -> GetOrganizmNaPozycji(previousX + j, previousY + i) -> GetSila() <= sila)
				return true;
		}

	return false;
}

Lis *Lis::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Lis(x, y);
}