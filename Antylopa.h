#pragma once

#include "Zwierze.h"

class Antylopa : public Zwierze
{
	static const int KROK_UCIECZKI = 1;
	static const int SZANSA_NA_UCIECZKE_W_PROCENTACH = 50;
	
	bool czyMaGdzieUciec(Swiat *swiat);
	bool sprobujUciec(Swiat *swiat);
	Antylopa *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'A';
	static const int DOMYSLNA_SILA = 4;

	Antylopa(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};