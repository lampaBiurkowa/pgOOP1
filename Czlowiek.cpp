#include "conio.h"
#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(int x, int y) : Zwierze(x, y)
{
	nazwa = "czlowiek";
	inicjatywa = 4;
	sila = DOMYSLNA_SILA;
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

int Czlowiek::GetIloscTurDoUzyciaSupermocy()
{
	return iloscTurDoUzyciaSupermocy;
}

int Czlowiek::GetPozostalaIloscTurZSupermoca()
{
	return pozostalaIloscTurZSupermoca;
}

void Czlowiek::Kolizja(Swiat *swiat, Organizm *organizm)
{
	if (GetPozostalaIloscTurZSupermoca() == 0)
		return;
		
	for (int i = -ZASIEG_ZNISZCZEN; i <= ZASIEG_ZNISZCZEN; i++)
		for (int j = -ZASIEG_ZNISZCZEN; j <=ZASIEG_ZNISZCZEN ; j++)
		{
			if ((i == 0 && j == 0) || (i != 0 && j != 0) || !swiat -> CzyPunktMiesciSieNaMapie(x + j, y + i))
				continue;

			if (!swiat -> CzyPoleZajete(x + i, y + j))
				continue;

			Organizm *organizm = swiat -> GetOrganizmNaPozycji(x + i, y + j);
			swiat -> DodajKomunikat(nazwa + " zabija " + organizm -> GetNazwa());
			swiat -> UsunOrganizm(organizm);
		}

	aktualizujStanSupermocyPoUzyciu();
}

void Czlowiek::aktualizujStanSupermocyPoUzyciu()
{
	if (GetPozostalaIloscTurZSupermoca() == 1)
		iloscTurDoUzyciaSupermocy = ILOSC_TUR_DO_ODTWORZENIA_SUPERMOCY;

	pozostalaIloscTurZSupermoca--;
}

bool Czlowiek::SprobujAktywowacSuperMoc()
{
	if (GetIloscTurDoUzyciaSupermocy() > 0)
		return false;

	pozostalaIloscTurZSupermoca = ILOSC_TUR_Z_WAZNA_SUPERMOCA;
}

Czlowiek *Czlowiek::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Czlowiek(x, y);
}