#pragma once

#include "Swiat.h"

class BudulecSwiata
{
	int iloscSztuk;
	int iloscGatunkow;
	bool pozycjaZajeta(int x, int y, int **pozycje, int iloscSztuk);
	int **przygotujPozycjeStartowe(Swiat *swiat, int iloscSztuk);
public:
	BudulecSwiata();
	void RozstawOrganizmy(Swiat *swiat, int iloscSztuk);
};