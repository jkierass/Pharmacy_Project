#include <fstream>
#include <string>
#include "txt_file.h"

TxtFile::TxtFile(std::string path_name, std::string path_symptoms, std::string path_medicine_prescription)
{
    set_path_name(path_name);
    set_path_symptoms(path_symptoms);
	set_path_medicine_prescription(path_medicine_prescription);
}

void TxtFile::set_path_name(std::string path_name)
{
    this->path_name = path_name;
}

void TxtFile::set_path_symptoms(std::string path_symptoms)
{
    this->path_symptoms = path_symptoms;
}

void TxtFile::set_path_medicine_prescription(std::string path_medicine_prescription)
{
	this->path_medicine_prescription = path_medicine_prescription;
}

std::vector<std::string> TxtFile::read_names()
{
    std::ifstream file_handle;
    std::vector<std::string> names;

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

std::vector<std::string> TxtFile::read_symptoms()
{
	std::ifstream file_handle;
	std::vector<std::string> symptoms;

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

std::vector<std::string> TxtFile::read_prescripted_medicines()
{
	std::ifstream file_handle;
	std::vector<std::string> medicines;

	file_handle.open(path_medicine_prescription.c_str());

	if (!file_handle.fail())
	{
		if (file_handle.is_open())
		{
			std::string med;
			do
			{
				file_handle >> med;
				medicines.push_back(med);

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
	return medicines;
}