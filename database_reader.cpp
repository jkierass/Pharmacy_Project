#include "database_reader.h"

Database_reader::Database_reader(std::string path)
{
	this->path = path;
}

MDatabase Database_reader::read_database()
{
	std::ifstream file_handler;
	MDatabase my_database;
	file_handler.open(path);
	if (!file_handler.fail())
	{
		if (file_handler.is_open())
		{
			std::string argument;
			int tmp_symptoms_num;
			std::string tmp_name;
			std::string tmp_producer;
			std::string tmp_substance;
			std::vector<std::string> tmp_symptoms;
			int tmp_amount;
			int tmp_base_price_gr;
			bool tmp_prescription;
			std::string tmp_special_type;
			std::string tmp_symptom;
			int a = 0;
			do
			{
				file_handler >> argument >> tmp_symptoms_num >> tmp_name >> tmp_producer >> tmp_substance;
				for (int i = 0; i < tmp_symptoms_num; i++)
				{
					file_handler >> tmp_symptom;
					tmp_symptoms.push_back(tmp_symptom);
				}
				file_handler >> tmp_amount >> tmp_base_price_gr >> tmp_prescription >> tmp_special_type;
				if (tmp_prescription = 1)
				{
					tmp_prescription = true;
				}
				else
				{
					tmp_prescription = false;
				}
				if (argument == "Pills")
				{
					my_database.add_Pills(tmp_name, tmp_producer, tmp_substance, tmp_symptoms, tmp_amount, tmp_base_price_gr, tmp_prescription, tmp_special_type);
				}
				else if (argument == "Syrup")
				{
					my_database.add_Syrup(tmp_name, tmp_producer, tmp_substance, tmp_symptoms, tmp_amount, tmp_base_price_gr, tmp_prescription, tmp_special_type);
				}
				else if (argument == "Ointment")
				{
					my_database.add_Ointment(tmp_name, tmp_producer, tmp_substance, tmp_symptoms, tmp_amount, tmp_base_price_gr, tmp_prescription, tmp_special_type);
				}
				else if (argument == "Drops")
				{
					my_database.add_Drops(tmp_name, tmp_producer, tmp_substance, tmp_symptoms, tmp_amount, tmp_base_price_gr, tmp_prescription, tmp_special_type);
				}
				a++;
			} while(a < 10);
			file_handler.close();
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

	return my_database;
}
