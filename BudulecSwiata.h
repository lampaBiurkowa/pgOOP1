#pragma once

#include "Swiat.h"

class BudulecSwiata
{
	const int ILOSC_GATUNKOW = 10;
	const int X_INDEKS = 0, Y_INDEKS = 1;
	const int ILOSC_ARGUMENOW_METADANYCH = Y_INDEKS + 1;
	const char SEPARATOR_W_PLIKU = ',', PUSTE_POLE = '-';

	bool pozycjaZajeta(int x, int y, int **pozycje, int iloscSztuk);
	int **przygotujPozycjeStartowe(Swiat *swiat, int iloscSztuk);
	void sprobujZebracMetadaneZPliku(Swiat *swiat, string zrodlo, int *tabilcaDocelowa);
	void wdrozMetadane(Swiat *swiat, int *metadane);
	void sprobujZapisacInformacjeOZwiekszeniuSily(Organizm *organizm, vector<string> *informacjeOSile);
	string sprobujZapisacInformacjeOSupermocy(Organizm *organizm);
	void wykonajZapisDanych(string sciezka, string metadane, vector<string> *linieMapy, vector<string> *informacjeOSile, string informacjeOSupermocy);
	void sprobujWdrozycInformacjeOSileZPliku(Swiat *swiat, string zrodlo);

public:
	void RozstawOrganizmyLosowo(Swiat *swiat, int iloscSztuk);
	void WczytajZPliku(Swiat *swiat, string sciezka);
	void ZapiszDoPliku(Swiat *swiat, string sciezka);
};