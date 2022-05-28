#include <iostream>
#include <vector>
#include "queue.h"

Queue::Queue(std::vector<Client> clients_vector)
{
	set_clients(clients_vector);
}

void Queue::set_clients(std::vector<Client> clients_vector)
{
	clients = clients_vector;
}

std::vector<Client> Queue::get_clients()
{
	return clients;
}

void Queue::add_client(Client person)
{
	clients.push_back(person); // add Client to end of queue
}

void Queue::remove_client()
{
	clients.erase(clients.begin()); // erase first Client from vector
}