#pragma once

#include "Zwierze.h"

class Zolw: public Zwierze
{
	Zolw *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	Zolw(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};