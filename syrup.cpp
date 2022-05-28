#include "syrup.h"

Syrup::Syrup(std::string name, std::string producer, std::string substance, int amount, int base_price_gr, bool receipt, std::string syrup_type) : Medicine(name, producer,  substance, amount, base_price_gr, receipt)
{
	this->syrup_type = syrup_type;
	this->med_type = "Syrup";
	calculate_price();
}


void Syrup::calculate_price() noexcept		// 23% tax
{
	this->calculated_price = round(base_price_gr * 1.23) / 100;
}



void Syrup::print(std::ostream& os) const
{
	os << "Type: Syrup\nName: " << name << "\nProducer: " << producer << "\nSubstance: " << substance <<
		"\nCapacity: " << amount << " ml\nPosition: " << position << "\nBase price:" << (double)base_price_gr / 100 <<"\nTaxed price: " << calculated_price << "\nCough Type:" << syrup_type << std::endl << std::endl;
}


std::string Syrup::get_cough_type() const noexcept
{
	return syrup_type;
}


void Syrup::set_caugh_type(std::string cough_type)
{
	this->syrup_type = cough_type;
}