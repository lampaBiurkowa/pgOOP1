#include <iostream>
#include "Owca.h"

using namespace std;

Owca::Owca(int x, int y): Zwierze(x, y)
{
	id = "owca";
	inicjatywa = 4;
	sila = 4;
}

void Owca::Rysuj()
{
	cout<<"O";
}

Owca *Owca::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Owca(x, y);
}