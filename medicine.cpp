#include "medicine.h"
#include <iomanip> 

Medicine::Medicine(std::string name, std::string producer, std::string substance, std::vector<std::string> symptoms, int amount, int base_price_gr, bool prescription)
{
	this->prescription = prescription;
	set_sympoms(symptoms);
	set_name(name);
	set_producer(producer);
	set_substance(substance);
	set_amount(amount);
	set_base_price_gr(base_price_gr);
	calculate_price();
}

//setters

void Medicine::set_name(std::string name)
{
	this->name = name;
}
void Medicine::set_producer(std::string producer)
{
	this->producer = producer;
}
void Medicine::set_substance(std::string substance)
{
	this->substance = substance;
}
void Medicine::set_amount(int amount)
{
	if (amount >= 0)
		this->amount = amount;
	else
		throw NegativeAmountException(amount);
}
void Medicine::set_base_price_gr(int base_price_gr)
{
	if (base_price_gr >= 0)
		this->base_price_gr = base_price_gr;
	else
		throw NegativePriceTagException(base_price_gr);
}
void Medicine::set_position(int position)
{
	if (position > 0)
		this->position = position;
	else
		throw NegativePositionException(position);
}

void Medicine::set_sympoms(std::vector<std::string> symptoms)
{
	this->symptoms = symptoms;
}
//getters

int Medicine::get_position() const
{
	return position;
}
std::string Medicine::get_name() const
{
	return name;
}
std::string Medicine::get_producer() const
{
	return producer;
}
std::string Medicine::get_substance() const
{
	return substance;
}
int Medicine::get_amount() const
{
	return amount;
}
int Medicine::get_base_price_gr() const
{
	return base_price_gr;
}
double Medicine::get_calculated_price() const
{
	return calculated_price;
}

std::string Medicine::get_med_type() const
{
	return med_type;
}

bool Medicine::get_prescription() const
{
	return prescription;
}

std::vector<std::string> Medicine::get_symptoms() const
{
	return symptoms;
}
// virtual methods
double Medicine::get_tax_value() const
{
	return this->tax_value;
}

void Medicine::print(std::ostream& os) const
{
	os << "Type: "<< med_type <<"\nName: " << name << "\nProducer: " << producer << "\nSubstance: " << substance << "\nPrescripted: " << prescription << "\nPosition : " << position << "\nSymptoms : ";
	for (int i = 0; i < symptoms.size(); i++)
	{
		os << symptoms[i] + " ";
	}
	os << "\nBase price: " << (double)base_price_gr / 100 << " zl\nTaxed price: " << calculated_price << " zl\n" << std::endl;
}

void Medicine::print_on_receipt(File_dial_out& mo) const noexcept
{
	int tax_value_to_pr = (tax_value - 1) * 100;
	std::string string_tax_value = std::to_string(tax_value_to_pr) + "%";
	
	
	mo << std::setfill(' ');
	mo << "|" << std::setw(20) << name << std::setw(16)
		<< producer << std::setw(8) << string_tax_value << std::setw(7) << std::to_string(base_price_gr/100) + ".00" << std::setw(8) << calculated_price << "|" << std::endl;
}

void Medicine::calculate_price()
{
	this->calculated_price = (double)base_price_gr / 100;
}

// output stream operator

std::ostream& operator<<(std::ostream& os, const Medicine& Med)
{
	Med.print(os);
	return os;
}

// virtual destructor

Medicine::~Medicine(){}