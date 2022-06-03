#pragma once
#include "client.h"
#include "pharmacist.h"
#include "mdatabase.h"

class Window
{
private:
	bool is_open = false;
	bool is_empty = true;
	int client_operation = 0;
	Client window_client;
	Pharmacist window_pharmacist;

public:
	/*void start_action(Pharmacist& my_pharmacist, Client& my_client);*/
	void status_close();
	void status_open();
	void status_busy();
	void status_empty();

	bool get_open_status();
	bool get_empty_status();
	int get_client_operation();

	void set_pharmacist(Pharmacist pharmacist);
	void set_client(Client client);
	void set_client_operation(int num);

	Client& get_client();
	Pharmacist get_pharmacist();
};