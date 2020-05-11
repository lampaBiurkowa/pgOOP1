#include "Wilk.h"
#include <iostream>

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