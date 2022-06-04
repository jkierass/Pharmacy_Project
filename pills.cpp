#include "pills.h"

Pills::Pills(std::string name, std::string producer, std::string substance, std::vector<std::string> symptoms, int amount, int base_price_gr, bool prescription, std::string pills_type) : Medicine(name, producer, substance, symptoms, amount, base_price_gr, prescription)
{
	this->pills_type = pills_type;
	this->med_type = "Pills";
	this->tax_value = 1.23;
	calculate_price();
}


void Pills::calculate_price() noexcept		// 8% tax
{
	this->calculated_price = round(base_price_gr * tax_value) / 100;
}


void Pills::print(std::ostream& os) const noexcept
{
	os << "Type: Pills\nName: " << name << "\nProducer: " << producer << "\nSubstance: " << substance << "\nPrescripted: " << prescription << "\nPosition : " << position << "\nSymptoms : ";
	for (int i = 0; i < symptoms.size(); i++)
	{
		os << symptoms[i] + " ";
	}
	os << "\nBase price: " << (double)base_price_gr / 100 << " zl\nTaxed price: " << calculated_price << " zl\nTaxed price: " << calculated_price << "\nType of dosing: "<< pills_type << std::endl << std::endl;
}


std::string Pills::get_pills_type() const noexcept
{
	return pills_type;
}


void Pills::set_pills_type(std::string pills_type)
{
	this->pills_type = pills_type;
}