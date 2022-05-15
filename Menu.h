#pragma once
#include "Move.h"

class Menu
{
public:
	void PrintOptions();
	int ChooseDestiny();
	void EnterPositions(int &row, int &col, char &colChar);
};
