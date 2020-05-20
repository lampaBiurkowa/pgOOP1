#include <iostream>
#include "Organizm.h"

using namespace std;

Organizm::Organizm(int x, int y)
{
	this -> x = x;
	this -> y = y;
}

string Organizm::GetNazwa() const
{
	return nazwa;
}

int Organizm::GetInicjatywa() const
{
	return inicjatywa;
}

int Organizm::GetSila() const
{
	return sila;
}

void Organizm::SetSila(int force)
{
	this -> sila = force;
}

int Organizm::GetX() const
{
	return x;
}

int Organizm::GetY() const
{
	return y;
}

char Organizm::GetZnakASCII() const
{
	return znakASCII;
}

void Organizm::Rysuj()
{
	cout<<znakASCII;
}