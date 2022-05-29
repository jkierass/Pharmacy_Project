#include <vector>
#include "random_objects_generator.h"
#include <cstdlib>
#include <ctime>
#include "txt_file.h"

RandomObjectsGenerator::RandomObjectsGenerator(std::vector<std::string> names, std::vector<std::string> symptoms)
{
	set_names(names);
	set_symptoms(symptoms);
}

void RandomObjectsGenerator::set_names(std::vector<std::string> names)
{
	this->names = names;
}

void RandomObjectsGenerator::set_symptoms(std::vector<std::string> symptoms)
{
	this->symptoms = symptoms;
}

std::vector<std::string> RandomObjectsGenerator::generate_symptoms()
{
	std::random_device r;
	std::default_random_engine generator(r());
	std::uniform_int_distribution<int> sym_gen(1, 3);
	int sym_num = sym_gen(generator);

	std::vector<std::string> generated_symptoms;
	int symptoms_num = symptoms.size();

	for (int i = 1; i <= sym_num; i++)
	{

		std::uniform_int_distribution<int> num_gen(0, symptoms_num-1);

		int num = num_gen(generator);

		generated_symptoms.push_back(symptoms[num]);
	}
	return generated_symptoms;
}

Client RandomObjectsGenerator::generate_client()
{
	int names_size = names.size();
	std::vector<std::string> client_symptoms = generate_symptoms();

	std::random_device r;
	std::default_random_engine generator(r());
	std::uniform_int_distribution<int> num_name(0, names_size-1);
	int name_number= num_name(generator);

	std::string name = names[name_number];

	Client client(name, client_symptoms);

	return client;
}

std::vector<Client> RandomObjectsGenerator::generate_clients_vector(int max_number)
{
	std::vector<Client> clients;

	std::random_device r;
	std::default_random_engine generator(r());
	std::uniform_int_distribution<int> num_client(0, max_number);
	int clients_number = num_client(generator);
	
	for (int i = 1; i <= clients_number; i++)
	{
		clients.push_back(generate_client());
	}

	return clients;
}

std::vector<Pharmacist> RandomObjectsGenerator::generate_pharmacists()
{
	std::vector<Pharmacist> pharmacists;
	return pharmacists;
}