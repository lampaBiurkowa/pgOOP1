#pragma once

#include "Roslina.h"

class BarszczSosnowskiego: public Roslina
{
protected:
	void zasiejRosline(Swiat *swiat) override;
public:
	BarszczSosnowskiego();
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};