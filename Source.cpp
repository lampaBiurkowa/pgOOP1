#include "Swiat.h"
#include "BudulecSwiata.h"

#include<iostream>
using namespace std;

int main()
{
	Swiat swiat;
	//swiat.Stworz(20, 20);
	BudulecSwiata budulec;
	//budulec.RozstawOrganizmyLosowo(&swiat, 3);
	budulec.WczytajZPliku(&swiat, "jea15.txt");
	swiat.RysujSwiat();
	for (int i = 0; i < 30; i++)
	{
		swiat.WykonajTure();
		swiat.RysujSwiat();
		budulec.ZapiszDoPliku(&swiat, "jea" + to_string(i) + ".txt");
	}

	return 0;
}