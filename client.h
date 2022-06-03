#pragma once
#include <iostream>
#include <vector>
#include "medicine.h"
#include <string>

class Client
{
private:
	std::string name;
	std::vector<std::string> symptoms;
	int logic_status = 1;

public:
	Client();
	Client(std::string name, std::vector<std::string> symptoms);

	void set_name(std::string name);
	std::string get_name();

	std::vector<std::string> get_symptoms();
};