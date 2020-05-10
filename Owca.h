#pragma once

#include "Zwierze.h"

class Owca: public Zwierze
{
public:
	Owca(unsigned int x, unsigned int y);
	void Rysuj() override;
};