#pragma once

#include "Zwierze.h"

class Lis: public Zwierze
{
	bool czyMozeSieRuszyc(Swiat *swiat);
public:
	Lis();
	void Akcja(Swiat *swiat) override;
	void Rysuj() override;
};