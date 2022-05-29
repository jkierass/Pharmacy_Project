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
	std::vector<std::string> tmp_symptoms = patient_symptoms;
	std::vector<chosen_medicine> tmp_chosen_meds;
	std::vector<Medicine> medicines;
	chosen_medicine tmp_med;
	std::string tmp_med_name;


	return 0;
}