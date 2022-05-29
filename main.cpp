#include <iostream>
#include "pharmacist.h"
#include "random_objects_generator.h"
#include <vector>
#include "client.h"
#include "mdatabase.h"
#include "database_meds_reader.h"
#include "txt_file.h"

int main()
{
	std::string path_symptoms = "symptoms_patient.txt";
	std::string path = "Med_database_info.txt";
	std::string path_name = "name.txt";
	Database_meds_reader database_reader_file(path);
	MDatabase my_database;
	my_database = database_reader_file.read_database();
	//my_database.print_all_data();

	TxtFile file(path_name, path_symptoms);

	RandomObjectsGenerator objects(file.read_names(), file.read_symptoms());

	std::vector<Client> clients = objects.generate_clients_vector(10);

	int size = clients.size();
	std::cout << size;

	for (int i = 0; i < size; i++)
	{
		std::cout << clients[i].get_name() << std::endl;
		int symptoms = clients[i].get_symptoms().size();
		for (int j = 0; j < symptoms; j++)
		{
			std::cout << clients[i].get_symptoms()[j]<<std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}