#include "pharmacist.h"
#include <random>

Pharmacist::Pharmacist()
{
	this->id = set_id();
}

int Pharmacist::get_id()
{
	return this->id;
}

int Pharmacist::set_id()
{
	std::random_device r;
	std::default_random_engine generator(r());
	std::uniform_int_distribution<int> id_gen(1000, 9999);
	 
	int number = id_gen(generator);

	return number;
}