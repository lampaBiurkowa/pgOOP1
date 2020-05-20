#include "conio.h"
#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(int x, int y) : Zwierze(x, y)
{
	nazwa = "czlowiek";
	inicjatywa = 4;
	sila = 5;
	znakASCII = IDENTYFIKATOR_PLIKU;
	iloscTurDoUzyciaSupermocy = 0;
	pozostalaIloscTurZSupermoca = 0;
}

void Czlowiek::WczytajInformacjeORuchu(Swiat *swiat)
{
	bool wyborPoprawny = false;
	int krok = czyDzialaSupermoc() ? KROK_Z_SUPERMOCA : STANDARDOWY_KROK;
	char wybor;
	while (!wyborPoprawny)
	{
		wybor = _getch();
		wyborPoprawny = wybor == STRZALKA_KOD_KONTROLNY;

		wybor = _getch();
		if (wybor == STRZALKA_DOL_KOD)
		{
			wybranaZmianaX = 0;
			wybranaZmianaY = krok;
		}
		else if (wybor == STRZALKA_GORA_KOD)
		{
			wybranaZmianaX = 0;
			wybranaZmianaY = -krok;
		}
		else if (wybor == STRZALKA_LEWO_KOD)
		{
			wybranaZmianaX = krok;
			wybranaZmianaY = 0;
		}
		else if (wybor == STRZALKA_PRAWO_KOD)
		{
			wybranaZmianaX = -krok;
			wybranaZmianaY = 0;
		}
		else
			continue;

		wyborPoprawny = swiat -> CzyPunktMiesciSieNaMapie(GetX() + wybranaZmianaX, GetY() + wybranaZmianaY);
	}
}

void Czlowiek::Akcja(Swiat *swiat)
{
	previousX = x;
	previousY = y;
	SprubojPrzesunacO(wybranaZmianaX, wybranaZmianaY, swiat);

	if (GetPozostalaIloscTurZSupermoca() == 0)
	{
		if (GetIloscTurDoUzyciaSupermocy() > 0)
			iloscTurDoUzyciaSupermocy--;

		return;
	}

	aktualizujStanSupermocyPoUzyciu();
}

int Czlowiek::GetIloscTurDoUzyciaSupermocy()
{
	return iloscTurDoUzyciaSupermocy;
}

int Czlowiek::GetPozostalaIloscTurZSupermoca()
{
	return pozostalaIloscTurZSupermoca;
}

void Czlowiek::SetPozostalaIloscTurZSupermoca(int pozostalaIloscTurZSupermoca)
{
	this -> pozostalaIloscTurZSupermoca = pozostalaIloscTurZSupermoca;
}

void Czlowiek::SetIloscTurDoUzyciaSupermocy(int iloscTurDoUzyciaSupermocy)
{
	this -> iloscTurDoUzyciaSupermocy = iloscTurDoUzyciaSupermocy;
}

void Czlowiek::Kolizja(Swiat *swiat, Organizm *organizm)
{
}

bool Czlowiek::czyDzialaSupermoc()
{
	if (pozostalaIloscTurZSupermoca > ILOSC_TUR_Z_WAZNA_SUPERMOCA - ILOSC_TUR_DO_OSLABIENIA_SUPERMOCY)
		return true;
	else if (pozostalaIloscTurZSupermoca > 0 && rand() % 100 < PROCENT_SZANS_NA_SUPERMOC_PO_OSLABIENIU)
		return true;

	return false;
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
	iloscTurDoUzyciaSupermocy = ILOSC_TUR_DO_ODTWORZENIA_SUPERMOCY;
}

Czlowiek *Czlowiek::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Czlowiek(x, y);
}