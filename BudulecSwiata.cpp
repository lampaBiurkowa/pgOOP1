#include <iostream>
#include "Antylopa.h"
#include "BarszczSosnowskiego.h"
#include "BudulecSwiata.h"
#include "Guarana.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Wilk.h"
#include "Zolw.h"

using namespace std;

BudulecSwiata::BudulecSwiata()
{
	iloscGatunkow = 10;
}

void BudulecSwiata::RozstawOrganizmy(Swiat *swiat, int iloscSztuk)
{
	int **pozycje = przygotujPozycjeStartowe(swiat, iloscSztuk);
	for (int i = 0; i < iloscSztuk * iloscGatunkow; i++)
	{
		swiat -> DodajOrganizm(new Antylopa(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new BarszczSosnowskiego(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new Guarana(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new Lis(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new Mlecz(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new Owca(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new Trawa(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new WilczeJagody(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new Wilk(pozycje[i][0], pozycje[i++][1]));
		swiat -> DodajOrganizm(new Zolw(pozycje[i][0], pozycje[i][1]));
	}
}

int **BudulecSwiata::przygotujPozycjeStartowe(Swiat *swiat, int iloscSztuk)
{
	int **pozycje = new int *[iloscSztuk * iloscGatunkow];
	for (int i = 0; i < iloscSztuk * iloscGatunkow; i++)
		pozycje[i] = new int[2];

	for (int i = 0; i < iloscSztuk * iloscGatunkow; i++)
	{
		bool udaloSieDodac = false;
		while (!udaloSieDodac)
		{
			int x = rand() % swiat -> GetSzerokosc();
			int y = rand() % swiat -> GetWysokosc();
			if (!pozycjaZajeta(x, y, pozycje, iloscSztuk))
			{
				udaloSieDodac = true;
				pozycje[i][0] = x;
				pozycje[i][1] = y;
			}
		}
	}

	return pozycje;
}

bool BudulecSwiata::pozycjaZajeta(int x, int y, int **pozycje, int iloscSztuk)
{
	for (int i = 0; i < iloscSztuk * iloscGatunkow; i++)
		if (pozycje[i][0] == x && pozycje[i][1] == y)
			return true;

	return false;
}