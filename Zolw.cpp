#include "Zolw.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

Zolw::Zolw()
{
	id ="zolw";
	inicjatywa = 1;
	sila = 2;
}

void Zolw::Akcja(Swiat *swiat)
{
	int czyStoiWMiejscu = rand() % 4 < 4;
	if (czyStoiWMiejscu)
		return;

	bool czySiePoruszyl;
	while (!czySiePoruszyl)
		czySiePoruszyl = sprubojWykonacRuch(2);
}

void Zolw::Kolizja(Swiat *swiat)
{
	if (dynamic_cast<Zwierze *>(swiat -> GetOrganizmNaPozycji(x, y)) != nullptr)
		if (((Zwierze *)(swiat -> GetOrganizmNaPozycji(x, y))) -> GetSila() < 5)
			((Zwierze *)(swiat -> GetOrganizmNaPozycji(x, y))) -> Cofnij();
}

void Zolw::Rysuj()
{
	cout<<"Z";
}