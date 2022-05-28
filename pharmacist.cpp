#include "pharmacist.h"
#include <cstdlib>
#include <ctime>

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
std::srand(time(NULL));

int number = (rand() % 9000) + 1000;

return number;
}