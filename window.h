#pragma once
#include "client.h"
#include "pharmacist.h"
#include "mdatabase.h"

class Window
{
private:
	bool is_open = false;
	bool is_empty = true;
	Client window_client;
	Pharmacist window_pharmacist;

public:
	Window();

	void start_action();

	void status_close();
	void status_open();
	void status_busy();
	void status_empty();

	bool get_open_status();
	bool get_empty_status();

	void set_pharmacist(Pharmacist pharmacist);
	void set_client(Client client);

	Client& get_client();
};