#pragma once
#include <stdexcept>
#include <string>

class NegativeAmountException :
    public std::invalid_argument
{
public:
    NegativeAmountException(int wrong_amount);
};

