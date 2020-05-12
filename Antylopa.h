#pragma once

#include "Zwierze.h"

class Antylopa : public Zwierze
{
	const int KROK_UCIECZKI = 1;
	
	bool czyMaGdzieUciec(Swiat *swiat);
	bool sprobujUciec(Swiat *swiat);
	Antylopa *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	Antylopa(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};