#pragma once

#include "Zwierze.h"

class Wilk : public Zwierze
{
	Wilk *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'W';

	Wilk(int x, int y);
};