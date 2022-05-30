#pragma once
#include <vector>
#include "client.h"
#include <random>
#include "pharmacist.h"
#include "mdatabase.h"
#include "window.h"

class RandomObjectsGenerator
{
private:
	std::vector<std::string> names;
	std::vector<std::string> symptoms;
public:
	RandomObjectsGenerator(std::vector<std::string> names, std::vector<std::string> symptoms);

	void set_names(std::vector<std::string> names);
	void set_symptoms(std::vector<std::string> symptoms);

	std::vector<std::string> generate_symptoms();

	Client generate_client();

	std::vector<Client> generate_clients_vector(int max_number);

	std::vector<Pharmacist> generate_pharmacists(int max_number);

	std::vector<Window> generate_windows(int max_number);
};