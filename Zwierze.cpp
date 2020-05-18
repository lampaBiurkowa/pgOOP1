#include "Zwierze.h"
#include "Swiat.h"
#include <cstdlib>
#include <ctime>

Zwierze::Zwierze(int x, int y) : Organizm(x, y)
{
	previousX = x;
	previousY = y;
}

void Zwierze::Cofnij()
{
	x = previousX;
	y = previousY;
}

bool Zwierze::SprubojPrzesunacO(int x, int y, Swiat *swiat)
{
	if (!swiat -> CzyPunktMiesciSieNaMapie(this -> x + x, this -> y + y))
		return false;

	this -> x += x;
	this -> y += y;
	return true;
}

void Zwierze::Akcja(Swiat *swiat)
{
	previousX = x;
	previousY = y;
	bool czyUdaloSiePoruszyc = false;
	while (!czyUdaloSiePoruszyc)
		czyUdaloSiePoruszyc = sprubojWykonacRuch(swiat);
}

bool Zwierze::sprubojWykonacRuch(Swiat *swiat, int step)
{
	int zmianaX = rand() % (2 * step + 1) - step;
	int zmianaY = rand() % (2 * step + 1) - step;

	if ((zmianaX == 0 && zmianaY == 0) || (zmianaX != 0 && zmianaY != 0))
		return false;
	
	return SprubojPrzesunacO(zmianaX, zmianaY, swiat);
}

void Zwierze::Kolizja(Swiat *swiat, Organizm *organizm)
{
	if (organizm -> GetNazwa() == nazwa)
	{
		Cofnij();
		if (!czyMaGdzieUstawicPotomka(swiat))
			return;
		bool czyUdaloSieRomznozyc = false;
		while (!czyUdaloSieRomznozyc)
			czyUdaloSieRomznozyc = sprobujDodacPotomka(swiat);

		swiat -> DodajKomunikat("rodzi sie " + nazwa);
	}
}

bool Zwierze::sprobujDodacPotomka(Swiat *swiat)
{
	int zmianaX = rand() % (2 * ZASIEG_USTAWIENIA_POTOMKA + 1) - ZASIEG_USTAWIENIA_POTOMKA;
	int zmianaY = rand() % (2 * ZASIEG_USTAWIENIA_POTOMKA + 1) - ZASIEG_USTAWIENIA_POTOMKA;
	if ((zmianaX == 0 && zmianaY == 0) || (zmianaX != 0 && zmianaY != 0) || !swiat -> CzyPunktMiesciSieNaMapie(x + zmianaX, y + zmianaY))
		return false;

	if (x + zmianaX == previousX && y + zmianaY == previousY)
		return false;

	if (swiat -> CzyPoleZajete(x + zmianaX, y + zmianaY) && swiat -> GetOrganizmNaPozycji(x + zmianaX, y + zmianaY) -> GetNazwa() == nazwa)
		return false;

	Zwierze *zwierze = zwrocInstancjeZwierzecia(x + zmianaX, y + zmianaY);
	swiat -> DodajOrganizm(zwierze);
	return true;
}

bool Zwierze::czyMaGdzieUstawicPotomka(Swiat *swiat)
{
	for (int i = -ZASIEG_USTAWIENIA_POTOMKA; i <= ZASIEG_USTAWIENIA_POTOMKA; i++)
		for (int j = -ZASIEG_USTAWIENIA_POTOMKA; j <= ZASIEG_USTAWIENIA_POTOMKA; j++)
		{
			if ((i == 0 && j == 0) || (i != 0 && j != 0) || x + j == previousX && y + i == previousY || !swiat -> CzyPunktMiesciSieNaMapie(x + j, y + i))
				continue;

			if (!swiat -> CzyPoleZajete(x + j, y + i) || swiat -> GetOrganizmNaPozycji(x + j, y + i) -> GetNazwa() != nazwa)
				return true;
		}

	return false;
}