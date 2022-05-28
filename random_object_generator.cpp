#include <vector>
#include "random_objects_generator.h"
#include <cstdlib>
#include <ctime>
#include "txt_file.h"

RandomObjectsGenerator::RandomObjectsGenerator() {};

std::vector<Client> RandomObjectsGenerator::generate_clients()
{
	std::string path_name = "name.txt";
	std::string name;
	std::vector<Client> clients;

	std::srand(time(0));

	int clients_number = rand() % 11;

	TxtFile file(path_name);

	file.openFile();

	while (clients_number != 0)
	{
		clients_number -= 1;

		int line = rand() % 600;

		for (int i = 1; i < line; i++)
			std::getline(file.file, name);

		file.file.clear();
		file.file.seekg(0);

		clients.push_back(file.create_client(name));
	}

	file.closeFile();

	return clients;
}