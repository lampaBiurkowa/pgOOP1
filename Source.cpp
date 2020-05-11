#include "Swiat.h"
#include "BudulecSwiata.h"

int main()
{
	Swiat swiat;
	swiat.Stworz(20, 20);
	BudulecSwiata budulec;
	budulec.RozstawOrganizmy(&swiat, 3);
	swiat.RysujSwiat();

	swiat.WykonajTure();

	return 0;
}