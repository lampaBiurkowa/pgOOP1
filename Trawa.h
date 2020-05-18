#pragma once

#include "Roslina.h"

class Trawa : public Roslina
{
	Trawa *zwrocInstancjeRosliny(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 't';
	static const int DOMYSLNA_SILA = 0;

	Trawa(int x, int y);
};