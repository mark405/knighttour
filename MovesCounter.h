#pragma once

class MovesCounter
{
private:
	static int count;
public:   
	static int IncreaseCount();
	static void ResetCount(); 
	static int Getcount(); 
};

