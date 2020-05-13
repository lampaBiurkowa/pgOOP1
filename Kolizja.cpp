#include "Kolizja.h"
#include "Swiat.h"

Kolizja::Kolizja()
{
	kolidujaceOrganizmy = new Organizm*[MAX_ORGANIZMOW_KOLIDUJACYCH]{NULL, NULL};
	inicjuj();
}

void Kolizja::inicjuj()
{
	for (int i = 0; i < MAX_ORGANIZMOW_KOLIDUJACYCH; i++)
		kolidujaceOrganizmy[i] = NULL;

	iloscKolidujacychOrganizmow = 0;
}

Organizm **Kolizja::GetKolidujaceOrganizmy()
{
	return kolidujaceOrganizmy;
}

void Kolizja::SzukajKolizji(Swiat *swiat, int x, int y)
{
	inicjuj();
	for (int i = 0; i < swiat -> GetWysokosc() * swiat -> GetSzerokosc(); i++)
		if (swiat -> GetOrganizmy()[i] != NULL && swiat -> GetOrganizmy()[i] -> GetX() == x && swiat -> GetOrganizmy()[i] -> GetY() == y)
		{
			kolidujaceOrganizmy[iloscKolidujacychOrganizmow] = swiat -> GetOrganizmy()[i];
			iloscKolidujacychOrganizmow++;
		}
}

bool Kolizja::WystepujeKolizja()
{
	return iloscKolidujacychOrganizmow == MAX_ORGANIZMOW_KOLIDUJACYCH;
}

Kolizja::~Kolizja()
{
	//delete[] kolidujaceOrganizmy;
}