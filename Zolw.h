#pragma once

#include "Zwierze.h"

class Zolw : public Zwierze
{
	static const int MAKSYMALNA_SILA_DO_ODPARCIA = 4;
	static const int SZANSE_NA_POZOSTANIE_W_MIEJSCU_W_PROCENTACH = 75;

	Zolw *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'Z';

	Zolw(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};