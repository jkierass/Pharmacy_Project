#include "drops.h"

Drops::Drops(std::string name, std::string producer, std::string substance, int amount, int base_price_gr, bool receipt, std::string drops_type) : Medicine(name, producer, substance, amount, base_price_gr, receipt)
{
	this->drops_type = drops_type;
	this->med_type = "Drops";
	calculate_price();
}


void Drops::calculate_price()		// 12% tax
{
	this->calculated_price = round(base_price_gr * 1.12) / 100;
}


void Drops::print(std::ostream& os) const noexcept
{
	os << "Type: Drops\nName: " << name << "\nProducer: " << producer << "\nSubstance: " << substance <<
		"\nCapacity: " << amount << " ml\nPosition: " << position << "\nBase price:" << (double)base_price_gr / 100 << "\nTaxed price: " << calculated_price << "\nDrops type: " << drops_type << std::endl << std::endl;
}


std::string Drops::get_drops_type() const noexcept
{
	return drops_type;
}


void Drops::set_drops_type(std::string pills_type)
{
	this->drops_type = pills_type;
}