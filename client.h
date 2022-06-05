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
	std::string prescription_medicine;
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
	void set_prescription_medicine(std::string prescription_medicine);

	std::string get_name();
	std::vector<Medicine> get_cart();
	std::vector<std::string> get_symptoms();
	std::string get_prescription_medicine();

	friend std::ostream& operator<<(std::ostream& os, const Client& client);
};

std::ostream& operator<<(std::ostream& os, const Client& second_song);