#pragma once
#include "pharmacist.h"

Pharmacist::Pharmacist(int id)
{
	set_id(id);
}

int Pharmacist::get_id()
{
	return this->id;
}

void Pharmacist::set_id(int id)
{
	this->id = id;
}

std::vector<Medicine> Pharmacist::choose_medicines(std::vector<std::string> patient_symptoms, MDatabase& pharmacist_knowledge)
{
	std::vector<std::string> tmp_symptoms = patient_symptoms;
	std::vector<chosen_medicine> tmp_chosen_meds;
	std::vector<Medicine> medicines;
	chosen_medicine tmp_med;
	std::string tmp_med_name;

	for (int i = 0; i < tmp_symptoms.size(); i++)
	{
		for (const auto& medicine_ptr : pharmacist_knowledge.med_database)
		{
			for (const auto& med_symptom : medicine_ptr->get_symptoms())
			{
				if (tmp_symptoms[i] == med_symptom)
				{
					tmp_med_name = medicine_ptr->get_name();
					if (std::any_of(tmp_chosen_meds.begin(), tmp_chosen_meds.end(), [tmp_med_name](const chosen_medicine& a)->bool {return a.chosen_med_name == tmp_med_name; }))
					{
						for (int ite = 0; ite < tmp_chosen_meds.size(); ite++)
						{
							if (medicine_ptr->get_name() == tmp_chosen_meds[ite].chosen_med_name)
							{
								tmp_chosen_meds[ite].num_of_symptoms += 1;
							}
						}

					}
					else
					{
						tmp_med.chosen_med_name = medicine_ptr->get_name();
						tmp_med.num_of_symptoms = 1;
						tmp_chosen_meds.push_back(tmp_med);
					}
				}
			}
		}
	}
	return medicines;
	//tmp_Medicines.push_back(pharmacist_knowledge.find_by_name(medicine_ptr->get_name()));
}