#pragma once

#include "Zwierze.h"

class Lis : public Zwierze
{
	bool czyMozeSieRuszyc(Swiat *swiat);
	Lis *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'L';

	Lis(int x, int y);
	void Akcja(Swiat *swiat) override;
};