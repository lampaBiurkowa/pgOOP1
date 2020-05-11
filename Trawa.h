#pragma once

#include "Roslina.h"

class Trawa : public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(int x, int y) override;
public:
	Trawa(int x, int y);
	void Rysuj() override;
};