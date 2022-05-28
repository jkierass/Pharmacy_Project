#include "NegativePriceTagException.h"

NegativePriceTagException::NegativePriceTagException(double wrong_price) : 
	std::invalid_argument("Negative value of the base price: " + std::to_string(wrong_price)) {}