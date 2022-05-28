#pragma once
#include <vector>
#include "client.h"
#include <random>

class RandomObjectsGenerator
{
public:
	RandomObjectsGenerator();

	std::vector<std::string> generate_symptoms();

	std::vector<Client> generate_clients();

};