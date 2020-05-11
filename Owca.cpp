#include "Owca.h"
#include <iostream>

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