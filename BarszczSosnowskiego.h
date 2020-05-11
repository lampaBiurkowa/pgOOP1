#pragma once

#include "Roslina.h"

class BarszczSosnowskiego: public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(int x, int y) override;
public:
	BarszczSosnowskiego(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};