#pragma once
#include <vector>
#include "client.h"

class RandomObjectsGenerator
{
public:
	RandomObjectsGenerator();

	std::vector<Client> generate_clients();

};