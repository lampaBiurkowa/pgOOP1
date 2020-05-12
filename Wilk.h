#pragma once

#include "Zwierze.h"

class Wilk : public Zwierze
{
	Wilk *zwrocInstancjeZwierzecia(int x, int y) override;
public:
	Wilk(int x, int y);
	void Rysuj() override;
};