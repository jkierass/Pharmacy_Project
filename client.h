#pragma once
#include <iostream>
#include <vector>
#include "medicine.h"
#include <string>

class Client
{
private:
	std::string name;
	std::string action;
	int logic_status = 1;
	std::vector<Medicine> cart;
	friend class Pharmacist;
public:
	std::vector<std::string> symptoms;
	Client();
	Client(std::string name, std::vector<std::string> symptoms);

	void set_name(std::string name);
	void set_action(std::string action);
	void set_cart(std::vector<Medicine> cart);

	std::string get_name();

	std::vector<std::string> get_symptoms();

	friend std::ostream& operator<<(std::ostream& os, const Client& client);
};

std::ostream& operator<<(std::ostream& os, const Client& second_song);