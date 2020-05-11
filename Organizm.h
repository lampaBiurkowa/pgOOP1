#pragma once

#include <string>

using namespace std;

class Swiat;

class Organizm
{
protected:
	int inicjatywa;
	int sila;
	int starszenstwo;
	int turyNaMapie;
	int x;
	int y;
	string id;
public:
	Organizm(int x, int y);
	string GetId();
	int GetInicjatywa();
	void SetInitiative(int inicjatywa);
	int GetSila();
	void SetSila(int sila);
	int GetTuryNaMapie();
	int GetX();
	void SetX(int x);
	int GetY();
	void SetY(int y);
	void Move(int x, int y);

	virtual void Akcja(Swiat *swiat) = 0;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) = 0;
	virtual void Rysuj() = 0;
};