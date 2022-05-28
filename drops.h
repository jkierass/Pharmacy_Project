#pragma once
#include "medicine.h"
class Drops :
    public Medicine
{
    std::string drops_type;
public:
    Drops(std::string, std::string, std::string, std::vector<std::string>, int, int, bool, std::string);
    void print(std::ostream&) const noexcept override;
    void calculate_price() override;
    std::string get_drops_type() const noexcept;
    void set_drops_type(std::string);
};

/*
Artificial tears.
Allergy drops.
Anti-redness drops.
*/