#include "Swiat.h"
#include "Kolizja.h"
#include <iostream>

using namespace std;

void Swiat::UsunOrganizm(Organizm *organizm)
{
	if (organizm == NULL)
		return;

	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] == organizm)
		{
			organizmy[i] = NULL;
			//delete organizm;
			iloscOrganizmow--;
		}
}

void Swiat::DodajKomunikat(string tresc)
{
	komunikaty.push_back(tresc);
}

void Swiat::DodajOrganizm(Organizm *organizm)
{
	zaktualizujTabliceOrganizmow();
	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] == NULL)
		{
			organizmy[i] = organizm;
			iloscOrganizmow++;
			return;
		}
}

bool Swiat::CzyPoleZajete(int x, int y)
{
	if (x >= szerokosc || y >= wysokosc || x < 0 || y < 0)
		return true;

	for (int i = 0; i < wysokosc * szerokosc; i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetX() == x && organizmy[i] -> GetY() == y)
			return true;

	return false;
}

Organizm *Swiat::GetOrganizmNaPozycji(int x, int y)
{
	for (int i = 0; i < GetWysokosc() * GetSzerokosc(); i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetX() == x && organizmy[i] -> GetY() == y)
			return organizmy[i];

	return NULL;
}

int Swiat::GetSzerokosc()
{
	return szerokosc;
}

int Swiat::GetWysokosc()
{
	return wysokosc;
}

void Swiat::Stworz(int szerokosc, int wysokosc)
{
	kolidujaceOrganizmy = new Organizm*[2]{NULL, NULL};
	maxInicjatywa = 7;
	licznikStarszenstwa = 0;
	this -> szerokosc = szerokosc;
	this -> wysokosc = wysokosc;
	organizmy = new Organizm *[wysokosc * szerokosc];
	for (int i = 0; i < wysokosc * szerokosc; i++)
		organizmy[i] = NULL;
	iloscOrganizmow = 0;
}


void Swiat::RysujSwiat()
{
	for (int i = 0; i < wysokosc * szerokosc; i++)
	{
		Organizm *organizm = GetOrganizmNaPozycji(i % szerokosc, i / wysokosc);
		cout<<"|";
		if (organizm == NULL)
			cout<<" ";
		else
			organizm -> Rysuj();
		if (i % szerokosc == szerokosc - 1)
			cout<<"|"<<endl;
	}

	obsluzKomunikaty();
}

void Swiat::obsluzKomunikaty()
{
	cout<<"Komunikaty:"<<endl;
	if (komunikaty.size() == 0)
	{
		cout<<"Brak"<<endl;
		return;
	}

	for (int i = 0; i < komunikaty.size(); i++)
		cout<<komunikaty[i]<<endl;

	komunikaty.clear();
}

void Swiat::WykonajTure()
{
	Organizm **ustawioneOrganizmy = new Organizm *[iloscOrganizmow];
	ustawOrganizmyWKolejnosciRuchow(ustawioneOrganizmy);
	//for (int i = 0; i < iloscOrganizmow; i++)
		//cout<<(ustawioneOrganizmy)[i] -> GetId()<<" "<<(ustawioneOrganizmy)[i] -> GetInicjatywa()<<endl;

	int iloscUstawionychOrganizmow = iloscOrganizmow;
//hlicz
	for (int i = 0; i < iloscUstawionychOrganizmow; i++)
	{
		if ((ustawioneOrganizmy)[i] == NULL)
		{
			cout<<i<<" NULL"<<endl;
			continue;
		}

		(ustawioneOrganizmy)[i] -> Akcja(this);
		//cout<<i<<" "<<(ustawioneOrganizmy)[i] -> GetId()<<endl;
		obsluzEwentualneKolizje((ustawioneOrganizmy)[i]);
	}

	delete[] ustawioneOrganizmy;
	zaktualizujTabliceOrganizmow();
}

void Swiat::ustawOrganizmyWKolejnosciRuchow(Organizm **ustawioneOrganizmy)
{
	int ograniczenieGorneWlaczne = maxInicjatywa;
	int iloscUstawionychOrganizmow = 0;
	while (iloscUstawionychOrganizmow < iloscOrganizmow)
	{
		int szukanaInicjatywa = getMaxInicjatywa(ograniczenieGorneWlaczne);
		ograniczenieGorneWlaczne = szukanaInicjatywa - 1;
		for (int i = 0; i < iloscOrganizmow; i++)
			if (organizmy[i] -> GetInicjatywa() == szukanaInicjatywa)
			{
				ustawioneOrganizmy[iloscUstawionychOrganizmow] = organizmy[i];
				iloscUstawionychOrganizmow++;
			}
	}
}

int Swiat::getMaxInicjatywa(int ograniczenieGorneWlaczne)
{
	int max = -1;
	for (int i = 0; i < iloscOrganizmow; i++)
		if (organizmy[i] != NULL && organizmy[i] -> GetInicjatywa() <= ograniczenieGorneWlaczne && organizmy[i] -> GetInicjatywa() > max)
			max = organizmy[i] -> GetInicjatywa();

	return max;
}

void Swiat::obsluzEwentualneKolizje(Organizm *organizmZOstatniaAkcja)
{
	//Kolizja kolizja;
	Organizm *organizmZPierwszenstwem, *organizmBezPierwszenstwa;
	for (int i = 0; i < GetWysokosc(); i++)
		for (int j = 0; j < GetSzerokosc(); j++)
		{
			if (!CzyPoleZajete(j, i))
				continue;

			szukajKolizji(j, i);
			if (!wystepujeKolizja())
				continue;
			//kolizja.SzukajKolizji(this, j, i);
			//if (!kolizja.WystepujeKolizja())
				//continue;

			if (kolidujaceOrganizmy[0] == organizmZOstatniaAkcja)
			{
				organizmZPierwszenstwem = kolidujaceOrganizmy[0];
				organizmBezPierwszenstwa = kolidujaceOrganizmy[1];
			}
			else
			{
				organizmZPierwszenstwem = kolidujaceOrganizmy[1];
				organizmBezPierwszenstwa = kolidujaceOrganizmy[0];
			}

			string text = "Kolizja " + organizmZPierwszenstwem -> GetId() + " z " + organizmBezPierwszenstwa -> GetId();
			DodajKomunikat(text);
			organizmZPierwszenstwem -> Kolizja(this, organizmBezPierwszenstwa);
			szukajKolizji(j, i);
			if (!wystepujeKolizja())
				continue;
			//kolizja.SzukajKolizji(this, j, i);
			//if (!kolizja.WystepujeKolizja())
				//continue;
			
			if (organizmZPierwszenstwem -> GetSila() >= organizmBezPierwszenstwa -> GetSila())
			{
				DodajKomunikat(organizmZPierwszenstwem -> GetId() + " zabija " + organizmBezPierwszenstwa -> GetId());
				UsunOrganizm(organizmBezPierwszenstwa);
			}
			else
			{
				DodajKomunikat(organizmBezPierwszenstwa -> GetId() + " zabija " + organizmZPierwszenstwem -> GetId());
				UsunOrganizm(organizmZPierwszenstwem);
			}
		}
}

void Swiat::szukajKolizji(int x, int y)
{
	inicjuj();
	for (int i = 0; i < GetWysokosc() * GetSzerokosc(); i++)
		if (GetOrganizmy()[i] != NULL && GetOrganizmy()[i] -> GetX() == x && GetOrganizmy()[i] -> GetY() == y)
		{
			kolidujaceOrganizmy[iloscKolidujacychOrganizmow] = GetOrganizmy()[i];
			iloscKolidujacychOrganizmow++;
		}
}

void Swiat::inicjuj()
{
	for (int i = 0; i < MAX_ORGANIZMOW_KOLIDUJACYCH; i++)
		kolidujaceOrganizmy[i] = NULL;

	iloscKolidujacychOrganizmow = 0;
}

bool Swiat::wystepujeKolizja()
{
	return iloscKolidujacychOrganizmow == MAX_ORGANIZMOW_KOLIDUJACYCH;
}

Organizm **Swiat::GetOrganizmy()
{
	return organizmy;
}

void Swiat::zaktualizujTabliceOrganizmow()
{
	int wolnyIndeks = GetSzerokosc() * GetWysokosc();
	bool czySzukacWolnegoIndeksu = true;
	for (int i = 0; i < GetSzerokosc() * GetWysokosc(); i++)
	{
		if (czySzukacWolnegoIndeksu && organizmy[i] == NULL)
		{
			wolnyIndeks = i;
			czySzukacWolnegoIndeksu = false;
		}
		else if (organizmy[i] != NULL && i > wolnyIndeks)
		{
			int roznica = i - wolnyIndeks;
			for (int j = wolnyIndeks; j < GetSzerokosc() * GetWysokosc() - roznica; j++)
				organizmy[j] = organizmy[j + roznica];

			i = wolnyIndeks + roznica - 1;
			wolnyIndeks = GetSzerokosc() * GetWysokosc();
			czySzukacWolnegoIndeksu = true;
		}
	}

	for (int i = iloscOrganizmow; i < GetSzerokosc() * GetWysokosc(); i++)
		organizmy[i] = NULL;
}