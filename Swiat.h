#pragma once
#include "Organizm.h"
#include <vector>

using namespace std;

class Swiat
{
	Organizm **organizmy;
	int iloscOrganizmow;
	int licznikStarszenstwa;
	int szerokosc, wysokosc;
	int maxInicjatywa;
	vector<string> komunikaty;
	int getMaxInicjatywa(int ograniczenieGorneWlaczne);
	void ustawOrganizmyWKolejnosciRuchow(Organizm **organizmy);
	void obsluzEwentualneKolizje(Organizm *organizmZOstatniaAkcja);

public:
	void DodajKomunikat(string tresc);
	void DodajOrganizm(Organizm *organizm);
	void UsunOrganizm(Organizm *organizm);
	void Stworz(int szerokosc, int wysokosc);
	bool CzyPoleZajete(int x, int y);
	Organizm *GetOrganizmNaPozycji(int x, int y);
	Organizm **GetOrganizmy();
	int GetSzerokosc();
	int GetWysokosc();
	void RysujSwiat();
	void WykonajTure();
};