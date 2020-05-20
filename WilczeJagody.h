#pragma once

#include "Roslina.h"

class WilczeJagody : public Roslina
{
	WilczeJagody *zwrocInstancjeRosliny(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'w';

	WilczeJagody(int x, int y);
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};