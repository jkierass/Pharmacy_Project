#pragma once
#include "pharmacist.h"
#include <iomanip>

std::vector<chosen_medicine> get_all_meds_for_symptoms(std::vector<std::string> vector_symptoms, MDatabase& database);

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

std::vector<Medicine> Pharmacist::choose_medicines(Client& my_client, MDatabase& pharmacist_knowledge)
{
	std::vector<std::string> tmp_symptoms = my_client.symptoms;
	std::vector<chosen_medicine> tmp_chosen_meds;
	std::vector<Medicine> medicines;
	chosen_medicine tmp_med;
	std::string tmp_med_name;
	std::string tmp_symptom_to_remove;

	while (tmp_symptoms.size() > 0)
	{
		tmp_chosen_meds = get_all_meds_for_symptoms(tmp_symptoms, pharmacist_knowledge);
		std::sort(tmp_chosen_meds.begin(), tmp_chosen_meds.end(), [](const chosen_medicine& a, const chosen_medicine& b)->bool {return a.num_of_symptoms < b.num_of_symptoms; });
		medicines.push_back(pharmacist_knowledge.find_by_name(tmp_chosen_meds.back().chosen_med_name));
		for (int iterat = 0; iterat < tmp_chosen_meds.back().num_of_symptoms; iterat++)
		{
			tmp_symptom_to_remove = tmp_chosen_meds.back().chosen_med_symptoms[iterat];
			for (int iterator1 = 0; iterator1 < tmp_symptoms.size(); iterator1++)
			{
				if (tmp_symptoms[iterator1] == tmp_symptom_to_remove)
				{
					tmp_symptoms.erase(tmp_symptoms.begin() + iterator1);
				}
			}
		}
		tmp_chosen_meds.clear();
	}
	for (int iterator = 0; iterator < medicines.size(); iterator++)
	{
		my_client.cart.push_back(medicines[iterator]);
	}
	my_client.cart.push_back(pharmacist_knowledge.find_by_name(my_client.prescription_medicine));
	return medicines;
}

std::vector<Medicine> Pharmacist::choose_cheaper_replacements_and_replace(Client& my_client, MDatabase& pharmacist_knowledge, Medicine med_to_replace)
{
	std::string tmp_substance = med_to_replace.get_substance();
	bool is_prescripted = med_to_replace.get_prescription();
	std::string tmp_med_to_replace_name = med_to_replace.get_name();
	std::vector<std::string> tmp_symptoms_to_replace;
	std::vector<Medicine> replacement_medicines;
	std::vector<Medicine> added_to_cart_medicines;
	std::vector<chosen_medicine> tmp_chosen_meds;
	chosen_medicine one_of_chosen;
	std::string the_one_chosen_med_name;
	std::string tmp_symptom_to_remove;
	bool replacement_found;
	double tmp_combined_price = 0.0;
	if (is_prescripted = false)
	{
		for (const auto& client_symptom : my_client.get_symptoms())
		{
			for (const auto& med_symptom : med_to_replace.get_symptoms())
			{
				if (client_symptom == med_symptom)
				{
					tmp_symptoms_to_replace.push_back(client_symptom);
				}
			}
		}
		while (tmp_symptoms_to_replace.size() > 0)
		{
			tmp_chosen_meds = get_all_meds_for_symptoms(tmp_symptoms_to_replace, pharmacist_knowledge);
			if (tmp_chosen_meds.size() > 1)
			{
				std::sort(tmp_chosen_meds.begin(), tmp_chosen_meds.end(), [](const chosen_medicine& a, const chosen_medicine& b)->bool {return a.taxed_price < b.taxed_price; });
				do {
					the_one_chosen_med_name = tmp_chosen_meds[0].chosen_med_name;
					if (!(the_one_chosen_med_name == med_to_replace.get_name()) && tmp_chosen_meds[0].prescripted == false)
					{
						replacement_medicines.push_back(pharmacist_knowledge.find_by_name(the_one_chosen_med_name));
						replacement_found = true;
						for (int iterator1 = 0; iterator1 < tmp_symptoms_to_replace.size(); iterator1++)
						{
							if (tmp_symptoms_to_replace[iterator1] == tmp_symptom_to_remove)
							{
								tmp_symptoms_to_replace.erase(tmp_symptoms_to_replace.begin() + iterator1);
							}
						}
					}
					else
					{
						tmp_chosen_meds.erase(tmp_chosen_meds.begin());
						replacement_found = false;
						if (tmp_chosen_meds.size() == 0)
						{
							throw MedicineNotFoundException("There is none replacement available");
						}
					}
				} while (replacement_found = false);
				tmp_chosen_meds.clear();
			}
			else
			{
				throw MedicineNotFoundException("There is none replacement available");
			}
		}
		for (int i = 0; i < replacement_medicines.size(); i++)
		{
			tmp_combined_price += replacement_medicines[i].get_calculated_price();
		}
		if (tmp_combined_price < med_to_replace.get_calculated_price())
		{
			my_client.cart.erase(std::remove_if(my_client.cart.begin(), my_client.cart.end(),
				[tmp_med_to_replace_name](const Medicine& A)->bool {return A.get_name() == tmp_med_to_replace_name; }));
			for (int iterator = 0; iterator < replacement_medicines.size(); iterator++)
			{
				my_client.cart.push_back(replacement_medicines[iterator]);
				added_to_cart_medicines.push_back(replacement_medicines[iterator]);
			}
			return added_to_cart_medicines;
		}
		else
		{
			throw MedicineNotFoundException("There is no cheaper alternative");
		}
	}
	else
	{
		for (const auto& medicine_ptrr : pharmacist_knowledge.med_database)
		{
			if (medicine_ptrr->get_substance() == tmp_substance)
			{
				one_of_chosen.chosen_med_name = medicine_ptrr->get_name();
				one_of_chosen.taxed_price = medicine_ptrr->get_calculated_price();
				tmp_chosen_meds.push_back(one_of_chosen);
			}
		}
		std::sort(tmp_chosen_meds.begin(), tmp_chosen_meds.end(), [](const chosen_medicine& a, const chosen_medicine& b)->bool {return a.taxed_price < b.taxed_price; });
		the_one_chosen_med_name = tmp_chosen_meds[0].chosen_med_name;
		if (!(the_one_chosen_med_name == med_to_replace.get_name()))
		{
			my_client.cart.erase(std::remove_if(my_client.cart.begin(), my_client.cart.end(),
				[tmp_med_to_replace_name](const Medicine& A)->bool {return A.get_name() == tmp_med_to_replace_name; }));
			my_client.cart.push_back(pharmacist_knowledge.find_by_name(the_one_chosen_med_name));
			added_to_cart_medicines.push_back(pharmacist_knowledge.find_by_name(the_one_chosen_med_name));
			return added_to_cart_medicines;
		}
		else
		{
			throw MedicineNotFoundException("There is no cheaper alternative");
		}
	}
}

void Pharmacist::print_receipt(Client my_client)
{
	if (my_client.cart.size() > 0)
	{
		std::cout.unsetf(std::ios::right);
		double total_price = 0.0;
		int total_price_base = 0;
		double total_tax_value = 0.0;
		std::cout.setf(std::ios::left);
		std::cout.fill('_');
		std::cout << "_" << std::setw(60) << "_" << std::endl;
		std::cout.fill(' ');
		std::cout << std::setw(60) << "|" << "|" << std::endl;
		std::cout << std::setw(60) << "| Pharmacy 'Pharmax' limited liability company" <<  "|" << std::endl;
		std::cout << std::setw(60) << "| Siedmiogrodzka street 13c" << "|" << std::endl;
		std::cout << std::setw(60) << "| 01-204 Warsaw, Poland" << "|" << std::endl;
		std::cout << std::setw(60) << "| NIP: 0123456609" << "|" << std::endl;
		std::cout << std::setw(60) << "| Phone: +48 321 243 967" << "|" << std::endl;
		std::cout << std::setw(60) << "|" << "|" << std::endl;
		std::cout << std::setw(60) << "|" << "|" << std::endl;
		std::cout << std::setw(20) << "|" << "FISCAL RECEIPT" << std::setiosflags(std::ios::right) << std::setw(27) << "|" << std::endl;
		std::cout.setf(std::ios::left);
		std::cout << "|" << std::setw(60) << "|" << std::endl;
		std::cout << "|" << std::setw(60) << "|" << std::endl;
		std::cout << "|" << std::setw(60) << "|" << std::endl;
		std::cout << "|" << std::setw(20) << "name:" << std::setw(16)
			<< "producer:" << std::setw(8) << "tax:" << std::setw(7) << "base:" << std::setw(8) << "total:" << "|" << std::endl;
		for (const auto& medicine_in_cart : my_client.cart)
		{
			medicine_in_cart.print_on_receipt(std::cout);
			total_price_base += medicine_in_cart.get_base_price_gr()/100;
			total_price += medicine_in_cart.get_calculated_price();
		}
		total_tax_value = total_price - total_price_base;
		std::cout.fill('_');
		std::cout << "_" << std::setw(60) << "_" << std::endl;
		std::cout.fill(' ');
		std::cout << "|" << std::setw(60) << "|" << std::endl;
		std::cout << "|" << std::setw(30) << "TOTAL BASE: " << std::setw(29) << std::to_string(total_price_base)+".00" << "|" << std::endl;
		std::cout << "|" << std::setw(30) << "TOTAL TAX: " << std::setw(29) << total_tax_value << "|" << std::endl;
		std::cout << "|" << std::setw(30) << "TOTAL: " << std::setw(29) << total_price  << "|" << std::endl;
		std::cout << "|" << std::setw(60) << "|" << std::endl;
		std::cout.fill('_');
		std::cout << "_" << std::setw(60) << "_" << std::endl;
		std::cout.fill(' ');
	}
	else
	{
		throw MedicineNotFoundException("Empty cart - cannot print receipt");
	}
}






std::ostream& operator<<(std::ostream& os, const Pharmacist& pharmacist)
{
	os << "Pharmacist id " << pharmacist.id << " supports client" << std::endl;
	return os;
}

std::vector<chosen_medicine> get_all_meds_for_symptoms(std::vector<std::string> vector_symptoms, MDatabase& database)
{
	std::vector<std::string> tmp_symptoms = vector_symptoms;
	std::vector<chosen_medicine> chosen_meds;
	chosen_medicine tmp_med;
	std::string tmp_med_name;
	for (int i = 0; i < tmp_symptoms.size(); i++)
	{
		for (const auto& medicine_ptr : database.med_database)
		{
			for (const auto& med_symptom : medicine_ptr->get_symptoms())
			{
				if (tmp_symptoms[i] == med_symptom)
				{
					tmp_med_name = medicine_ptr->get_name();
					if (std::any_of(chosen_meds.begin(), chosen_meds.end(), [tmp_med_name](const chosen_medicine& a)->bool {return a.chosen_med_name == tmp_med_name; }))
					{
						for (int ite = 0; ite < chosen_meds.size(); ite++)
						{
							if (medicine_ptr->get_name() == chosen_meds[ite].chosen_med_name)
							{
								chosen_meds[ite].num_of_symptoms++;
								chosen_meds[ite].chosen_med_symptoms.push_back(med_symptom);
							}
						}
					}
					else
					{
						tmp_med.chosen_med_name = medicine_ptr->get_name();
						tmp_med.prescripted = medicine_ptr->get_prescription();
						tmp_med.chosen_med_symptoms.push_back(med_symptom);
						chosen_meds.push_back(tmp_med);
						tmp_med.chosen_med_symptoms.clear();
						tmp_med.taxed_price = medicine_ptr->get_calculated_price();
					}
				}
			}
		}
	}
	return chosen_meds;
}
