#include "Organizm.h"

Organizm::Organizm(int x, int y)
{
	this -> x = x;
	this -> y = y;
	starszenstwo = 0;
}

string Organizm::GetId()
{
	return id;
}

int Organizm::GetInicjatywa()
{
	return inicjatywa;
}

void Organizm::SetInitiative(int initiative)
{
	this -> inicjatywa = initiative;
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

void Organizm::SetX(int x)
{
	this -> x = x;
}

int Organizm::GetY()
{
	return y;
}

void Organizm::SetY(int y)
{
	this -> y = y;
}

void Organizm::Move(int x, int y)
{
	this -> x += x;
	this -> y += y;
}