#include "Owca.h"
#include <iostream>

using namespace std;

Owca::Owca(unsigned int x, unsigned int y): Zwierze(x, y)
{
	inicjatywa = 4;
	sila = 4;
}

void Owca::Rysuj()
{
	cout<<"O";
}