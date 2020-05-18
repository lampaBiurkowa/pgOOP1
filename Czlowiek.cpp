#include "conio.h"
#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(int x, int y) : Zwierze(x, y)
{
	nazwa = "czlowiek";
	inicjatywa = 4;
	sila = 5;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

void Czlowiek::Akcja(Swiat *swiat)
{
	bool udaloSiePoruszyc = false;
	char wybor;
	while (!udaloSiePoruszyc)
	{
		wybor = _getch();
		udaloSiePoruszyc = wybor == STRZALKA_KOD_KONTROLNY;

		wybor = _getch();
		if (wybor == STRZALKA_DOL_KOD)
			udaloSiePoruszyc = SprubojPrzesunacO(0, 1, swiat);
		else if (wybor == STRZALKA_GORA_KOD)
			udaloSiePoruszyc = SprubojPrzesunacO(0, -1, swiat);
		else if (wybor == STRZALKA_LEWO_KOD)
			udaloSiePoruszyc = SprubojPrzesunacO(1, 0, swiat);
		else if (wybor == STRZALKA_PRAWO_KOD)
			udaloSiePoruszyc = SprubojPrzesunacO(-1, 0, swiat);
		else
			udaloSiePoruszyc = false;
	}
}

void Czlowiek::Kolizja(Swiat *swiat, Organizm *organizm)
{

}

Czlowiek *Czlowiek::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Czlowiek(x, y);
}