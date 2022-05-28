#pragma once
#include <stdexcept>
#include <string>

class NegativePositionException :
    public std::invalid_argument
{
public:
    NegativePositionException(int wrong_position);
};

