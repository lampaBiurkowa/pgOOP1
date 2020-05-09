#include "WilczeJagody.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

WilczeJagody::WilczeJagody()
{
	id = "wilczeJagody";
	sila = 99;
}

void WilczeJagody::Kolizja(Swiat *swiat, Organizm *organizm)
{
	swiat -> UsunOrganizm(organizm);
}

void WilczeJagody::Rysuj()
{
	cout<<"g";
}