#pragma once

#include "Zwierze.h"

class Czlowiek : public Zwierze
{
	const int STRZALKA_GORA_KOD = 72;
	const int STRZALKA_DOL_KOD = 80;
	const int STRZALKA_LEWO_KOD = 77;
	const int STRZALKA_PRAWO_KOD = 75;
	const int STRZALKA_KOD_KONTROLNY = 0;

	Czlowiek *zwrocInstancjeZwierzecia(int x, int y);
	void aktualizujStanSupermocyPoUzyciu();
	const int ILOSC_TUR_Z_WAZNA_SUPERMOCA = 5;
	const int ILOSC_TUR_DO_ODTWORZENIA_SUPERMOCY = 5;
	const int ZASIEG_ZNISZCZEN = 1;
	int pozostalaIloscTurZSupermoca;
	int iloscTurDoUzyciaSupermocy;
public:
	static const char IDENTYFIKATOR_PLIKU = 'C';
	static const int DOMYSLNA_SILA = 5;

	Czlowiek(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	int GetPozostalaIloscTurZSupermoca();
	int GetIloscTurDoUzyciaSupermocy();
	bool SprobujAktywowacSuperMoc();
};