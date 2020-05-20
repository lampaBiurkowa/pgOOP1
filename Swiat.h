#pragma once
#include "Organizm.h"
#include "Czlowiek.h"
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
	void zaktualizujTabliceOrganizmow();
	void rysujKomunikaty();
	void rysujMape();
	void szukajKolizji(int x, int y);
	bool wystepujeKolizja();
	static const int MAX_ORGANIZMOW_KOLIDUJACYCH = 2;
	int iloscKolidujacychOrganizmow;
	Organizm **kolidujaceOrganizmy;

	void inicjuj();

public:
	void DodajKomunikat(string tresc);
	void DodajOrganizm(Organizm *organizm);
	void UsunOrganizm(Organizm *organizm);
	void Stworz(int szerokosc, int wysokosc);
	bool CzyPoleZajete(int x, int y);
	bool CzyPunktMiesciSieNaMapie(int x, int y);
	bool CzyOrganizmJestNaPolu(int x, int y, string nazwa);
	Organizm *GetOrganizmNaPozycji(int x, int y);
	Organizm **GetOrganizmy();
	int GetIloscOrganizmow();
	int GetSzerokosc();
	int GetWysokosc();
	void RysujSwiat();
	void WykonajTure();
	void WypelnijSasiadujacePola(int **tablicaDocelowa, int zasieg, int x, int y);
	Czlowiek *SprobujZnalezcCzlowieka();
};