#pragma once
#include "client.h"
#include "mdatabase.h"
#include <vector>
#include <algorithm>

struct chosen_medicine;

class Pharmacist
{
	int id = 0;
public:
	Pharmacist();
	Pharmacist(int id);
	std::vector<Medicine> choose_medicines(Client&, MDatabase&);
	std::vector<Medicine> choose_cheaper_replacements_and_replace(Client&, MDatabase&, Medicine);
	void print_receipt(Client);
	void print_invoide(Client);
	int get_id();
	void set_id(int id);
	friend std::ostream& operator<<(std::ostream& os, const Pharmacist& pharmacist);
};

std::ostream& operator<<(std::ostream& os, const Pharmacist& pharmacist);

struct chosen_medicine
{
	std::string chosen_med_name;
	int num_of_symptoms = 0;
	std::vector<std::string> chosen_med_symptoms;
	double taxed_price = 0.0;
};