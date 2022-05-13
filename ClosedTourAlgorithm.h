#pragma once
#include "Printer.h"
#include "Move.h"
#include "TimerChecker.h"

enum class STATUS
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
	ClosedTourAlgorithm(const Printer& printer, const Move& move):
	_printer(printer), _move(move) {}
};
