#include "Guarana.h"
#include <iostream>

using namespace std;

Guarana::Guarana(unsigned int x, unsigned int y) : Roslina(x, y)
{
	id = "guarana";
	sila = 0;
}

Roslina *Guarana::zwrocInstancjeRosliny(unsigned int x, unsigned int y)
{
	return new Guarana(x, y);
}

void Guarana::Kolizja(Swiat *swiat, Organizm *organizm)
{
	organizm -> SetSila(organizm -> GetSila() + 3);
}

void Guarana::Rysuj()
{
	cout<<"g";
}