#pragma once

#include "Organizm.h"

class Zwierze : public Organizm
{
	static const int ZASIEG_USTAWIENIA_POTOMKA = 1;
protected:
	int previousX, previousY;
	int zwiekszenieSily;

	bool czyMaGdzieUstawicPotomka(Swiat *swiat);
	bool sprobujDodacPotomka(Swiat *swiat);
	bool sprubojWykonacRuch(Swiat *swiat, int step = 1);
	virtual Zwierze *zwrocInstancjeZwierzecia(int x, int y) = 0;
public:
	Zwierze(int x, int y);
	void Cofnij();
	int GetZwiekszenieSily() const;
	void OznaczZwiekszenieSily(int ilosc);
	bool SprubojPrzesunacO(int x, int y, Swiat *swiat);

	virtual void Akcja(Swiat *swiat) override;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) override;
};