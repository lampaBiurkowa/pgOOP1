#include "Zwierze.h"
#include "Swiat.h"
#include <cstdlib>
#include <ctime>

Zwierze::Zwierze(int x, int y) : Organizm(x, y)
{
	previousX = x;
	previousY = y;
}

void Zwierze::Cofnij()
{
	x = previousX;
	y = previousY;
}

bool Zwierze::SprubojPrzesunacO(int x, int y, Swiat *swiat)
{
	if (this -> x + x >= swiat -> GetSzerokosc() || this -> x + x < 0)
		return false;
	if (this -> y + y >= swiat -> GetWysokosc() || this -> y + x < 0)
		return false;

	this -> x += x;
	this -> y += y;
	return true;
}

void Zwierze::Akcja(Swiat *swiat)
{
	previousX = x;
	previousY = y;
	bool czyUdaloSiePoruszyc = false;
	while (!czyUdaloSiePoruszyc)
		czyUdaloSiePoruszyc = sprubojWykonacRuch(swiat);
}

bool Zwierze::sprubojWykonacRuch(Swiat *swiat, int step)
{
	int zmianaX = rand() % (2 * step + 1) - step;
	int zmianaY = rand() % (2 * step + 1) - step;

	if (zmianaX == 0 && zmianaY == 0)
		return false;
	
	return SprubojPrzesunacO(zmianaX, zmianaY, swiat);
}

void Zwierze::Kolizja(Swiat *swiat, Organizm *organizm)
{
	if (organizm -> GetId() == id)
	;//
}