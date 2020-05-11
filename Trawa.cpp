#include "Trawa.h"
#include <iostream>

using namespace std;

Trawa::Trawa(int x, int y) : Roslina(x, y)
{
	id = "trawa";
	sila = 0;
}

Roslina* Trawa::zwrocInstancjeRosliny(int x, int y)
{
	return new Trawa(x, y);
}

void Trawa::Rysuj()
{
	cout<<"t";
}