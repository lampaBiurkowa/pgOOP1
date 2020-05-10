#pragma once

#include "Zwierze.h"

class Wilk : public Zwierze
{
public:
	Wilk(unsigned int x, unsigned int y);
	void Rysuj() override;
};