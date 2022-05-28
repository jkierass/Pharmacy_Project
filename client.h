#pragma once
#include <iostream>
#include <vector>
#include "medicine.h"
#include <string>

class Client
{
private:
	std::vector<Medicine> medicines;
	std::string name;

public:
	Client();
	Client(std::string name);
	Client(std::string name, std::vector<Medicine> medicines);

	void set_name(std::string name);
	std::string get_name();

	std::vector<Medicine> get_medicines();

	void add_medicine(Medicine medicine);
	//void remove_medicine(Medicine medicine);
};