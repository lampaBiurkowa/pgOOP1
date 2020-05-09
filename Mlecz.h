#pragma once

#include "Roslina.h"

class Mlecz : public Roslina
{
protected:
	void zasiejRosline(Swiat *swiat) override;
public:
	Mlecz();
	void Akcja(Swiat *swiat) override;
	void Rysuj() override;
};
