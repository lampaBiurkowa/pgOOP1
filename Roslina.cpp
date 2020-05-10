#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(unsigned int x, unsigned int y) : Organizm(x, y)
{
	inicjatywa = 0;
}

void Roslina::Akcja(Swiat *swiat)
{
	if (rand() % 10 > 7)
	{
		bool czyUdaloSieZasiac = false;
		while (!czyUdaloSieZasiac)
			sprubujZasiacRosline(swiat);
	}
}

bool Roslina::sprubujZasiacRosline(Swiat *swiat, int step)
{
	int zmianaX = rand() % (2 * step + 1) - step;
	int zmianaY = rand() % (2 * step + 1) - step;
	if (zmianaX == 0 && zmianaY == 0)
		return false;

	if (x + zmianaX < 0 || x + zmianaX >= swiat -> GetSzerokosc() || y + zmianaY < 0 || y + zmianaY >= swiat -> GetWysokosc())
		return false;

	Roslina *roslina = zwrocInstancjeRosliny(x + zmianaX, y + zmianaY);
	swiat -> DodajOrganizm(roslina);
	return true;
}

void Roslina::Kolizja(Swiat *swiat, Organizm *organizm)
{
	
}