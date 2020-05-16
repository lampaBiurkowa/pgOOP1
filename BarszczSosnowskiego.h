#pragma once

#include "Roslina.h"

class BarszczSosnowskiego: public Roslina
{
	BarszczSosnowskiego *zwrocInstancjeRosliny(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'b';

	BarszczSosnowskiego(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};