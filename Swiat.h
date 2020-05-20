#pragma once
#include "Organizm.h"
#include "Czlowiek.h"
#include <vector>

using namespace std;

class Swiat
{
	Organizm **organizmy;
	int iloscOrganizmow;
	vector<string> komunikaty;
	int maxInicjatywa;
	int numerTury;
	int szerokosc, wysokosc;

	int getMaxInicjatywa(int ograniczenieGorneWlaczne);
	void rysujKomunikaty();
	void rysujMape();
	void obsluzEwentualneKolizje(Organizm *organizmZOstatniaAkcja);
	void ustawOrganizmyWKolejnosciRuchow(Organizm **organizmy);
	void zaktualizujTabliceOrganizmow();

public:
	bool CzyPoleZajete(int x, int y);
	bool CzyPunktMiesciSieNaMapie(int x, int y);
	bool CzyOrganizmJestNaPolu(int x, int y, string nazwa);
	void DodajKomunikat(string tresc);
	void DodajOrganizm(Organizm *organizm);
	int GetIloscOrganizmow();
	Organizm *GetOrganizmNaPozycji(int x, int y);
	Organizm **GetOrganizmy();
	int GetNumerTury();
	int GetSzerokosc();
	int GetWysokosc();
	void RysujSwiat();
	Czlowiek *SprobujZnalezcCzlowieka();
	void Stworz(int szerokosc, int wysokosc, int numerTury = 0);
	void UsunOrganizm(Organizm *organizm);
	void WykonajTure();
	void WypelnijSasiadujacePola(int **tablicaDocelowa, int zasieg, int x, int y);
};