#pragma once

#include "Roslina.h"

class Mlecz : public Roslina
{
	Mlecz *zwrocInstancjeRosliny(int x, int y) override;
public:
	Mlecz(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Rysuj() override;
};
