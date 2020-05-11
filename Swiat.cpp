#include "Swiat.h"
#include <iostream>

using namespace std;

void Swiat::UsunOrganizm(Organizm *organizm)
{
	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] == organizm)
		{
			organizmy[i] = NULL;
			iloscOrganizmow--;
			delete organizm;
		}
}

void Swiat::DodajKomunikat(string tresc)
{
	komunikaty.push_back(tresc);
}

void Swiat::DodajOrganizm(Organizm *organizm)
{
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
	if (x >= szerokosc || y >= wysokosc || x < 0 || y < 0)
		return true;

	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetX() == x && organizmy[i] -> GetY() == y)
			return true;

	return false;
}

Organizm *Swiat::GetOrganizmNaPozycji(int x, int y)
{
	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetX() == x && organizmy[i] -> GetY() == y)
			return organizmy[i];

	return NULL;
}

int Swiat::GetSzerokosc()
{
	return szerokosc;
}

int Swiat::GetWysokosc()
{
	return wysokosc;
}

void Swiat::Stworz(int szerokosc, int wysokosc)
{
	maxInicjatywa = 7;
	licznikStarszenstwa = 0;
	this -> szerokosc = szerokosc;
	this -> wysokosc = wysokosc;
	organizmy = new Organizm *[wysokosc * szerokosc];
	for (int i = 0; i < wysokosc * szerokosc; i++)
		organizmy[i] = NULL;
	iloscOrganizmow = 0;
}


void Swiat::RysujSwiat()
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

	cout<<"Komunikaty:"<<endl;
	for (int i = 0; i < komunikaty.size(); i++)
		cout<<komunikaty[i]<<endl;
}

void Swiat::WykonajTure()
{
	Organizm **ustawioneOrganizmy = new Organizm *[iloscOrganizmow];
	ustawOrganizmyWKolejnosciRuchow(ustawioneOrganizmy);

	for (int i = 0; i < iloscOrganizmow; i++)
		cout<<ustawioneOrganizmy[i] -> GetId()<<" "<<ustawioneOrganizmy[i] -> GetInicjatywa()<<endl;
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
		if (organizmy[i] -> GetInicjatywa() <= ograniczenieGorneWlaczne && organizmy[i] -> GetInicjatywa() > max)
			max = organizmy[i] -> GetInicjatywa();

	return max;
}