#pragma once
#include "Organizm.h"

class Swiat
{
	bool **zajetePola;
	Organizm **organizmy;
	int iloscOrganizmow;
	unsigned int szerokosc, wysokosc;
public:
	void Stworz(int szerokosc, int wysokosc);
	bool CzyPoleZajete(int x, int y);
	Organizm *GetOrganizmNaPozycji(unsigned int x, unsigned int y);
	unsigned int GetSzerokosc();
	unsigned int GetWysokosc();
	void RysujSwiat();
	void WykonajTure();
};