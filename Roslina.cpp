#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int x, int y) : Organizm(x, y)
{
	inicjatywa = 0;
}

void Roslina::Akcja(Swiat *swiat)
{
	if (rand() % 100 < SZANSE_NA_ROZPRZESTRZENIENIE_W_PROCENTACH)
	{
		bool czyUdaloSieZasiac = false;
		while (!czyUdaloSieZasiac)
			czyUdaloSieZasiac = sprobujZasiacRosline(swiat);

		swiat -> DodajKomunikat(nazwa + " zasialo brata");
	}
}

bool Roslina::sprobujZasiacRosline(Swiat *swiat, int step)
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