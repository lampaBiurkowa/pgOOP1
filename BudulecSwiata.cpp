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
	if (iloscSztuk * ILOSC_GATUNKOW_DO_LOSOWANIA + 1 > swiat -> GetSzerokosc() * swiat -> GetWysokosc())
	{
		cout<<"Zbyt maly rozmiar swiat do zmieszczeia wszystkich gatunkow";
		return;
	}

	int **pozycje = przygotujPozycjeStartowe(swiat, iloscSztuk);
	for (int i = 0; i < iloscSztuk * ILOSC_GATUNKOW_DO_LOSOWANIA; i++)
	{
		swiat -> DodajOrganizm(new Antylopa(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new BarszczSosnowskiego(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new Guarana(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new Lis(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new Mlecz(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new Owca(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new Trawa(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new WilczeJagody(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new Wilk(pozycje[i][0], pozycje[i][1])), i++;
		swiat -> DodajOrganizm(new Zolw(pozycje[i][0], pozycje[i][1]));
	}
	swiat -> DodajOrganizm(new Czlowiek(pozycje[iloscSztuk * ILOSC_GATUNKOW_DO_LOSOWANIA][0], pozycje[iloscSztuk * ILOSC_GATUNKOW_DO_LOSOWANIA][1]));
}

int **BudulecSwiata::przygotujPozycjeStartowe(Swiat *swiat, int iloscSztuk)
{
	int **pozycje = new int *[iloscSztuk * ILOSC_GATUNKOW_DO_LOSOWANIA + 1];
	for (int i = 0; i < iloscSztuk * ILOSC_GATUNKOW_DO_LOSOWANIA + 1; i++)
		pozycje[i] = new int[2];

	for (int i = 0; i < iloscSztuk * ILOSC_GATUNKOW_DO_LOSOWANIA + 1; i++)
	{
		bool udaloSieDodac = false;
		while (!udaloSieDodac)
		{
			int x = rand() % swiat -> GetSzerokosc();
			int y = rand() % swiat -> GetWysokosc();
			if (!pozycjaZajeta(x, y, pozycje, iloscSztuk))
			{
				udaloSieDodac = true;
				pozycje[i][0] = x, pozycje[i][1] = y;
			}
		}
	}

	return pozycje;
}

bool BudulecSwiata::pozycjaZajeta(int x, int y, int **pozycje, int iloscSztuk)
{
	for (int i = 0; i < iloscSztuk * ILOSC_GATUNKOW_DO_LOSOWANIA + 1; i++)
		if (pozycje[i][0] == x && pozycje[i][1] == y)
			return true;

	return false;
}

void BudulecSwiata::WczytajZPliku(Swiat *swiat, string sciezka)
{
	string linia;
	fstream dane(sciezka.c_str(), ios::in);
	dane>>linia;
	wdrozMetadane(swiat, linia);
	for (int i = 0; i < swiat -> GetWysokosc(); i++)
	{
		dane>>linia;
		for (int j = 0; j < linia.length(); j += 2)
			dodajOdpowiedniTypOrganizmu(swiat, linia[j], j / 2, i);
	}

	while (!dane.eof())
	{
		dane>>linia;
		wdrozPozostaleInformacjeZPliku(swiat, linia);
	}
	dane.close();
}

void BudulecSwiata::dodajOdpowiedniTypOrganizmu(Swiat *swiat, char znak, int x, int y)
{
	if (znak == Antylopa::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Antylopa(x, y));
	else if (znak == BarszczSosnowskiego::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new BarszczSosnowskiego(x, y));
	else if (znak == Czlowiek::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Czlowiek(x, y));
	else if (znak == Guarana::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Guarana(x, y));
	else if (znak == Lis::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Lis(x, y));
	else if (znak == Mlecz::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Mlecz(x, y));
	else if (znak == Owca::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Owca(x, y));
	else if (znak == Trawa::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Trawa(x, y));
	else if (znak == WilczeJagody::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new WilczeJagody(x, y));
	else if (znak == Wilk::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Wilk(x, y));
	else if (znak == Zolw::IDENTYFIKATOR_PLIKU)
		swiat -> DodajOrganizm(new Zolw(x, y));
}

void BudulecSwiata::wdrozMetadane(Swiat *swiat, string zrodlo)
{
	int *dane = new int[ILOSC_ARGUMENOW_METADANYCH];
	int iloscParametrow = wypelnijLiczbowaTabliceZPlikuIZwrocIlosc(zrodlo, dane, 0);
	obsluzPotencjalnyBladWczytywania(ILOSC_ARGUMENOW_METADANYCH, iloscParametrow);
	swiat -> Stworz(dane[X_INDEKS], dane[Y_INDEKS], dane[NUMER_TURY_INDEKS]);
}

void BudulecSwiata::obsluzPotencjalnyBladWczytywania(int oczekiwanaIloscArg, int aktualnaIloscArg)
{
	if (aktualnaIloscArg != oczekiwanaIloscArg)
	{
		cout<<"Blad! Ilosc argumentow w metadnych: "<<aktualnaIloscArg<<", oczekiwano: "<<oczekiwanaIloscArg<<endl;
		exit(-1);
	}
}

void BudulecSwiata::wdrozPozostaleInformacjeZPliku(Swiat *swiat, string zrodlo)
{
	if (zrodlo[0] == OZNACZENIE_SUPERMOCY)
		sprobujWdrozycInformacjeOSupermocyZPliku(swiat, zrodlo);
	else
		sprobujWdrozycInformacjeOSileZPliku(swiat, zrodlo);
}

void BudulecSwiata::sprobujWdrozycInformacjeOSupermocyZPliku(Swiat *swiat, string zrodlo)
{
	Czlowiek *czlowiek = swiat -> SprobujZnalezcCzlowieka();
	if (czlowiek == NULL)
		return;

	int *dane = new int[ILOSC_ARGUMENOW_SUPERMOCY];
	int iloscParametrow = wypelnijLiczbowaTabliceZPlikuIZwrocIlosc(zrodlo, dane, 1);
	obsluzPotencjalnyBladWczytywania(ILOSC_ARGUMENOW_SUPERMOCY, iloscParametrow);

	czlowiek -> SetPozostalaIloscTurZSupermoca(dane[POZOSTALE_TURY_Z_SUPERMOCA_INDEKS]);
	czlowiek -> SetIloscTurDoUzyciaSupermocy(dane[ILOSC_TUR_DO_AKTYWACJI_SUPERMOCY_INDEKS]);
}

void BudulecSwiata::sprobujWdrozycInformacjeOSileZPliku(Swiat *swiat, string zrodlo)
{
	int *dane = new int[ILOSC_ARGUMENOW_SILY];
	int iloscParametrow = wypelnijLiczbowaTabliceZPlikuIZwrocIlosc(zrodlo, dane);
	obsluzPotencjalnyBladWczytywania(ILOSC_ARGUMENOW_SILY, iloscParametrow);

	int x = dane[X_INDEKS], y = dane[Y_INDEKS];
	int zwiekszenieSily = dane[ZWIEKSZENIE_SILY_INDEKS];
	Organizm *organizm = swiat -> GetOrganizmNaPozycji(x, y);
	if (swiat -> CzyPoleZajete(x, y) && dynamic_cast<Zwierze *>(organizm) != nullptr)
	{
		((Zwierze *)organizm) -> OznaczZwiekszenieSily(zwiekszenieSily);
		organizm -> SetSila(organizm -> GetSila() + zwiekszenieSily);
	}
}

int BudulecSwiata::wypelnijLiczbowaTabliceZPlikuIZwrocIlosc(string zrodlo, int *tablicaDocelowa, int startIteracji)
{
	string numer = "";
	int iterator = 0;
	for (int i = startIteracji; i < zrodlo.length(); i++)
	{
		if (zrodlo[i] != SEPARATOR_W_PLIKU)
			numer += zrodlo[i];
		if (zrodlo[i] == SEPARATOR_W_PLIKU || i == zrodlo.length() - 1)
		{
			tablicaDocelowa[iterator++] = atoi(numer.c_str());
			numer = "";
		}
	}

	return iterator;
}

string BudulecSwiata::przygotujMetadaneDoZapisu(Swiat *swiat)
{
	string metadane = to_string(swiat -> GetSzerokosc()) + SEPARATOR_W_PLIKU;
	metadane += to_string(swiat -> GetWysokosc()) + SEPARATOR_W_PLIKU;
	metadane += to_string(swiat -> GetNumerTury());

	return metadane;
}

void BudulecSwiata::ZapiszDoPliku(Swiat *swiat, string sciezka)
{
	vector<string> linieMapy, informacjOSile;
	string informacjeOSupermocy;
	for (int i = 0; i < swiat -> GetWysokosc(); i++)
	{
		string linia = "";
		for (int j = 0; j < swiat -> GetSzerokosc(); j++)
		{
			if (!swiat -> CzyPoleZajete(j, i))
				linia += PUSTE_POLE;
			else
			{
				Organizm *organizm = swiat -> GetOrganizmNaPozycji(j, i);
				linia += organizm -> GetZnakASCII();
				sprobujZapisacInformacjeOZwiekszeniuSily(organizm, &informacjOSile);
				string wynikProby = sprobujZapisacInformacjeOSupermocy(organizm);
				if (wynikProby.length() > 0)
					informacjeOSupermocy = wynikProby;
			}

			if (j != swiat -> GetSzerokosc() - 1)
				linia += SEPARATOR_W_PLIKU;
		}
		linieMapy.push_back(linia);
	}
	wykonajZapisDanych(sciezka, przygotujMetadaneDoZapisu(swiat), &linieMapy, &informacjOSile, informacjeOSupermocy);
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
		informacjeOSupermocy = OZNACZENIE_SUPERMOCY + to_string(pozostalaIloscTurZSupemoca) + SEPARATOR_W_PLIKU + to_string(iloscTurDoUzyciaSupermocy);
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