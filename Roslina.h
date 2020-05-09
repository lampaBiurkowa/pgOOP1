#pragma once

#include "Organizm.h"

class Roslina : public Organizm
{
protected:
	virtual void zasiejRosline(Swiat *swiat) = 0;
public:
	void Akcja(Swiat *swiat) override;
};