#include "Mlecz.h"
#include <iostream>

using namespace std;

Mlecz::Mlecz()
{
	id = "mlecz";
	sila = 0;
}

void Mlecz::Akcja(Swiat *swiat)
{
	for (int i = 0; i < 3; i++)
		if (rand() % 10 > 7)
			zasiejRosline(swiat);
}

void Mlecz::Rysuj()
{
	cout<<"m";
}