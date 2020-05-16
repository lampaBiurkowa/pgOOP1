#pragma once

#include "Organizm.h"

class Zwierze : public Organizm
{
protected:
	int previousX;
	int previousY;

	bool czyMaGdzieUstawicPotomka(Swiat *swiat);
	bool sprubojWykonacRuch(Swiat *swiat, int step = 1);
	bool sprobujDodacPotomka(Swiat *swiat);
	virtual Zwierze *zwrocInstancjeZwierzecia(int x, int y) = 0;
public:
	Zwierze(int x, int y);
	void Cofnij();
	bool SprubojPrzesunacO(int x, int y, Swiat *swiat);
	virtual void Akcja(Swiat *swiat) override;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) override;
};