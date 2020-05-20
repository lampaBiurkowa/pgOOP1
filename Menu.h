#pragma once

#include <iostream>
#include "BudulecSwiata.h"
#include "Swiat.h"

class Menu
{
	static const char WYBOR_PLIK = 'p';
	static const char WYBOR_LOSOWO = 'l';

	Swiat swiat;
	BudulecSwiata budulec;

	void obslozInicjalizacjeSwiata();
	void obslozRuchCzlowiekaJezeliIstnieje();
	void obslozSymulacje();
	void obslozTure();
	void obslozWczytanieSwiataZPliku();
	void obslozWygenerowanieSwiata();
	void obslozZapisDoPliku();

public:
	void Wykonaj();
};