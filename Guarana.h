#pragma once

#include "Roslina.h"

class Guarana : public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(unsigned int x, unsigned int y) override;
public:
	Guarana(unsigned int x, unsigned int y);
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};