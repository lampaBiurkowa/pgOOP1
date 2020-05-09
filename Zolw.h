#pragma once

#include "Zwierze.h"

class Zolw: public Zwierze
{
public:
	Zolw();
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat) override;
	void Rysuj() override;
};