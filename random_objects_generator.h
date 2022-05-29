#pragma once
#include <vector>
#include "client.h"
#include <random>
#include "pharmacist.h"

class RandomObjectsGenerator
{
private:
	std::list<std::string> names;
	std::list<std::string> symptoms;
public:
	RandomObjectsGenerator(std::list<std::string> names, std::list<std::string> symptoms);

	std::vector<std::string> generate_symptoms();

	std::vector<Client> generate_queue();

	std::vector<Pharmacist> generate_pharmacists();
	void set_names(std::list<std::string> names);
	void set_symptoms(std::list<std::string> symptoms);
};