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
	std::vector<std::string> tmp_symptoms = patient_symptoms;
	std::vector<Medicine> tmp_Medicines;
	for (std::vector<std::string>::iterator it = tmp_symptoms.begin(); it != tmp_symptoms.end(); it++)
	{
	
		for (const auto& medicine_ptr : pharmacist_knowledge.med_database)
		{
			for (const auto& med_symptom : medicine_ptr->get_symptoms())
			{
				if (*it._Unwrapped() == med_symptom)
				{
					tmp_Medicines.push_back(pharmacist_knowledge.find_by_name(medicine_ptr->get_name()));
					tmp_symptoms.erase(it);
				}
			}
		}
	}
}