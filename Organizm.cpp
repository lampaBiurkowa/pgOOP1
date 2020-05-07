#include "Organizm.h"

unsigned int Organizm::GetSila()
{
	return sila;
}

void Organizm::SetForce(unsigned int force)
{
	this -> sila = force;
}

unsigned int Organizm::GetInicjatywa()
{
	return inicjatywa;
}

void Organizm::SetInitiative(unsigned int initiative)
{
	this -> inicjatywa = initiative;
}

unsigned int Organizm::GetX()
{
	return x;
}

void Organizm::SetX(unsigned int x)
{
	this -> x = x;
}

unsigned int Organizm::GetY()
{
	return y;
}

void Organizm::SetY(unsigned int y)
{
	this -> y = y;
}

void Organizm::Move(int x, int y)
{
	this -> x += x;
	this -> y += y;
}