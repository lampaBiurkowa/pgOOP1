#include "Menu.h"

void Menu::Wykonaj()
{
	char wybor = '\0';

	obslozInicjalizacjeSwiata();
	swiat.RysujSwiat();
	while (true)
	{
		obslozTure();
		cout<<"Czy przejsc do nastepnej tury? (T/n)"<<endl;
		cin>>wybor;
		if (wybor == 'n')
			break;
	}
}

void Menu::obslozInicjalizacjeSwiata()
{
	char wybor = '\0';
	while (wybor != WYBOR_PLIK && wybor != WYBOR_LOSOWO)
	{
		cout<<"Wczytac swiat z pliku (podaj "<<WYBOR_PLIK<<") czy wygenerowac losowy? (podaj "<<WYBOR_LOSOWO<<")"<<endl;
		cin>>wybor;
	}
	if (wybor == WYBOR_PLIK)
		obslozWczytanieSwiataZPliku();
	else
		obslozWygenerowanieSwiata();
}

void Menu::obslozWczytanieSwiataZPliku()
{
	string nazwaPliku;
	cout<<"Podaj nazwe pliku"<<endl;
	cin>>nazwaPliku;
	budulec.WczytajZPliku(&swiat, nazwaPliku);
}

void Menu::obslozWygenerowanieSwiata()
{
	int x, y, iloscSztuk;
	cout<<"Podaj x"<<endl;
	cin>>x;
	cout<<"Podaj y"<<endl;
	cin>>y;
	cout<<"Podaj poczatkowa ilosc sztuk organizmow (oprocz czlowieka)"<<endl;
	cin>>iloscSztuk;
	swiat.Stworz(x, y);
	budulec.RozstawOrganizmyLosowo(&swiat, iloscSztuk);
}

void Menu::obslozTure()
{
	cout<<"Numer tury: "<<swiat.GetNumerTury() + 1<<endl;
	obslozRuchCzlowiekaJezeliIstnieje();
	obslozSymulacje();
	obslozZapisDoPliku();
}

void Menu::obslozRuchCzlowiekaJezeliIstnieje()
{
	Czlowiek *czlowiek = swiat.SprobujZnalezcCzlowieka();
	char wybor = '\0';

	cout<<"Twoja si³a: "<<czlowiek -> GetSila()<<endl;
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

void Menu::obslozSymulacje()
{
	system("cls");
	cout<<"Symulowanie..."<<endl;
	swiat.WykonajTure();
	swiat.RysujSwiat();
}

void Menu::obslozZapisDoPliku()
{
	char wybor = '\0';
	cout<<"Czy zapisac do pliku? (t/N)"<<endl;
	cin>>wybor;
	if (wybor == 't')
	{
		string nazwaPliku;
		cout<<"Podaj nazwe pliku"<<endl;
		cin>>nazwaPliku;
		budulec.ZapiszDoPliku(&swiat, nazwaPliku);
	}
}