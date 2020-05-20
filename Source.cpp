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
	budulec.WczytajZPliku(&swiat, "jea.txt");
	Czlowiek *czlowiek = swiat.SprobujZnalezcCzlowieka();
	swiat.RysujSwiat();
	char wybor;
	for (int i = 0; i < 30; i++)
	{
		czlowiek = swiat.SprobujZnalezcCzlowieka();
		if (czlowiek != NULL)
		{
			cout<<"Pozostala ilosc tur z wazna supermoca: "<<czlowiek -> GetPozostalaIloscTurZSupermoca()<<endl;
			cout<<"Ilosc tur do ponownego aktywowania supermocy: "<<czlowiek -> GetIloscTurDoUzyciaSupermocy() + czlowiek -> GetPozostalaIloscTurZSupermoca()<<endl;
			if (czlowiek -> GetIloscTurDoUzyciaSupermocy() == 0)
			{
				cout<<"Czy aktywowac supermoc? (t/N)";
				cin>>wybor;
				if (wybor == 't')
					czlowiek -> SprobujAktywowacSuperMoc();
			}
			czlowiek -> WczytajInformacjeORuchu(&swiat);
		}
		system("cls");
		swiat.WykonajTure();
		swiat.RysujSwiat();
		budulec.ZapiszDoPliku(&swiat, "jea" + to_string(i) + ".txt");
	}

	return 0;
}