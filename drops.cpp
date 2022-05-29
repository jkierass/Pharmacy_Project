#include "drops.h"

Drops::Drops(std::string name, std::string producer, std::string substance, std::vector<std::string> symptoms, int amount, int base_price_gr, bool prescription, std::string drops_type) : Medicine(name, producer, substance, symptoms, amount, base_price_gr, prescription)
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
	os << "Type: Drops\nName: " << name << "\nProducer: " << producer << "\nSubstance: " << substance << "\nPrescripted: " << prescription << "\nPosition : " << position << "\nSymptoms : ";
		for (int i = 0; i < symptoms.size(); i++)
		{
			os << symptoms[i] + " ";
		}
	os << "\nBase price: " << (double)base_price_gr / 100 << " zl\nTaxed price: " << calculated_price << " zl\nDrops type: " << drops_type << std::endl << std::endl;
}


std::string Drops::get_drops_type() const noexcept
{
	return drops_type;
}


void Drops::set_drops_type(std::string pills_type)
{
	this->drops_type = pills_type;
}