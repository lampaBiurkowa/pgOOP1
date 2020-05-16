#pragma once

#include "Zwierze.h"

class Owca: public Zwierze
{
	Owca *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	static const char IDENTYFIKATOR_PLIKU = 'O';
	
	Owca(int x, int y);
};