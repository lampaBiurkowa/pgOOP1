#pragma once

#include "Roslina.h"

class Mlecz : public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(int x, int y) override;
public:
	Mlecz(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Rysuj() override;
};
