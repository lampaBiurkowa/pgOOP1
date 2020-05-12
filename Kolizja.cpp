#include "Kolizja.h"
#include "Swiat.h"

Kolizja::Kolizja(Swiat *swiat, int x, int y)
{
	kolidujaceOrganizmy = new Organizm*[2] { NULL, NULL };
;	iloscKolidujacychOrganizmow = 0;
	for (int i = 0; i < swiat -> GetWysokosc() * swiat -> GetSzerokosc(); i++)
		if (swiat -> GetOrganizmy()[i] != NULL && swiat -> GetOrganizmy()[i] -> GetX() == x && swiat -> GetOrganizmy()[i] -> GetY() == y)
		{
			kolidujaceOrganizmy[iloscKolidujacychOrganizmow] = swiat -> GetOrganizmy()[i];
			iloscKolidujacychOrganizmow++;
		}
}

bool Kolizja::WystepujeKolizja()
{
	return iloscKolidujacychOrganizmow == 2;
}

Organizm** Kolizja::GetKolidujaceOrganizmy()
{
	return kolidujaceOrganizmy;
}