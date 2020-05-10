#pragma once

#include "Zwierze.h"

class Zolw: public Zwierze
{
public:
	Zolw(unsigned int x, unsigned int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};