#pragma once

#include "Zwierze.h"

class Owca: public Zwierze
{
	Owca *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	Owca(int x, int y);
	void Rysuj() override;
};