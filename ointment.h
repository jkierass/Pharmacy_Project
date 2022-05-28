#pragma once
#include "medicine.h"
class Ointment :
    public Medicine
{
    std::string ointment_type;
public:
    Ointment(std::string, std::string, std::string, int, int, std::string);
    void print(std::ostream&) const noexcept override;
    void calculate_price() noexcept override;
    std::string get_ointment_type() const noexcept;
    void set_ointment_type(std::string);
};

/*
Cuts and scrapes
Burns
Bites
Hemorrhoids
*/