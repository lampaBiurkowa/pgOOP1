#include "Swiat.h"
#include "BudulecSwiata.h"

#include<iostream>
using namespace std;

int main()
{
	Swiat swiat;
	swiat.Stworz(20, 20);
	BudulecSwiata budulec;
	budulec.RozstawOrganizmy(&swiat, 3);
	swiat.RysujSwiat();
	for (int i = 0; i < 30; i++)
	{
		swiat.WykonajTure();
		swiat.RysujSwiat();
	}

	return 0;
}