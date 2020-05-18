#pragma once

#include "Zwierze.h"

class Wilk : public Zwierze
{
	Wilk *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'W';
	static const int DOMYSLNA_SILA = 9;

	Wilk(int x, int y);
};