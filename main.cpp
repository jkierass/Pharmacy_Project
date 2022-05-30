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
	//my_database.print_all_data();

	std::vector<std::string> patient_symptoms = { "after_stroke", "dry_cough", "wet_cough"};
	std::vector<Medicine> medicines;
	Pharmacist John(121);
	medicines = John.choose_medicines(patient_symptoms, pharmacist_knowledge);
	for(int i = 0; i<medicines.size(); i++)
	{
		std::cout << medicines[i] << std::endl;
	}
	return 0;
}