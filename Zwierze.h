#pragma once

#include "Organizm.h"

class Zwierze : public Organizm
{
	bool handleStandardMovement();
public:
	virtual void Akcja();
	virtual void Kolizja();
};