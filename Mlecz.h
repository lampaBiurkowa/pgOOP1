#pragma once

#include "Roslina.h"

class Mlecz : public Roslina
{
	const int KROK_ROZPRZESTRZENIANIA = 1;
	const int ILOSC_PROB_ROZPRZESTRZENIENIA = 3;

	bool sprobujZasiacRosline(Swiat *swiat, int **uzyteMiejsca);
	Mlecz *zwrocInstancjeRosliny(int x, int y) override;
public:
	Mlecz(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Rysuj() override;
};
