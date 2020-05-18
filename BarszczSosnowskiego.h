#pragma once

#include "Roslina.h"

class BarszczSosnowskiego: public Roslina
{
	const int ZASIEG_ZNISZCZEN = 1;
	BarszczSosnowskiego *zwrocInstancjeRosliny(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'b';
	static const int DOMYSLNA_SILA = 10;

	BarszczSosnowskiego(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
};