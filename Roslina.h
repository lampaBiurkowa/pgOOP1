#pragma once

#include "Organizm.h"

class Roslina : public Organizm
{
protected:
	const int SZANSE_NA_ROZPRZESTRZENIENIE_W_PROCENTACH = 50;
	bool sprobujZasiacRosline(Swiat *swiat, int step = 1);
	virtual Roslina *zwrocInstancjeRosliny(int x, int y) = 0;
public:
	Roslina(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;  
};