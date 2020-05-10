#pragma once

#include "Roslina.h"

class Mlecz : public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(unsigned int x, unsigned int y) override;
public:
	Mlecz(unsigned int x, unsigned int y);
	void Akcja(Swiat *swiat) override;
	void Rysuj() override;
};
