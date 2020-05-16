#include <iostream>
#include "Mlecz.h"
#include "Swiat.h"

using namespace std;

Mlecz::Mlecz(int x, int y) : Roslina(x, y)
{
	nazwa = "mlecz";
	sila = 0;
	znakASCII = IDENTYFIKATOR_PLIKU;
}

void Mlecz::Akcja(Swiat *swiat)
{
	int **uzyteMiejsca = new int*[ILOSC_PROB_ROZPRZESTRZENIENIA];
	for (int i = 0; i < ILOSC_PROB_ROZPRZESTRZENIENIA; i++)
		uzyteMiejsca[i] = new int[2]{-1, -1};

	for (int i = 0; i < ILOSC_PROB_ROZPRZESTRZENIENIA; i++)
		if (rand() % 100 < SZANSE_NA_ROZPRZESTRZENIENIE_W_PROCENTACH)
		{
			bool czyUdaloSieZasiac = false;
			while (!czyUdaloSieZasiac)
				czyUdaloSieZasiac = sprobujZasiacRosline(swiat, uzyteMiejsca);

			uzyteMiejsca[i][0] = swiat -> GetOrganizmy()[swiat -> GetIloscOrganizmow() - 1] -> GetX();
			uzyteMiejsca[i][1] = swiat -> GetOrganizmy()[swiat -> GetIloscOrganizmow() - 1] -> GetY();
			swiat -> DodajKomunikat(nazwa + " zasialo brata");
		}

	delete[] uzyteMiejsca;
}

bool Mlecz::sprobujZasiacRosline(Swiat *swiat, int **uzyteMiejsca)
{
	int zmianaX = rand() % (2 * KROK_ROZPRZESTRZENIANIA + 1) - KROK_ROZPRZESTRZENIANIA;
	int zmianaY = rand() % (2 * KROK_ROZPRZESTRZENIANIA + 1) - KROK_ROZPRZESTRZENIANIA;
	if (zmianaX == 0 && zmianaY == 0)
		return false;

	if (x + zmianaX < 0 || x + zmianaX >= swiat -> GetSzerokosc() || y + zmianaY < 0 || y + zmianaY >= swiat -> GetWysokosc())
		return false;

	for (int i = 0; i < ILOSC_PROB_ROZPRZESTRZENIENIA; i++)
		if (uzyteMiejsca[i][0] == x + zmianaX && uzyteMiejsca[i][1] == y + zmianaY)
			return false;

	Roslina *roslina = zwrocInstancjeRosliny(x + zmianaX, y + zmianaY);
	swiat -> DodajOrganizm(roslina);
	return true;
}

Mlecz *Mlecz::zwrocInstancjeRosliny(int x, int y)
{
	return new Mlecz(x, y);
}