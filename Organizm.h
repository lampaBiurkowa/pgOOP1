#pragma once

#include <string>

using namespace std;

class Swiat;

class Organizm
{
protected:
	string id;
	int inicjatywa;
	int sila;
	int turyNaMapie;
	int x;
	int y;
public:
	Organizm(int x, int y);
	string GetId();
	int GetInicjatywa();
	int GetSila();
	void SetSila(int sila);
	int GetTuryNaMapie();
	int GetX();
	int GetY();
	void Move(int x, int y);

	virtual void Akcja(Swiat *swiat) = 0;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) = 0;
	virtual void Rysuj() = 0;
};