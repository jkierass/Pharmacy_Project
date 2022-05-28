#include "pills.h"

Pills::Pills(std::string name, std::string producer, std::string substance, int amount, int base_price_gr, bool receipt, std::string pills_type) : Medicine(name, producer, substance, amount, base_price_gr, receipt)
{
	this->pills_type = pills_type;
	this->med_type = "Pills";
	calculate_price();
}


void Pills::calculate_price() noexcept		// 8% tax
{
	this->calculated_price = round(base_price_gr * 1.08) / 100;
}


void Pills::print(std::ostream& os) const noexcept
{
	os << "Type: Pills\nName: " << name << "\nProducer: " << producer << "\nSubstance: " << substance <<
		"\nAmount: " << amount << " tablets\nPosition: " << position << "\nBase price:" << (double)base_price_gr / 100 << "\nTaxed price: " << calculated_price << "\nType of dosing: "<< pills_type << std::endl << std::endl;
}


std::string Pills::get_pills_type() const noexcept
{
	return pills_type;
}


void Pills::set_pills_type(std::string pills_type)
{
	this->pills_type = pills_type;
}