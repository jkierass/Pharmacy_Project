#include <vector>
#include "random_objects_generator.h"
#include <cstdlib>
#include <ctime>
#include "txt_file.h"

RandomObjectsGenerator::RandomObjectsGenerator() {};

std::vector<std::string> RandomObjectsGenerator::generate_symptoms()
{
	std::string path_name = "symptoms_patient.txt";
	std::random_device r;
	std::default_random_engine generator(r());
	std::uniform_int_distribution<int> sym_gen(1, 3);
	int symptoms_num = sym_gen(generator);

	std::vector<std::string> symptoms;

	TxtFile name_file(path_name);
	name_file.openFile();
	int line_number = name_file.lines_num();

	for (int i = 0; i <= symptoms_num; i++)
	{
		std::string symptom;

		std::uniform_int_distribution<int> line_gen(1, line_number);
		int line = line_gen(generator);

		for (int i = 1; i < line+1; i++)
		{
			std::getline(name_file.get_file(), symptom);
		}

		name_file.get_file().clear();
		name_file.get_file().seekg(0);

		if (i != 0)
		{
			symptoms.push_back(symptom);
		}
	}
	name_file.closeFile();

	return symptoms;
}

std::vector<Client> RandomObjectsGenerator::generate_clients()
{
	std::string path_name = "name.txt";
	std::string name;
	std::vector<Client> clients;
	std::random_device r;
	std::default_random_engine generator(r());
	std::uniform_int_distribution<int> num_gen(1, 10);
	int clients_number = num_gen(generator);

	TxtFile name_file(path_name);
	name_file.openFile();
	int line_number = name_file.lines_num();

	for(int j = 0; j < clients_number+1; j++)
	{
		std::uniform_int_distribution<int> line_gen(1, line_number);

		int line = line_gen(generator);

		for (int i = 1; i < line+1; i++)
		{
			std::getline(name_file.get_file(), name);
		}

		name_file.get_file().clear();
		name_file.get_file().seekg(0);
		
		std::vector<std::string> symptons = generate_symptoms();

		if (j != 0)
		{
			clients.push_back(name_file.create_client(name, symptons));
		}
	}

	name_file.closeFile();

	return clients;
}