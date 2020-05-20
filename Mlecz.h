#pragma once

#include "Roslina.h"

class Mlecz : public Roslina
{
	static const int KROK_ROZPRZESTRZENIANIA = 1;
	static const int ILOSC_PROB_ROZPRZESTRZENIENIA = 3;

	bool sprobujZasiacRosline(Swiat *swiat, int **uzyteMiejsca);
	Mlecz *zwrocInstancjeRosliny(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'm';
	static const int DOMYSLNA_SILA = 0;

	Mlecz(int x, int y);
	void Akcja(Swiat *swiat) override;
};
