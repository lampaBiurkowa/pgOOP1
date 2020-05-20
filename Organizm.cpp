#include <iostream>
#include "Organizm.h"

using namespace std;

Organizm::Organizm(int x, int y)
{
	this -> x = x;
	this -> y = y;
}

string Organizm::GetNazwa()
{
	return nazwa;
}

int Organizm::GetInicjatywa()
{
	return inicjatywa;
}

int Organizm::GetSila()
{
	return sila;
}

void Organizm::SetSila(int force)
{
	this -> sila = force;
}

int Organizm::GetTuryNaMapie()
{
	return turyNaMapie;
}

int Organizm::GetX()
{
	return x;
}

int Organizm::GetY()
{
	return y;
}

char Organizm::GetZnakASCII()
{
	return znakASCII;
}

void Organizm::Rysuj()
{
	cout<<znakASCII;
}