#include "Zolw.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

Zolw::Zolw(int x, int y) : Zwierze(x, y)
{
	id = "zolw";
	inicjatywa = 1;
	sila = 2;
}

void Zolw::Akcja(Swiat *swiat)
{
	int czyStoiWMiejscu = rand() % 4 < 4;
	if (czyStoiWMiejscu)
		return;

	bool czySiePoruszyl = false;
	while (!czySiePoruszyl)
		czySiePoruszyl = sprubojWykonacRuch(swiat, 2);
}

void Zolw::Kolizja(Swiat *swiat, Organizm *organizm)
{
	if (dynamic_cast<Zwierze *>(organizm) != nullptr)
		if (((Zwierze *)(organizm)) -> GetSila() < 5)
			((Zwierze *)(organizm)) -> Cofnij();
}

void Zolw::Rysuj()
{
	cout<<"Z";
}