#pragma once
#include <stdexcept>
#include <string>

class NegativePriceTagException :
    public std::invalid_argument
{
public:
    NegativePriceTagException(double wrong_price);
};

