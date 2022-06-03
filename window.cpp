#include "window.h"

bool Window::get_open_status()
{
	return this->is_open;
}
bool Window::get_empty_status()
{
	return this->is_empty;
}

void Window::status_empty()
{
	is_empty = true;
}

void Window::status_busy()
{
	is_empty = false;
}

void Window::status_open()
{
	is_open = true;
}

void Window::status_close()
{
	is_open = false;
}

//void Window::start_action()
//{
//
//}

void Window::set_pharmacist(Pharmacist pharmacist)
{
	this->window_pharmacist = pharmacist;
	status_open();
}

void Window::set_client(Client client)
{
	this->window_client = client;
	status_busy();
}

Client& Window::get_client()
{
	return this->window_client;
}