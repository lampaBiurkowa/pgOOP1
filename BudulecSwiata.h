#pragma once

#include "Swiat.h"

class BudulecSwiata
{
	const int ILOSC_GATUNKOW = 10;
	const int X_INDEKS = 0, Y_INDEKS = 1;
	const int CZLOWIEK_X_INDEKS = 2, CZLOWIEK_Y_INDEKS = 3;
	const int ILOSC_ARGUMENOW_METADANYCH = CZLOWIEK_Y_INDEKS;
	const char SEPARATOR_W_PLIKU = ',';

	bool pozycjaZajeta(int x, int y, int **pozycje, int iloscSztuk);
	int **przygotujPozycjeStartowe(Swiat *swiat, int iloscSztuk);
	void sprobujZebracMetadaneZPliku(Swiat *swiat, string zrodlo, int *tabilcaDocelowa);
	void wdrozMetadane(Swiat *swiat, int *metadane);
public:
	void RozstawOrganizmyLosowo(Swiat *swiat, int iloscSztuk);
	void WczytajZPliku(Swiat *swiat, string sciezka);
};