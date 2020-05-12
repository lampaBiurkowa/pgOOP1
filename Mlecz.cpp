#include "Mlecz.h"
#include <iostream>

using namespace std;

Mlecz::Mlecz(int x, int y) : Roslina(x, y)
{
	id = "mlecz";
	sila = 0;
}

Roslina *Mlecz::zwrocInstancjeRosliny(int x, int y)
{
	return new Mlecz(x, y);
}

void Mlecz::Akcja(Swiat *swiat)
{
	for (int i = 0; i < 3; i++)
		if (rand() % 10 > 7)
		{
			bool czyUdaloSieZasiac = false;
			while (!czyUdaloSieZasiac)
				czyUdaloSieZasiac = sprubujZasiacRosline(swiat);
		}
}

void Mlecz::Rysuj()
{
	cout<<"m";
}