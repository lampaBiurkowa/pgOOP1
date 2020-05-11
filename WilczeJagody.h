#pragma once

#include "Roslina.h"

class WilczeJagody : public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(int x, int y) override;
public:
	WilczeJagody(int x, int y);
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};