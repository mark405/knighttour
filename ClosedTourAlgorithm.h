#pragma once
#include "Printer.h"
#include "Move.h"

class ClosedTourAlgorithm
{
private:
	Printer *_printer;
	Move *_move;
public:
	bool findClosedTour(int& rowStart, int& colStart); //checking if the algorithm found closed tour
	ClosedTourAlgorithm(Printer *printer, Move *move);
};

