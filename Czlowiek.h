#pragma once

#include "Zwierze.h"

class Czlowiek : public Zwierze
{
	const int STRZALKA_GORA_KOD = 72;
	const int STRZALKA_DOL_KOD = 80;
	const int STRZALKA_LEWO_KOD = 77;
	const int STRZALKA_PRAWO_KOD = 75;
	const int STRZALKA_KOD_KONTROLNY = 0;

	Czlowiek *zwrocInstancjeZwierzecia(int x, int y);
public:
	static const char IDENTYFIKATOR_PLIKU = 'C';

	Czlowiek(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};