#include <iostream>
#include <vector>
#include "client.h"
#include <string>
#pragma once

Client::Client() {}

Client::Client(std::string name, std::vector<std::string> symptoms)
{
	this->set_name(name);
	this->symptoms = symptoms;
	this->set_action("");
}

void Client::set_name(std::string name)
{
	this->name = name;
}

void Client::set_action(std::string action)
{
	this->action = action;
}

void Client::set_cart(std::vector<Medicine> cart)
{
	this->cart = cart;
}

std::string Client::get_name()
{
	return this->name;
}

std::vector<std::string> Client::get_symptoms()
{
	return this->symptoms;
}

std::vector<Medicine> Client::get_cart()
{
	return this->cart;
}

std::ostream& operator<<(std::ostream& os, const Client& client)
{
	os << "Client: " << client.name << " Action: " << client.action << std::endl;
	return os;
}
