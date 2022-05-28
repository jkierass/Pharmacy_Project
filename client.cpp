#include <iostream>
#include <vector>
#include "client.h"
#include <string>
#pragma once

Client::Client(std::string name, std::vector<Medicine> medicines)
{
	this->set_name(name);
	this->medicines = medicines;
}

Client::Client(std::string name)
{
	this->name = name;
}

Client::Client() {}

void Client::set_name(std::string name)
{
	this->name = name;
}

std::string Client::get_name()
{
	return this->name;
}

std::vector<Medicine> Client::get_medicines()
{
	return this->medicines;
}

void Client::add_medicine(Medicine medicine)
{
	this->medicines.push_back(medicine);
}
/*
void Client::remove_medicine(Medicine medicine)
{
	std::vector<Medicine>::iterator it;

	it = find(this->medicines.begin(), this->medicines.end(), medicine);
	if (it != this->medicines.end())
	{
		this->medicines.erase(it);
	}
}*/