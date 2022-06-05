#include <vector>
#include "random_objects_generator.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "txt_file.h"

RandomObjectsGenerator::RandomObjectsGenerator(std::vector<std::string> names, std::vector<std::string> symptoms, std::vector<std::string> prescripted_medicines)
{
	set_names(names);
	set_symptoms(symptoms);
	set_prescripted_medicines(prescripted_medicines);
}

void RandomObjectsGenerator::set_names(std::vector<std::string> names)
{
	this->names = names;
}

void RandomObjectsGenerator::set_symptoms(std::vector<std::string> symptoms)
{
	this->symptoms = symptoms;
}

void RandomObjectsGenerator::set_prescripted_medicines(std::vector<std::string> prescripted_medicines)
{
	this->prescripted_medicines = prescripted_medicines;
}

std::string RandomObjectsGenerator::generate_p_medcicine()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	int med_num = prescripted_medicines.size();
	std::uniform_int_distribution<int> num_gen_med(0, med_num - 1);
	int num = num_gen_med(generator);
	std::string med = prescripted_medicines[num];
	return med;
}

std::vector<std::string> RandomObjectsGenerator::generate_symptoms()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> sym_gen(1, 3);
	int sym_num = sym_gen(generator);

	std::vector<std::string> generated_symptoms;
	int symptoms_num = symptoms.size();

	for (int i = 1; i <= sym_num; i++)
	{

		std::uniform_int_distribution<int> num_gen(0, symptoms_num-1);

		int num = num_gen(generator);
		if (std::find(generated_symptoms.begin(), generated_symptoms.end(), symptoms[num]) == generated_symptoms.end())
		{
			generated_symptoms.push_back(symptoms[num]);
		}
		else
		{
			i = i - 1;
		}
	}
	return generated_symptoms;
}

Client RandomObjectsGenerator::generate_client()
{
	int names_size = names.size();
	std::vector<std::string> client_symptoms = generate_symptoms();
	std::string med = generate_p_medcicine();

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> num_name(0, names_size-1);
	int name_number= num_name(generator);

	std::string name = names[name_number];

	Client client(name, client_symptoms, med);

	return client;
}

std::vector<Client> RandomObjectsGenerator::generate_clients_vector(int min_number, int max_number)
{
	std::vector<Client> clients;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> num_client(min_number, max_number);
	int clients_number = num_client(generator);
	
	for (int i = 1; i <= clients_number; i++)
	{
		clients.push_back(generate_client());
	}

	return clients;
}

std::vector<Client> RandomObjectsGenerator::generate_clients_vector(int number)
{
	std::vector<Client> clients;

	int clients_number = number;

	for (int i = 1; i <= clients_number; i++)
	{
		clients.push_back(generate_client());
	}

	return clients;
}

std::vector<Pharmacist> RandomObjectsGenerator::generate_pharmacists(int min_num, int max_number)
{
	std::vector<Pharmacist> pharmacists;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> num_pharmacist(min_num, max_number);
	int pharmacists_number = num_pharmacist(generator);

	for (int i = 1; i <= pharmacists_number; i++)
	{
		std::uniform_int_distribution<int> id_gen(1000, 9999);

		int number = id_gen(generator);
		Pharmacist pharmacist(number);

		pharmacists.push_back(pharmacist);
	}
	return pharmacists;
}

std::vector<Pharmacist> RandomObjectsGenerator::generate_pharmacists(int number)
{
	std::vector<Pharmacist> pharmacists;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	int pharmacists_number = number;

	for (int i = 1; i <= pharmacists_number; i++)
	{
		std::uniform_int_distribution<int> id_gen(1000, 9999);

		int number = id_gen(generator);
		Pharmacist pharmacist(number);

		pharmacists.push_back(pharmacist);
	}
	return pharmacists;
}

std::vector<Window> RandomObjectsGenerator::generate_windows(int min_number, int max_number)
{
	std::vector<Window> windows;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> num_windows(1, max_number);
	int windows_number = num_windows(generator);

	Window window;

	for (int i = 1; i <= windows_number; i++)
	{
		windows.push_back(window);
	}
	return windows;
}

std::vector<Window> RandomObjectsGenerator::generate_windows(int number)
{
	std::vector<Window> windows;

	int windows_number = number;

	Window window;

	for (int i = 1; i <= windows_number; i++)
	{
		windows.push_back(window);
	}
	return windows;
}

int RandomObjectsGenerator::generate_number(int min_number, int max_number)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> num(min_number, max_number);
	int number = num(generator);

	return number;
}