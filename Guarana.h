#pragma once

#include "Roslina.h"

class Guarana : public Roslina
{
	Guarana *zwrocInstancjeRosliny(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'g';

	Guarana(int x, int y);
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};