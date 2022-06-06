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
	std::vector<std::string> prescripted_medicines;
public:
	RandomObjectsGenerator(std::vector<std::string> names, std::vector<std::string> symptoms, std::vector<std::string> prescripted_medicines);

	void set_names(std::vector<std::string> names);
	void set_symptoms(std::vector<std::string> symptoms);
	void set_prescripted_medicines(std::vector<std::string> prescripted_medicines);

	std::string generate_p_medcicine();

	std::vector<std::string> generate_symptoms();

	Client generate_client();

	std::vector<Client> generate_clients_vector(int min_number, int max_number);
	std::vector<Client> generate_clients_vector(int number);

	std::vector<Pharmacist> generate_pharmacists(int min_number, int max_number);
	std::vector<Pharmacist> generate_pharmacists(int number);

	std::vector<Window> generate_windows(int min_number, int max_number);
	std::vector<Window> generate_windows(int number);

	int generate_number(int min_number, int max_number);
	int generate_NIP();
};