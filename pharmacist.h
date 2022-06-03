#pragma once
#include "client.h"
#include "mdatabase.h"
#include <vector>
#include <algorithm>


class Pharmacist
{
	int id;

public:
	Pharmacist();
	Pharmacist(int id);
	std::vector<Medicine> choose_medicines(Client, MDatabase&);
	Medicine choose_cheaper_replacement(Client, MDatabase&, Medicine);
	int get_id();
	void set_id(int id);
};

struct chosen_medicine
{
	std::string chosen_med_name;
	int num_of_symptoms;
	std::vector<std::string> chosen_med_symptoms;
};