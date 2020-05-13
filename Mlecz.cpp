#include <iostream>
#include "Mlecz.h"
#include "Swiat.h"

using namespace std;

Mlecz::Mlecz(int x, int y) : Roslina(x, y)
{
	id = "mlecz";
	sila = 0;
}

void Mlecz::Akcja(Swiat *swiat)
{
	const int ILOSC_PROB_ROZPRZESTRZENIENIA = 3;
	for (int i = 0; i < ILOSC_PROB_ROZPRZESTRZENIENIA; i++)
		if (rand() % 100 < SZANSE_NA_ROZPRZESTRZENIENIE_W_PROCENTACH)
		{
			bool czyUdaloSieZasiac = false;
			while (!czyUdaloSieZasiac)
				czyUdaloSieZasiac = sprobujZasiacRosline(swiat);

			//swiat -> DodajKomunikat(id + " zasialo brata");
		}
}

void Mlecz::Rysuj()
{
	cout<<"m";
}

Mlecz *Mlecz::zwrocInstancjeRosliny(int x, int y)
{
	return new Mlecz(x, y);
}