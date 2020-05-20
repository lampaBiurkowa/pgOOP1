#include "Swiat.h"
#include "Kolizja.h"
#include <iostream>

using namespace std;

void Swiat::UsunOrganizm(Organizm *organizm)
{
	if (organizm == NULL)
		return;

	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] == organizm)
		{
			organizmy[i] = NULL;
			iloscOrganizmow--;
		}
}

void Swiat::DodajKomunikat(string tresc)
{
	komunikaty.push_back(tresc);
}

void Swiat::DodajOrganizm(Organizm *organizm)
{
	zaktualizujTabliceOrganizmow();
	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] == NULL)
		{
			organizmy[i] = organizm;
			iloscOrganizmow++;
			return;
		}
}

bool Swiat::CzyPoleZajete(int x, int y)
{
	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetX() == x && organizmy[i] -> GetY() == y)
			return true;

	return false;
}

bool Swiat::CzyPunktMiesciSieNaMapie(int x, int y)
{
	return x < szerokosc && y < wysokosc && x >= 0 && y >= 0;
}

Organizm *Swiat::GetOrganizmNaPozycji(int x, int y) const
{
	for (int i = 0; i < GetWysokosc() * GetSzerokosc(); i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetX() == x && organizmy[i] -> GetY() == y)
			return organizmy[i];

	return NULL;
}

int Swiat::GetSzerokosc() const
{
	return szerokosc;
}

int Swiat::GetWysokosc() const
{
	return wysokosc;
}

void Swiat::Stworz(int szerokosc, int wysokosc, int numerTury)
{
	iloscOrganizmow = 0;
	maxInicjatywa = 7;
	this -> numerTury = numerTury;
	this -> szerokosc = szerokosc;
	this -> wysokosc = wysokosc;
	organizmy = new Organizm *[wysokosc * szerokosc];
	for (int i = 0; i < wysokosc * szerokosc; i++)
		organizmy[i] = NULL;
}


void Swiat::RysujSwiat()
{
	rysujKomunikaty();
	rysujMape();
}

void Swiat::rysujMape()
{
	for (int i = 0; i < wysokosc * szerokosc; i++)
	{
		Organizm *organizm = GetOrganizmNaPozycji(i % szerokosc, i / wysokosc);
		cout<<"|";
		if (organizm == NULL)
			cout<<" ";
		else
			organizm -> Rysuj();
		if (i % szerokosc == szerokosc - 1)
			cout<<"|"<<endl;
	}
}

void Swiat::rysujKomunikaty()
{
	cout<<"Komunikaty:"<<endl;
	if (komunikaty.size() == 0)
	{
		cout<<"Brak"<<endl;
		return;
	}

	for (int i = 0; i < komunikaty.size(); i++)
		cout<<komunikaty[i]<<endl;

	komunikaty.clear();
}

void Swiat::WykonajTure()
{
	Organizm **ustawioneOrganizmy = new Organizm *[iloscOrganizmow];
	ustawOrganizmyWKolejnosciRuchow(ustawioneOrganizmy);

	int iloscUstawionychOrganizmow = iloscOrganizmow;
	for (int i = 0; i < iloscUstawionychOrganizmow; i++)
	{
		if ((ustawioneOrganizmy)[i] == NULL)
			continue;

		(ustawioneOrganizmy)[i] -> Akcja(this);
		obsluzEwentualneKolizje((ustawioneOrganizmy)[i]);
	}

	delete[] ustawioneOrganizmy;
	zaktualizujTabliceOrganizmow();
	numerTury++;
}

void Swiat::ustawOrganizmyWKolejnosciRuchow(Organizm **ustawioneOrganizmy)
{
	int ograniczenieGorneWlaczne = maxInicjatywa;
	int iloscUstawionychOrganizmow = 0;
	while (iloscUstawionychOrganizmow < iloscOrganizmow)
	{
		int szukanaInicjatywa = getMaxInicjatywa(ograniczenieGorneWlaczne);
		ograniczenieGorneWlaczne = szukanaInicjatywa - 1;
		for (int i = 0; i < iloscOrganizmow; i++)
			if (organizmy[i] -> GetInicjatywa() == szukanaInicjatywa)
			{
				ustawioneOrganizmy[iloscUstawionychOrganizmow] = organizmy[i];
				iloscUstawionychOrganizmow++;
			}
	}
}

int Swiat::getMaxInicjatywa(int ograniczenieGorneWlaczne)
{
	int max = -1;
	for (int i = 0; i < iloscOrganizmow; i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetInicjatywa() <= ograniczenieGorneWlaczne && organizmy[i] -> GetInicjatywa() > max)
			max = organizmy[i] -> GetInicjatywa();

	return max;
}

void Swiat::obsluzEwentualneKolizje(Organizm *organizmZOstatniaAkcja)
{
	Kolizja kolizja;
	Organizm *organizmZPierwszenstwem, *organizmBezPierwszenstwa;
	for (int i = 0; i < GetWysokosc(); i++)
		for (int j = 0; j < GetSzerokosc(); j++)
		{
			if (!CzyPoleZajete(j, i))
				continue;

			kolizja.SzukajKolizji(this, j, i);
			if (!kolizja.WystepujeKolizja())
				continue;

			if (kolizja.GetKolidujaceOrganizmy()[0] == organizmZOstatniaAkcja)
			{
				organizmZPierwszenstwem = kolizja.GetKolidujaceOrganizmy()[1];
				organizmBezPierwszenstwa = kolizja.GetKolidujaceOrganizmy()[0];
			}
			else
			{
				organizmZPierwszenstwem = kolizja.GetKolidujaceOrganizmy()[0];
				organizmBezPierwszenstwa = kolizja.GetKolidujaceOrganizmy()[1];
			}

			DodajKomunikat("Kolizja " + organizmZPierwszenstwem -> GetNazwa() + " z " + organizmBezPierwszenstwa -> GetNazwa());
			organizmZPierwszenstwem -> Kolizja(this, organizmBezPierwszenstwa);
			kolizja.SzukajKolizji(this, j, i);
			if (!kolizja.WystepujeKolizja())
				continue;
			
			if (organizmZPierwszenstwem -> GetSila() >= organizmBezPierwszenstwa -> GetSila())
			{
				DodajKomunikat(organizmZPierwszenstwem -> GetNazwa() + " zabija " + organizmBezPierwszenstwa -> GetNazwa());
				UsunOrganizm(organizmBezPierwszenstwa);
			}
			else
			{
				DodajKomunikat(organizmBezPierwszenstwa -> GetNazwa() + " zabija " + organizmZPierwszenstwem -> GetNazwa());
				UsunOrganizm(organizmZPierwszenstwem);
			}
		}
}

Organizm **Swiat::GetOrganizmy() const
{
	return organizmy;
}

void Swiat::zaktualizujTabliceOrganizmow()
{
	int wolnyIndeks = GetSzerokosc() * GetWysokosc();
	bool czySzukacWolnegoIndeksu = true;
	for (int i = 0; i < GetSzerokosc() * GetWysokosc(); i++)
	{
		if (czySzukacWolnegoIndeksu && organizmy[i] == NULL)
		{
			wolnyIndeks = i;
			czySzukacWolnegoIndeksu = false;
		}
		else if (organizmy[i] != NULL && i > wolnyIndeks)
		{
			int roznica = i - wolnyIndeks;
			for (int j = wolnyIndeks; j < GetSzerokosc() * GetWysokosc() - roznica; j++)
				organizmy[j] = organizmy[j + roznica];

			i = wolnyIndeks + roznica - 1;
			wolnyIndeks = GetSzerokosc() * GetWysokosc();
			czySzukacWolnegoIndeksu = true;
		}
	}

	for (int i = iloscOrganizmow; i < GetSzerokosc() * GetWysokosc(); i++)
		organizmy[i] = NULL;
}

int Swiat::GetIloscOrganizmow() const
{
	return iloscOrganizmow;
}

void Swiat::WypelnijSasiadujacePola(int **tablicaDocelowa, int zasieg, int x, int y)
{
	int iterator = 0;
	for (int i = -zasieg; i <= zasieg; i++)
		for (int j = -zasieg; j <= zasieg; j++)
		{
			if ((i == 0 && j == 0) || (i != 0 && j != 0))
				continue;

			tablicaDocelowa[iterator][0] = x + j;
			tablicaDocelowa[iterator][1] = y + i;
		}
}

Czlowiek *Swiat::SprobujZnalezcCzlowieka()
{
	for (int i = 0; i < GetWysokosc(); i++)
		for (int j = 0; j < GetSzerokosc(); j++)
			if (CzyPoleZajete(j, i) && dynamic_cast<Czlowiek *>(GetOrganizmNaPozycji(j, i)) != nullptr)
				return (Czlowiek *)GetOrganizmNaPozycji(j, i);

	return NULL;
}

bool Swiat::CzyOrganizmJestNaPolu(int x, int y, string nazwa)
{
	for (int i = 0; i < GetWysokosc() * GetSzerokosc(); i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetX() == x && organizmy[i] -> GetY() == y && organizmy[i] -> GetNazwa() == nazwa)
			return true;

	return false;
}

int Swiat::GetNumerTury() const
{
	return numerTury;
}