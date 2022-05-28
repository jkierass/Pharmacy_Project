#include "NegativePositionException.h"

NegativePositionException::NegativePositionException(int wrong_position) :
	std::invalid_argument("Negative position: " + std::to_string(wrong_position)) {}