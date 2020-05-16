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
	int x;
	int y;
	char znakASCII;
public:
	Organizm(int x, int y);
	string GetNazwa();
	int GetInicjatywa();
	int GetSila();
	void SetSila(int sila);
	int GetTuryNaMapie();
	int GetX();
	int GetY();
	char GetZnakASCII();
	void Move(int x, int y);

	virtual void Akcja(Swiat *swiat) = 0;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) = 0;
	void Rysuj();
};