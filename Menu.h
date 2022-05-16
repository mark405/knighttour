#pragma once
#include "Move.h"

class Menu//class that has all methods related to the menu
{
public:
	void PrintOptions();//printing menu
	int ChooseDestiny();//choosing of action
	void EnterPositions(int &row, int &col, char &colChar);//entering starting positions
};
