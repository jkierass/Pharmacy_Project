#include "database_reader.h"

Database_reader::Database_reader(std::string path)
{
	this->path = path;
}

MDatabase Database_reader::read_database()
{
	std::ifstream file_handler;
	file_handler.open(path);
	if (!file_handler.fail())
	{
		if (file_handler.is_open())
		{
			do
			{
				std::string argument;
				file_handler >> argument;
				if (argument == "Pills")
				{

				}
			} while (file_handler.eof());
		}
		else
		{
			throw std::invalid_argument("not opened");
		}
	}
	else
	{
		throw std::invalid_argument("not found");
	}
}
