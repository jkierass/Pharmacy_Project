#pragma once

class Window
{
private:
	bool is_open;
	bool is_empty;
public:
	Window();
	void status_close();
	void status_open();

	void status_busy();
	void status_empty();
};