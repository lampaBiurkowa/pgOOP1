#pragma once

#include <string>

using namespace std;

class Swiat;

class Organizm
{
protected:
	unsigned int inicjatywa;
	unsigned int sila;
	unsigned int turyNaMapie;
	unsigned int x;
	unsigned int y;
	string id;
public:
	Organizm();
	string GetId();
	unsigned int GetInicjatywa();
	void SetInitiative(unsigned int inicjatywa);
	unsigned int GetSila();
	void SetSila(unsigned int sila);
	unsigned int GetTuryNaMapie();
	void AktualizujLicznikTur();
	unsigned int GetX();
	void SetX(unsigned int x);
	unsigned int GetY();
	void SetY(unsigned int y);
	void Move(int x, int y);

	virtual void Akcja(Swiat *swiat) = 0;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) = 0;
	virtual void Rysuj() = 0;
};