#pragma once

#include "Zwierze.h"

class Czlowiek : public Zwierze
{
	static const int STRZALKA_GORA_KOD = 72;
	static const int STRZALKA_DOL_KOD = 80;
	static const int STRZALKA_LEWO_KOD = 77;
	static const int STRZALKA_PRAWO_KOD = 75;
	static const int STRZALKA_KOD_KONTROLNY = 0;

	static const int ILOSC_TUR_DO_ODTWORZENIA_SUPERMOCY = 5;
	static const int ILOSC_TUR_DO_OSLABIENIA_SUPERMOCY = 3;
	static const int ILOSC_TUR_Z_WAZNA_SUPERMOCA = 5;
	static const int KROK_Z_SUPERMOCA = 2;
	static const int PROCENT_SZANS_NA_SUPERMOC_PO_OSLABIENIU = 50;
	static const int STANDARDOWY_KROK = 1;

	int pozostalaIloscTurZSupermoca;
	int iloscTurDoUzyciaSupermocy;
	int wybranaZmianaX, wybranaZmianaY;

	Czlowiek *zwrocInstancjeZwierzecia(int x, int y);
	void aktualizujStanSupermocyPoUzyciu();
	bool czyDzialaSupermoc();
public:
	static const char IDENTYFIKATOR_PLIKU = 'C';

	Czlowiek(int x, int y);
	void Akcja(Swiat *swiat) override;
	void Kolizja(Swiat *swiat, Organizm *organizm) override;
	int GetIloscTurDoUzyciaSupermocy() const;
	int GetPozostalaIloscTurZSupermoca() const;
	void SetIloscTurDoUzyciaSupermocy(int iloscTurDoUzyciaSupermocy);
	void SetPozostalaIloscTurZSupermoca(int pozostalaIloscTurZSupermoca);
	bool SprobujAktywowacSuperMoc();
	void WczytajInformacjeORuchu(Swiat *swiat);
};