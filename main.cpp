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
	MDatabase pharmacist_knowledge;
	pharmacist_knowledge = database_reader_file.read_database();
	
	return 0;
}