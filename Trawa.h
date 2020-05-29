#pragma once

#include "Roslina.h"

class Trawa : public Roslina
{
	Trawa *zwrocInstancjeRosliny(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 't';

	Trawa(int x, int y);
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};