#pragma once

#include "Roslina.h"

class Guarana : public Roslina
{
	static const int ZWIEKSZENIE_SILY = 3;

	Guarana *zwrocInstancjeRosliny(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'g';

	Guarana(int x, int y);
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};