#pragma once

#include "Roslina.h"

class Trawa : public Roslina
{
protected:
	Roslina *zwrocInstancjeRosliny(unsigned int x, unsigned int y) override;
public:
	Trawa(unsigned int x, unsigned int y);
	void Rysuj() override;
};