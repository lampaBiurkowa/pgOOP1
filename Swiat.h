#pragma once
#include "Organizm.h"

class Swiat
{
	Organizm **organizmy;
	int iloscOrganizmow;
	unsigned int szerokosc, wysokosc;

public:
	void DodajOrganizm(Organizm *organizm);
	void UsunOrganizm(Organizm *organizm);
	void Stworz(int szerokosc, int wysokosc);
	bool CzyPoleZajete(int x, int y);
	Organizm *GetOrganizmNaPozycji(unsigned int x, unsigned int y);
	unsigned int GetSzerokosc();
	unsigned int GetWysokosc();
	void RysujSwiat();
	void WykonajTure();
};