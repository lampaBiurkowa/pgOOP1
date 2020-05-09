#include "Guarana.h"
#include <iostream>

using namespace std;

Guarana::Guarana()
{
	id = "guarana";
	sila = 0;
}

void Guarana::Kolizja(Swiat *swiat, Organizm *organizm)
{
	organizm -> SetSila(organizm -> GetSila() + 3);
}

void Guarana::Rysuj()
{
	cout<<"g";
}