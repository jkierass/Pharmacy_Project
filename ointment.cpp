#include "ointment.h"

Ointment::Ointment(std::string name, std::string producer, std::string substance, int amount, int base_price_gr, std::string ointment_type) : Medicine(name, producer, substance, amount, base_price_gr)
{
	this->ointment_type = ointment_type;
	this->med_type = "Ointment";
	calculate_price();
}


void Ointment::calculate_price() noexcept		// 15% tax
{
	this->calculated_price = round(base_price_gr * 1.15) / 100;
}


void Ointment::print(std::ostream& os) const noexcept
{
	os << "Type: Ointment\nName: " << name << "\nProducer: " << producer << "\nSubstance: " << substance <<
		"\nCapacity: " << amount << " ml\nPosition: " << position << "\nBase price:" << (double)base_price_gr / 100 << "\nTaxed price: " << calculated_price << "\nType of symptom: " << ointment_type << std::endl << std::endl;
}


std::string Ointment::get_ointment_type() const noexcept
{
	return ointment_type;
}


void Ointment::set_ointment_type(std::string ointment_type) 
{
	this->ointment_type = ointment_type;
}