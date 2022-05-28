#pragma once
#include "medicine.h"
class Pills :
    public Medicine
{
    std::string pills_type;
public:
    Pills(std::string, std::string, std::string, int, int, bool, std::string);
    void print(std::ostream&) const noexcept override;
    void calculate_price() noexcept override;
    std::string get_pills_type() const noexcept;
    void set_pills_type(std::string);
};

/*
* Chewable tablets
* Orally disintegrating tablets
* Sublingual tablets
* Effervescent tablets
*/