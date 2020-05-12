#include <iostream>
#include "Guarana.h"
#include "Swiat.h"

using namespace std;

Guarana::Guarana(int x, int y) : Roslina(x, y)
{
	id = "guarana";
	sila = 0;
}

void Guarana::Kolizja(Swiat *swiat, Organizm *organizm)
{
	const int ZWIEKSZENIE_SILY = 3;

	organizm -> SetSila(organizm -> GetSila() + ZWIEKSZENIE_SILY);
	swiat -> DodajKomunikat(organizm -> GetId() + " zjadl " + id + " i jego sila wyno sila zwiekszyla sie o 3");
}

void Guarana::Rysuj()
{
	cout<<"g";
}

Guarana *Guarana::zwrocInstancjeRosliny(int x, int y)
{
	return new Guarana(x, y);
}