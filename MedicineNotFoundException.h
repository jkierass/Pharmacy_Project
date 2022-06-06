#pragma once
#include <stdexcept>
#include <string>

class MedicineNotFoundException :
    public std::invalid_argument
{
public:
    MedicineNotFoundException(std::string msg);
    MedicineNotFoundException(int wrong_position);
};

