#pragma once

#include "Zwierze.h"

class Antylopa: public Zwierze
{
	bool czyMaGdzieUciec(Swiat *swiat);
	bool sprubojUciec(Swiat *swiat);
public:
	Antylopa(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};