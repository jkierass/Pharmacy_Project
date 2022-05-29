#include "window.h"

Window::Window()
{
	this->is_open = false;
	this->is_empty = true;
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