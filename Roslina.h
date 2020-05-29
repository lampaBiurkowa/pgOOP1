#pragma once

#include "Organizm.h"

class Roslina : public Organizm
{
protected:
	static const int SZANSE_NA_ROZPRZESTRZENIENIE_W_PROCENTACH = 20;
	static const int ZASIEG_USTAWIENIA_POTOMKA = 1;

	bool czyMaGdzieUstawicPotomka(Swiat *swiat);
	bool sprobujZasiacRosline(Swiat *swiat, int step = 1);
	virtual Roslina *zwrocInstancjeRosliny(int x, int y) = 0;
public:
	Roslina(int x, int y);
	void Akcja(Swiat *swiat) override;
};