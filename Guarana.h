#pragma once

#include "Roslina.h"

class Guarana : public Roslina
{
protected:
	void zasiejRosline(Swiat *swiat) override;
public:
	Guarana();
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	void Rysuj() override;
};