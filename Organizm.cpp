#include "Organizm.h"

Organizm::Organizm(int x, int y)
{
	this -> x = x;
	this -> y = y;
}

string Organizm::GetId()
{
	return id;
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

void Organizm::Move(int x, int y)
{
	this -> x += x;
	this -> y += y;
}