#pragma once

#include "Organizm.h"

class Zwierze : public Organizm
{
protected:
	bool sprubojWykonacRuch(Swiat *swiat, int step = 1);
	int previousX;
	int previousY;
public:
	Zwierze(int x, int y);
	void Cofnij();
	bool SprubojPrzesunacO(int x, int y, Swiat *swiat);
	virtual void Akcja(Swiat *swiat) override;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) override;
};