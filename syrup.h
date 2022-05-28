#pragma once
#include "medicine.h"
class Syrup :
    public Medicine
{
    std::string cough_type;
public:
    Syrup(std::string, std::string, std::string, int, int, std::string);
    void print(std::ostream&) const override;
    void calculate_price() noexcept override;
    std::string get_cough_type() const noexcept;
    void set_caugh_type(std::string);
};

/*
* dry
* wet
*/
