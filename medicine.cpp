#include "medicine.h"

Medicine::Medicine(std::string name, std::string producer, std::string substance, int amount, int base_price_gr, bool receipt)
{
	this->receipt = receipt;
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

// virtual methods

void Medicine::print(std::ostream& os) const
{
	os << "Type: "<< med_type <<"\n Name: " << name << "\nProducer: " << producer << "\nSubstance: " << substance <<
		"\nCapacity: " << amount << " ml\nPosition: " << position << "\nBase price:" << (double)base_price_gr / 100 << "\nTaxed price: " << calculated_price << std::endl;
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