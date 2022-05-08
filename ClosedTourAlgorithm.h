#pragma once
#include "Printer.h"
#include "Move.h"

enum STATUS
{
	SUCCESS,
	TRAP,
	FAILURE
};

class ClosedTourAlgorithm
{
private:
	Printer _printer;
	Move _move;
public:
	STATUS findClosedTour(int& rowStart, int& colStart); //checking if the algorithm found closed tour
	ClosedTourAlgorithm(Printer& printer, Move& move);
};
