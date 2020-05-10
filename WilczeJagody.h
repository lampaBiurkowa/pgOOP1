#pragma once

#include "Roslina.h"

class WilczeJagody : public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(unsigned int x, unsigned int y) override;
public:
	WilczeJagody(unsigned int x, unsigned int y);
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};