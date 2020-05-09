#pragma once

#include "Roslina.h"

class WilczeJagody : public Roslina
{
protected:
	void zasiejRosline(Swiat *swiat) override;
public:
	WilczeJagody();
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};