#pragma once
#include "mdatabase.h"
#include <vector>

class Pharmacist
{
private:
	int id;
	MDatabase pharmacist_knowledge;

public:
	Pharmacist(int id, MDatabase database);
	std::vector<Medicine> choose_medicines(std::vector<std::string>);
	int get_id();
	int set_id(int id);
};