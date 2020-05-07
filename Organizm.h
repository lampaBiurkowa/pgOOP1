#pragma once

#include "Swiat.h"

class Organizm
{
protected:
	unsigned int sila;
	unsigned int inicjatywa;
	unsigned int x;
	unsigned int y;
	Swiat *swiat;
public:
	unsigned int GetSila();
	void SetForce(unsigned int sila);
	unsigned int GetInicjatywa();
	void SetInitiative(unsigned int inicjatywa);
	unsigned int GetX();
	void SetX(unsigned int x);
	unsigned int GetY();
	void SetY(unsigned int y);
	void Move(int x, int y);

	virtual void Akcja() = 0;
	virtual void Kolizja() = 0;
	virtual void Rysuj() = 0;
};