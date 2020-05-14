#include <iostream>
#include "Swiat.h"
#include "WilczeJagody.h"

using namespace std;

WilczeJagody::WilczeJagody(int x, int y) : Roslina(x, y)
{
	id = "wilczeJagody";
	sila = 99;
}

void WilczeJagody::Kolizja(Swiat *swiat, Organizm *organizm)
{
	swiat -> DodajKomunikat(organizm -> GetId() + " zjadl " + id + " i nie zyje");
	swiat -> UsunOrganizm(organizm);
}

void WilczeJagody::Rysuj()
{
	cout<<"w";
}

WilczeJagody *WilczeJagody::zwrocInstancjeRosliny(int x, int y)
{
	return new WilczeJagody(x, y);
}