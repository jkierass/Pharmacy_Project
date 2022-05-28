#include <iostream>
#include <vector>
#include "client.h"
#include <string>
#pragma once

Client::Client(std::string name, std::vector<std::string> symptoms)
{
	this->set_name(name);
	this->symptoms = symptoms;
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

std::vector<std::string> Client::get_symptoms()
{
	return this->symptoms;
}
