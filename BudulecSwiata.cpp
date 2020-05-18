#include <fstream>
#include <iostream>
#include "Antylopa.h"
#include "BarszczSosnowskiego.h"
#include "BudulecSwiata.h"
#include "Czlowiek.h"
#include "Guarana.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Wilk.h"
#include "Zolw.h"

using namespace std;

void BudulecSwiata::RozstawOrganizmyLosowo(Swiat *swiat, int iloscSztuk)
{
	int **pozycje = przygotujPozycjeStartowe(swiat, iloscSztuk);
	for (int i = 0; i < iloscSztuk * ILOSC_GATUNKOW; i++)
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
	int **pozycje = new int *[iloscSztuk * ILOSC_GATUNKOW];
	for (int i = 0; i < iloscSztuk * ILOSC_GATUNKOW; i++)
		pozycje[i] = new int[2];

	for (int i = 0; i < iloscSztuk * ILOSC_GATUNKOW; i++)
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
	for (int i = 0; i < iloscSztuk * ILOSC_GATUNKOW; i++)
		if (pozycje[i][0] == x && pozycje[i][1] == y)
			return true;

	return false;
}

void BudulecSwiata::WczytajZPliku(Swiat *swiat, string sciezka)
{
	string metadaneZrodlo;
	fstream dane(sciezka.c_str(), ios::in);
	dane>>metadaneZrodlo;
	int *metadanePrzekonwertowane = new int[ILOSC_ARGUMENOW_METADANYCH];
	sprobujZebracMetadaneZPliku(swiat, metadaneZrodlo, metadanePrzekonwertowane);
	wdrozMetadane(swiat, metadanePrzekonwertowane);
	for (int i = 0; i < swiat -> GetWysokosc(); i++)
	{
		string rzad;
		dane>>rzad;
		for (int j = 0; j < rzad.length(); j += 2)
		{
			if (rzad[j] == Antylopa::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Antylopa(i, j / 2));
			else if (rzad[j] == BarszczSosnowskiego::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new BarszczSosnowskiego(i, j / 2));
			if (rzad[j] == Czlowiek::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Czlowiek(i, j / 2));
			else if (rzad[j] == Guarana::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Guarana(i, j / 2));
			else if (rzad[j] == Lis::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Lis(i, j / 2));
			else if (rzad[j] == Mlecz::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Mlecz(i, j / 2));
			else if (rzad[j] == Owca::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Owca(i, j / 2));
			else if (rzad[j] == Trawa::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Trawa(i, j / 2));
			else if (rzad[j] == WilczeJagody::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new WilczeJagody(i, j / 2));
			else if (rzad[j] == Wilk::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Wilk(i, j / 2));
			else if (rzad[j] == Zolw::IDENTYFIKATOR_PLIKU)
				swiat -> DodajOrganizm(new Zolw(i, j / 2));
		}
	}

	string linia;
	while (!dane.eof())
	{
		dane>>linia;
		sprobujWdrozycInformacjeOSileZPliku(swiat, linia);
	}
	dane.close();
}

void BudulecSwiata::sprobujZebracMetadaneZPliku(Swiat *swiat, string zrodlo, int *tabilcaDocelowa)
{
	string numer = "";
	int iterator = 0;
	for (int i = 0; i < zrodlo.length(); i++)
	{
		if (zrodlo[i] != SEPARATOR_W_PLIKU)
			numer += zrodlo[i];
		if (i == zrodlo.length() - 1 || zrodlo[i] == SEPARATOR_W_PLIKU)
		{
			tabilcaDocelowa[iterator] = atoi(numer.c_str());
			iterator++;
			numer = "";
		}
	}

	if (iterator != ILOSC_ARGUMENOW_METADANYCH)
	{
		cout<<"Blad! Ilosc argumentow w metadnych: "<<iterator<<", oczekiwano: "<<ILOSC_ARGUMENOW_METADANYCH<<endl;
		exit(-1);
	}
}

void BudulecSwiata::sprobujWdrozycInformacjeOSileZPliku(Swiat *swiat, string zrodlo)
{
	int *dane = new int[3];
	string numer = "";
	int iterator = 0;
	for (int i = 0; i < zrodlo.length(); i++)
	{
		if (zrodlo[i] != SEPARATOR_W_PLIKU)
			numer += zrodlo[i];
		if (i == zrodlo.length() - 1 || zrodlo[i] == SEPARATOR_W_PLIKU)
		{
			dane[iterator] = atoi(numer.c_str());
			iterator++;
			numer = "";
		}
	}

	int x = dane[0];
	int y = dane[1];
	int zwiekszenieSily = dane[2];
	if (!swiat -> CzyPoleZajete(x, y) || dynamic_cast<Zwierze *>(swiat -> GetOrganizmNaPozycji(x, y)) == nullptr)
		return;

	Zwierze *zwierze = ((Zwierze *)swiat -> GetOrganizmNaPozycji(x, y));
	zwierze -> OznaczZwiekszenieSily(zwiekszenieSily);
	zwierze -> SetSila(zwierze -> GetSila() + zwiekszenieSily);
}

void BudulecSwiata::wdrozMetadane(Swiat *swiat, int *metadane)
{
	swiat -> Stworz(metadane[X_INDEKS], metadane[Y_INDEKS]);
}

void BudulecSwiata::ZapiszDoPliku(Swiat *swiat, string sciezka)
{
	string metadane = to_string(swiat -> GetSzerokosc()) + SEPARATOR_W_PLIKU + to_string(swiat -> GetWysokosc());
	vector<string> linieMapy, informacjOSile;
	string informacjeOSupermocy;
	for (int i = 0; i < swiat -> GetWysokosc(); i++)
	{
		string linia = "";
		for (int j = 0; j < swiat -> GetSzerokosc(); j++)
		{
			if (!swiat -> CzyPoleZajete(i, j))
				linia += PUSTE_POLE;
			else
			{
				Organizm *organizm = swiat -> GetOrganizmNaPozycji(i, j);
				linia += organizm -> GetZnakASCII();
				sprobujZapisacInformacjeOZwiekszeniuSily(organizm, &informacjOSile);
				informacjeOSupermocy = sprobujZapisacInformacjeOSupermocy(organizm);
			}

			if (j != swiat -> GetSzerokosc() - 1)
				linia += SEPARATOR_W_PLIKU;
		}
		linieMapy.push_back(linia);
	}
	wykonajZapisDanych(sciezka, metadane, &linieMapy, &informacjOSile, informacjeOSupermocy);
}

void BudulecSwiata::wykonajZapisDanych(string sciezka, string metadane, vector<string> *linieMapy, vector<string> *informacjeOSile, string informacjeOSupermocy)
{
	fstream zapis(sciezka, ios::out);
	zapis<<metadane<<endl;
	for (int i = 0; i < linieMapy -> size(); i++)
		zapis<<(*linieMapy)[i]<<endl;
	for (int i = 0; i < informacjeOSile -> size(); i++)
		zapis<<(*informacjeOSile)[i]<<endl;
	zapis<<informacjeOSupermocy<<endl;
	zapis.close();
}

string BudulecSwiata::sprobujZapisacInformacjeOSupermocy(Organizm *organizm)
{
	string informacjeOSupermocy;
	if (dynamic_cast<Czlowiek *>(organizm) != nullptr)
	{
		int pozostalaIloscTurZSupemoca = ((Czlowiek *)(organizm)) -> GetPozostalaIloscTurZSupermoca();
		int iloscTurDoUzyciaSupermocy = ((Czlowiek *)(organizm)) -> GetIloscTurDoUzyciaSupermocy();
		informacjeOSupermocy = to_string(pozostalaIloscTurZSupemoca) + SEPARATOR_W_PLIKU + to_string(iloscTurDoUzyciaSupermocy);
	}

	return informacjeOSupermocy;
}

void BudulecSwiata::sprobujZapisacInformacjeOZwiekszeniuSily(Organizm *organizm, vector<string> *informacjeOSile)
{
	if (dynamic_cast<Zwierze *>(organizm) != nullptr)
	{
		int zwiekszenieSily = ((Zwierze *)(organizm)) -> GetZwiekszenieSily();
		if (((Zwierze *)(organizm)) -> GetZwiekszenieSily() != 0)
			informacjeOSile -> push_back(to_string(organizm -> GetX()) + SEPARATOR_W_PLIKU + to_string(organizm -> GetY()) + SEPARATOR_W_PLIKU + to_string(zwiekszenieSily));
	}
}