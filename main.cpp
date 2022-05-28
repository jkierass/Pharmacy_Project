#include <iostream>
#include "pharmacist.h"
#include "random_objects_generator.h"
#include <vector>
#include "client.h"
#include "mdatabase.h"
#include "database_reader.h"

int main()
{
	std::string path = "C:\\Users\\jakub\\source\\repos\\Pharmacy_projekt\\Med_database_info.txt";
	Database_reader database_reader_file(path);
	MDatabase my_database;
	my_database = database_reader_file.read_database();
	my_database.print_all_data();

	//RandomObjectsGenerator objects;

	//std::vector<Client> clients = objects.generate_clients();

	//int size = clients.size();
	//std::cout << size;

	//for (int i = 0; i < size; i++)
	//{
	//	std::cout << clients[i].get_name() << std::endl;
	//	int symptoms = clients[i].get_symptoms().size();
	//	for (int j = 0; j < symptoms; j++)
	//	{
	//		std::cout << clients[i].get_symptoms()[j]<<std::endl;
	//	}
	//	std::cout << std::endl;
	//}

	return 0;
}