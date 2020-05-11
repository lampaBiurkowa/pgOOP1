#include "WilczeJagody.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

WilczeJagody::WilczeJagody(int x, int y) : Roslina(x, y)
{
	id = "wilczeJagody";
	sila = 99;
}

Roslina *WilczeJagody::zwrocInstancjeRosliny(int x, int y)
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