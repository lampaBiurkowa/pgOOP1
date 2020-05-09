#pragma once

#include "Organizm.h"

class Zwierze : public Organizm
{
protected:
	bool sprubojWykonacRuch(int step = 1);
	unsigned int previousX;
	unsigned int previousY;
public:
	void Cofnij();
	bool SprubojPrzesunacO(int x, int y);
	virtual void Akcja(Swiat *swiat) override;
	virtual void Kolizja(Swiat *swiat) override;
};