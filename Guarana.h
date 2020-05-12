#pragma once

#include "Roslina.h"

class Guarana : public Roslina
{
	Guarana *zwrocInstancjeRosliny(int x, int y) override;
public:
	Guarana(int x, int y);
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};