#include "Swiat.h"

bool Swiat::CzyPoleZajete(int x, int y)
{
	if (x >= szerokosc || y >= wysokosc || x < 0 || y < 0)
		return true;

	return zajetePola[y][x];
}

Organizm *Swiat::GetOrganizmNaPozycji(unsigned int x, unsigned int y)
{
	return &organizmy[y][x];
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
	zajetePola = new bool*[wysokosc];
	organizmy = new Organizm*[wysokosc];
	for (int i = 0; i < wysokosc; i++)
	{
		zajetePola[i] = new bool[szerokosc];
		organizmy[i] = new Organizm[szerokosc];
	}
	iloscOrganizmow = 0;
}