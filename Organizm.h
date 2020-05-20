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
	int x, y;
	char znakASCII;
public:
	Organizm(int x, int y);
	int GetInicjatywa() const;
	string GetNazwa() const;
	int GetSila() const;
	int GetX() const;
	int GetY() const;
	char GetZnakASCII() const;
	void SetSila(int sila);

	virtual void Akcja(Swiat *swiat) = 0;
	virtual void Kolizja(Swiat *swiat, Organizm *organizm) = 0;
	void Rysuj();
};