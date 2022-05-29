#pragma once
#include "pharmacist.h"
#include <random>


Pharmacist::Pharmacist(MDatabase pharmacist_knowledge)
{
	this->id = set_id();
	this->pharmacist_knowledge = pharmacist_knowledge;
}

int Pharmacist::get_id()
{
	return this->id;
}

int Pharmacist::set_id()
{
	std::random_device r;
	std::default_random_engine generator(r());
	std::uniform_int_distribution<int> id_gen(1000, 9999);
	 
	int number = id_gen(generator);

	return number;
}

std::vector<Medicine> Pharmacist::choose_medicines(std::vector<std::string> patient_symptoms)
{
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
	//				if (std::any_of(tmp_chosen_meds.begin(), tmp_chosen_meds.end(), [tmp_med_name](const std::string& a)->bool {return a == tmp_med_name; }))
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
	//tmp_Medicines.push_back(pharmacist_knowledge.find_by_name(medicine_ptr->get_name()));
}