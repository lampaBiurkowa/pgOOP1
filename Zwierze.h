#pragma once

#include "Organizm.h"

class Zwierze : public Organizm
{
	bool handleStandardMovement();
public:
	virtual void Akcja(Swiat *swiat) override;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) override;
};