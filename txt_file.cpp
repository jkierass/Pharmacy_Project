#include <fstream>
#include <string>
#include "txt_file.h"

TxtFile::TxtFile(std::string path_name, std::string path_symptoms)
{
    set_path_name(path_name);
    set_path_symptoms(path_symptoms);
}

void TxtFile::set_path_name(std::string path_name)
{
    this->path_name = path_name;
}

void TxtFile::set_path_symptoms(std::string path_symptoms)
{
    this->path_symptoms = path_symptoms;
}

std::list<std::string> TxtFile::read_names()
{
    std::ifstream file_handle;
    std::list<std::string> names;

    file_handle.open(path_name.c_str());

	if (!file_handle.fail())
	{
		if (file_handle.is_open())
		{
			std::string name;
			do
			{
				file_handle >> name;
                names.push_back(name);
				
			} while(!file_handle.eof());
			file_handle.close();
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

    return names;
}

std::list<std::string> TxtFile::read_symptoms()
{
	std::ifstream file_handle;
	std::list<std::string> symptoms;

	file_handle.open(path_symptoms.c_str());

	if (!file_handle.fail())
	{
		if (file_handle.is_open())
		{
			std::string symptom;
			do
			{
				file_handle >> symptom;
				symptoms.push_back(symptom);

			} while (!file_handle.eof());
			file_handle.close();
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
	return symptoms;
}