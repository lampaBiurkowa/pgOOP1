#pragma once

#include "Organizm.h"

class Zwierze : public Organizm
{
	const int ZASIEG_USTAWIENIA_POTOMKA = 1;
protected:
	int previousX;
	int previousY;
	int zwiekszenieSily;

	bool czyMaGdzieUstawicPotomka(Swiat *swiat);
	bool sprubojWykonacRuch(Swiat *swiat, int step = 1);
	bool sprobujDodacPotomka(Swiat *swiat);
	virtual Zwierze *zwrocInstancjeZwierzecia(int x, int y) = 0;
public:
	Zwierze(int x, int y);
	void Cofnij();
	int GetZwiekszenieSily();
	bool SprubojPrzesunacO(int x, int y, Swiat *swiat);
	void OznaczZwiekszenieSily(int ilosc);
	virtual void Akcja(Swiat *swiat) override;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) override;
};