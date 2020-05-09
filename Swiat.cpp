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

Organizm *Swiat::GetOrganizmNaPozycji(unsigned int x, unsigned int y)
{
	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetX() == x && organizmy[i] -> GetY() == y)
			return organizmy[i];

	return NULL;
}

unsigned int Swiat::GetSzerokosc()
{
	return szerokosc;
}

unsigned int Swiat::GetWysokosc()
{
	return wysokosc;
}

void Swiat::Stworz(int szerokosc, int wysokosc)
{
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
}