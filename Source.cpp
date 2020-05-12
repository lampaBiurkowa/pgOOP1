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
	swiat.WykonajTure();
	swiat.RysujSwiat();
	swiat.WykonajTure();
	swiat.RysujSwiat();
	swiat.WykonajTure();

	return 0;
}