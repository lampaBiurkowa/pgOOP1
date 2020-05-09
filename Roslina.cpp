#include "Roslina.h"

void Roslina::Akcja(Swiat *swiat)
{
	if (rand() % 10 > 7)
		zasiejRosline(swiat);
}