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

	//std::vector<std::string> patient_symptoms = { "after_stroke", "dry_cough", "wet_cough", "runny_nose", "sinus"};
	//std::vector<std::string> tmp_symptoms = patient_symptoms;
	//std::vector<chosen_medicine> tmp_chosen_meds;
	//std::vector<Medicine> medicines;
	//chosen_medicine tmp_med;
	//std::string tmp_med_name;

	//for (int i = 0; i < tmp_symptoms.size(); i++)
	//{
	//	for (const auto& medicine_ptr : pharmacist_knowledge.med_database)
	//	{
	//		for (const auto& med_symptom : medicine_ptr->get_symptoms())
	//		{
	//			if (tmp_symptoms[i] == med_symptom)
	//			{
	//				tmp_med_name = medicine_ptr->get_name();
	//				if (std::any_of(tmp_chosen_meds.begin(), tmp_chosen_meds.end(), [tmp_med_name](const chosen_medicine& a)->bool {return a.chosen_med_name == tmp_med_name; }))
	//				{
	//					for (int ite = 0; ite < tmp_chosen_meds.size(); ite++)
	//					{
	//						if (medicine_ptr->get_name() == tmp_chosen_meds[ite].chosen_med_name)
	//						{
	//							tmp_chosen_meds[ite].num_of_symptoms += 1;
	//						}
	//					}

	//				}
	//				else
	//				{
	//					tmp_med.chosen_med_name = medicine_ptr->get_name();
	//					tmp_med.num_of_symptoms = 1;
	//					tmp_chosen_meds.push_back(tmp_med);
	//				}
	//			}
	//		}
	//	}
	//}
	//std::cout << tmp_chosen_meds.size();
	//TxtFile file(path_name, path_symptoms);

	//RandomObjectsGenerator objects(file.read_names(), file.read_symptoms());

	//std::vector<Client> clients = objects.generate_clients_vector(10);

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