#include <cstdlib>
#include <time.h>
#include "Menu.h"

int main()
{
	srand(time(NULL));
	Menu menu;
	menu.Wykonaj();

	return 0;
}