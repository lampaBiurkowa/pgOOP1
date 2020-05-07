#include "Zwierze.h"
#include <cstdlib>
#include <ctime>

void Zwierze::Akcja()
{
	bool moved = false;
	while (!moved)
		moved = handleStandardMovement();
}

bool Zwierze::handleStandardMovement()
{
	const int DIRECTIONS_COUNT = 4;
	int move = rand() % DIRECTIONS_COUNT;
	if (move == 0 && swiat -> GetSzerokosc() > x + 1)
		SetX(x + 1);
	else if (move == 1 && x > 0)
		SetX(x - 1);
	else if (move == 2 && swiat -> GetWysokosc() > y + 1)
		SetY(y + 1);
	else if (move == 3 && y > 0)
		SetY(y - 1);
	else
		return false;

	return true;
}

void Zwierze::Kolizja()
{

}