#include "syrup.h"

Syrup::Syrup(std::string name, std::string producer, std::string substance, std::vector<std::string> symptoms, int amount, int base_price_gr, bool prescription, std::string syrup_type) : Medicine(name, producer,  substance, symptoms, amount, base_price_gr, prescription)
{
	this->syrup_type = syrup_type;
	this->med_type = "Syrup";
	this->tax_value = 1.08;
	calculate_price();
}


void Syrup::calculate_price() noexcept		// 23% tax
{
	this->calculated_price = round(base_price_gr * tax_value) / 100;
}



void Syrup::print(std::ostream& os) const noexcept
{
	os << "Type: Syrup\nName: " << name << "\nProducer: " << producer << "\nSubstance: " << substance <<
		"\nCapacity: " << amount << "ml\nPrescripted: " << prescription << "\nPosition: " << position << "\nSymptoms: ";
	for (int i = 0; i < symptoms.size(); i++)
	{
		os << symptoms[i] + " ";
	}
	os << "\nBase price: " << (double)base_price_gr / 100 << " zl\nTaxed price: " << calculated_price << " zl\nSyrup Type:" << syrup_type << std::endl << std::endl;
}


std::string Syrup::get_cough_type() const noexcept
{
	return syrup_type;
}


void Syrup::set_caugh_type(std::string cough_type)
{
	this->syrup_type = cough_type;
}