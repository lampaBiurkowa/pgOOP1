#pragma once

#include "Zwierze.h"

class Zolw : public Zwierze
{
	const int SZANSE_NA_POZOSTANIE_W_MIEJSCU_W_PROCENTACH = 75;
	const int MAKSYMALNA_SILA_DO_ODPARCIA = 4;
	Zolw *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'Z';
	static const int DOMYSLNA_SILA = 2;

	Zolw(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};