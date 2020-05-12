#include <iostream>
#include "Wilk.h"

using namespace std;

Wilk::Wilk(int x, int y): Zwierze(x, y)
{
	id = "wilk";
	sila = 9;
	inicjatywa = 5;
}

void Wilk::Rysuj()
{
	cout<<"W";
}

Wilk *Wilk::zwrocInstancjeZwierzecia(int x, int y)
{
	return new Wilk(x, y);
}