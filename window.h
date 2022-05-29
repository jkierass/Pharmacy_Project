#pragma once
#include "client.h"
#include "pharmacist.h"
#include "mdatabase.h"

class Window
{
private:
	bool is_open;
	bool is_empty;
	Client window_client;
//	Pharmacist window_pharmacist;

public:
	Window();
	void start_action();
	void status_close();
	void status_open();

	void status_busy();
	void status_empty();
};