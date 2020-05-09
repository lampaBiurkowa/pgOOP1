#include "Zwierze.h"
#include "Swiat.h"
#include <cstdlib>
#include <ctime>

void Zwierze::Cofnij()
{
	x = previousX;
	y = previousY;
}

bool Zwierze::SprubojPrzesunacO(int x, int y)
{
	if (this -> x + x >= swiat -> GetSzerokosc() || this -> x + x < 0)
		return false;
	if (this -> y + y >= swiat -> GetWysokosc() || this -> y + x < 0)
		return false;

	this -> x += x;
	this -> y += y;
}

void Zwierze::Akcja(Swiat *swiat)
{
	previousX = x;
	previousY = y;
	bool moved = false;
	while (!moved)
		moved = sprubojWykonacRuch();
}

bool Zwierze::sprubojWykonacRuch(int step)
{
	int zmianaX = rand() % (2 * step + 1) - step;
	int zmianaY = rand() % (2 * step + 1) - step;

	if (zmianaX == 0 && zmianaY == 0)
		return false;
	
	return SprubojPrzesunacO(zmianaX, zmianaY);
}

void Zwierze::Kolizja(Swiat *swiat)
{
	if (swiat -> GetOrganizmNaPozycji(x, y) -> GetId() == id)
	;//
}