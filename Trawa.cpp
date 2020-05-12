#include <iostream>
#include "Trawa.h"

using namespace std;

Trawa::Trawa(int x, int y) : Roslina(x, y)
{
	id = "trawa";
	sila = 0;
}

void Trawa::Rysuj()
{
	cout<<"t";
}

Trawa *Trawa::zwrocInstancjeRosliny(int x, int y)
{
	return new Trawa(x, y);
}