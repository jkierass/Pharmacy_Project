#pragma once
#include "mdatabase.h"
#include <vector>
#include <algorithm>


class Pharmacist
{
	int id;

public:
	Pharmacist(int id);
	std::vector<Medicine> choose_medicines(std::vector<std::string>, MDatabase&);
	int get_id();
	void set_id(int id);
};

struct chosen_medicine
{
	std::string chosen_med_name;
	int num_of_symptoms;
	std::vector<std::string> chosen_med_symptoms;
};