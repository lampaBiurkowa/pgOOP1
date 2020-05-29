#include <iostream>
#include "Guarana.h"
#include "Swiat.h"
#include "Zwierze.h"

using namespace std;

Guarana::Guarana(int x, int y) : Roslina(x, y)
{
	nazwa = "Guarana";
	sila = 0;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

void Guarana::Kolizja(Swiat *swiat, Organizm *organizm)
{
	if (dynamic_cast<Zwierze *>(organizm) != nullptr)
	{
		organizm -> SetSila(organizm -> GetSila() + ZWIEKSZENIE_SILY);
		((Zwierze *)(organizm)) -> OznaczZwiekszenieSily(ZWIEKSZENIE_SILY);
		swiat -> DodajKomunikat(((Zwierze *)(organizm)) -> GetNazwa() + " zjadl " + nazwa + " i jego sila zwiekszyla sie o 3");
	}
}

Guarana *Guarana::zwrocInstancjeRosliny(int x, int y)
{
	return new Guarana(x, y);
}