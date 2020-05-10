#include "WilczeJagody.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

WilczeJagody::WilczeJagody(unsigned int x, unsigned int y) : Roslina(x, y)
{
	id = "wilczeJagody";
	sila = 99;
}

Roslina *WilczeJagody::zwrocInstancjeRosliny(unsigned int x, unsigned int y)
{
	return new WilczeJagody(x, y);
}

void WilczeJagody::Kolizja(Swiat *swiat, Organizm *organizm)
{
	swiat -> UsunOrganizm(organizm);
}

void WilczeJagody::Rysuj()
{
	cout<<"g";
}