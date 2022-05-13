#pragma once
#include "Move.h"

class Menu
{
public:
	void PrintOptions();
	int ChooseDestiny();
	void EnterPositions(int &row,char &CharRow, int &col);  
};

