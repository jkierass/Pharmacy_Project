#include "NegativeAmountException.h"

NegativeAmountException::NegativeAmountException(int wrong_amount) :
	std::invalid_argument("Negative value of amount: " + std::to_string(wrong_amount)) {}