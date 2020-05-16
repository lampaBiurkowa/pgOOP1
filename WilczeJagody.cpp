#include <iostream>
#include "Swiat.h"
#include "WilczeJagody.h"

using namespace std;

WilczeJagody::WilczeJagody(int x, int y) : Roslina(x, y)
{
	nazwa = "wilczeJagody";
	sila = 99;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

void WilczeJagody::Kolizja(Swiat *swiat, Organizm *organizm)
{//TODO a jak roslina ? d
	swiat -> DodajKomunikat(organizm -> GetNazwa() + " zjadl " + nazwa + " i nie zyje");
	swiat -> UsunOrganizm(organizm);
}

WilczeJagody *WilczeJagody::zwrocInstancjeRosliny(int x, int y)
{
	return new WilczeJagody(x, y);
}