#pragma once

#include "Swiat.h"

class BudulecSwiata
{
	int iloscSztuk;
	int iloscGatunkow;
	int **przygotujPozycjeStartowe(Swiat *swiat, int iloscSztuk);
public:
	BudulecSwiata();
	void RozstawOrganizmy(Swiat *swiat, int iloscSztuk);
};