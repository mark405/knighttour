#include "MovesCounter.h"

int MovesCounter::count = 0; // value of count at the beginning

int MovesCounter::IncreaseCount() //method for increasing count by one 
{
	count++;
	return count;
}

void MovesCounter::ResetCount() // method for reseting counter (make it zero)
{
	count = 0;
}

int MovesCounter::Getcount() //method for getting current count value
{
	return count; 
}
