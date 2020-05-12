#pragma once

#include "Roslina.h"

class Trawa : public Roslina
{
	Trawa *zwrocInstancjeRosliny(int x, int y) override;
public:
	Trawa(int x, int y);
	void Rysuj() override;
};