#pragma once
#include "mdatabase.h"
#include <vector>

class Pharmacist
{
	int id;
	MDatabase pharmacist_knowledge;
public:
	Pharmacist(MDatabase pharmacist_knowledge);
	std::vector<Medicine> choose_medicines(std::vector<std::string>);
	int get_id();
	int set_id();
};

struct chosen_medicine
{
	std::string chosen_med_name;
	int num_of_symptoms;
};