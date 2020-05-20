#pragma once

#include <string>

using namespace std;

class Swiat;

class Organizm
{
protected:
	string nazwa;
	int inicjatywa;
	int sila;
	int turyNaMapie;
	int x, y;
	char znakASCII;
public:
	Organizm(int x, int y);
	int GetInicjatywa();
	string GetNazwa();
	int GetSila();
	int GetX();
	int GetY();
	int GetTuryNaMapie();
	char GetZnakASCII();
	void SetSila(int sila);

	virtual void Akcja(Swiat *swiat) = 0;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) = 0;
	void Rysuj();
};