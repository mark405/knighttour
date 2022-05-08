#include "MovesCounter.h"

int MovesCounter::count = 0;

int MovesCounter::IncreaseCount()
{
	count++;
	return count;
}

void MovesCounter::ResetCount()
{
	count = 0;
}

int MovesCounter::Getcount()
{
	return count; 
}
