#pragma once

#include "Roslina.h"

class BarszczSosnowskiego: public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(unsigned int x, unsigned int y) override;
public:
	BarszczSosnowskiego(unsigned int x, unsigned int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};