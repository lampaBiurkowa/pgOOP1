#pragma once

class Organizm;

class Swiat
{
	bool **czyZajete;
	Organizm *organizmy;
	unsigned int wysokosc, szerokosc;
public:
	unsigned int GetWysokosc();
	unsigned int GetSzerokosc();
	void RysujSwiat();
	void WykonajTure();
};