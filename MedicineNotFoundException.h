#pragma once
#include <stdexcept>
#include <string>

class MedicineNotFoundException :
    public std::invalid_argument
{
public:
    MedicineNotFoundException(std::string wrong_name);
    MedicineNotFoundException(int wrong_position);
};

