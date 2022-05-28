#include <iostream>
#include <vector>
#include <string>
#include "client.h"
#pragma once

class Queue
{
private:
	std::vector<Client> clients;

public:

	Queue(std::vector<Client> clients_vector = {});

	void set_clients(std::vector<Client> clients_vector = {});
	std::vector<Client> get_clients();

	void add_client(Client person);

	void remove_client();
};