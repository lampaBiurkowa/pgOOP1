#pragma once

#include "Swiat.h"

class BudulecSwiata
{
	static const int ILOSC_GATUNKOW_DO_LOSOWANIA = 10;
	static const int X_INDEKS = 0, Y_INDEKS = 1;
	static const int POZOSTALE_TURY_Z_SUPERMOCA_INDEKS = 0, ILOSC_TUR_DO_AKTYWACJI_SUPERMOCY_INDEKS = 1;
	static const int ZWIEKSZENIE_SILY_INDEKS = 2;
	static const int ILOSC_ARGUMENOW_METADANYCH = 2, ILOSC_ARGUMENOW_SUPERMOCY = 2, ILOSC_ARGUMENOW_SILY = 3;
	static const char SEPARATOR_W_PLIKU = ',', PUSTE_POLE = '-', OZNACZENIE_SUPERMOCY = 'S';

	bool pozycjaZajeta(int x, int y, int **pozycje, int iloscSztuk);
	int **przygotujPozycjeStartowe(Swiat *swiat, int iloscSztuk);
	void wdrozMetadane(Swiat *swiat, string zrodlo);
	void sprobujZapisacInformacjeOZwiekszeniuSily(Organizm *organizm, vector<string> *informacjeOSile);
	string sprobujZapisacInformacjeOSupermocy(Organizm *organizm);
	void wykonajZapisDanych(string sciezka, string metadane, vector<string> *linieMapy, vector<string> *informacjeOSile, string informacjeOSupermocy);
	void sprobujWdrozycInformacjeOSileZPliku(Swiat *swiat, string zrodlo);
	void sprobujWdrozycInformacjeOSupermocyZPliku(Swiat *swiat, string zrodlo);
	void wdrozPozostaleInformacjeZPliku(Swiat *swiat, string zrodlo);
	void wdrozMapeOrganizmow(Swiat *swiat);
	void dodajOdpowiedniTypOrganizmu(Swiat *swiat, char znak, int x, int y);
	void obsluzPotencjalnyBladWczytywania(int oczekiwanaIloscArg, int aktualnaIloscArg);
	int wypelnijLiczbowaTabliceZPlikuIZwrocIlosc(string zrodlo, int *tablicaDocelowa, int startIteracji = 0);

public:
	void RozstawOrganizmyLosowo(Swiat *swiat, int iloscSztuk);
	void WczytajZPliku(Swiat *swiat, string sciezka);
	void ZapiszDoPliku(Swiat *swiat, string sciezka);
};