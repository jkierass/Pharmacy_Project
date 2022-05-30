#pragma once
#include "pharmacist.h"

Pharmacist::Pharmacist() {};

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
								tmp_chosen_meds[ite].num_of_symptoms++;
								tmp_chosen_meds[ite].chosen_med_symptoms.push_back(med_symptom);
							}
						}

					}
					else
					{
						tmp_med.chosen_med_name = medicine_ptr->get_name();
						tmp_med.num_of_symptoms = 1;
						tmp_med.chosen_med_symptoms.push_back(med_symptom);
						tmp_chosen_meds.push_back(tmp_med);
						tmp_med.chosen_med_symptoms.clear();
					}
				}
			}
		}
	}
	int iterator2 = 0;
	while (tmp_symptoms.size() > 0)
	{
	std::sort(tmp_chosen_meds.begin(), tmp_chosen_meds.end(), [](const chosen_medicine& a, const chosen_medicine& b)->bool {return a.num_of_symptoms < b.num_of_symptoms; });
	//std::reverse(tmp_chosen_meds.begin(), tmp_chosen_meds.end());
	medicines.push_back(pharmacist_knowledge.find_by_name(tmp_chosen_meds[0].chosen_med_name)); // ZABEZPIECZYÆ PRZED DUBLOWANIEM LEKOW NA TE SAME SYMPTOMY
	std::string tmp_symptom_to_remove;
		for (int iterat = 0; iterat < tmp_chosen_meds[iterator2].num_of_symptoms; iterat++)
		{
			tmp_symptom_to_remove = tmp_chosen_meds[iterator2].chosen_med_symptoms[iterat];
			for (int iterator1 = 0; iterator1 < tmp_symptoms.size(); iterator1++)
			{
				if (tmp_symptoms[iterator1] == tmp_symptom_to_remove)
				{
					tmp_symptoms.erase(tmp_symptoms.begin()+iterator1);
				}
			}
		}
		iterator2++;
		tmp_chosen_meds.erase(tmp_chosen_meds.begin());
	}
	return medicines;
}