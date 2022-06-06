#include "mdatabase.h"

bool operator<(const std::unique_ptr<Medicine>& Med, const std::unique_ptr<Medicine>& Med2);


// dodaj leki do bazy danych

void MDatabase::add_Syrup(std::string name, std::string producer, std::string substance, std::vector<std::string> syndroms, int amount, int base_price_gr, bool prescription, std::string cough_type)
{
	std::unique_ptr<Syrup> ASyrup = std::make_unique<Syrup>(name, producer, substance, syndroms, amount, base_price_gr, prescription, cough_type);
	ASyrup->set_position(syrups_num + 1);
	med_database.push_back(std::move(ASyrup));
	med_database.sort();			// already overloaded operator < (sorting by position)
	syrups_num++;
}
void MDatabase::add_Pills(std::string name, std::string producer, std::string substance, std::vector<std::string> syndroms, int amount, int base_price_gr, bool prescription, std::string pills_type)
{
	std::unique_ptr<Pills> APills = std::make_unique<Pills>(name, producer, substance, syndroms, amount, base_price_gr, prescription, pills_type);
	APills->set_position(pills_num + 101);
	med_database.push_back(std::move(APills));
	med_database.sort();
	pills_num++;
}
void MDatabase::add_Drops(std::string name, std::string producer, std::string substance, std::vector<std::string> syndroms, int amount, int base_price_gr, bool prescription, std::string drops_type)
{
	std::unique_ptr<Drops> ADrops = std::make_unique<Drops>(name, producer, substance, syndroms, amount, base_price_gr, prescription, drops_type);
	ADrops->set_position(drops_num + 201);
	med_database.push_back(std::move(ADrops));
	med_database.sort();
	drops_num++;
}
void MDatabase::add_Ointment(std::string name, std::string producer, std::string substance, std::vector<std::string> syndroms, int amount, int base_price_gr, bool prescription, std::string ointment_type)
{
	std::unique_ptr<Ointment> ANOintment = std::make_unique<Ointment>(name, producer, substance, syndroms, amount, base_price_gr, prescription, ointment_type);
	ANOintment->set_position(ointments_num + 301);
	med_database.push_back(std::move(ANOintment));
	med_database.sort();
	ointments_num++;
}

//drukowanie informacji o lekach w bazie danych

void MDatabase::print_total_value(File_dial_out& mo) const
{
	int base_price_ingr = 0;
	double taxed_price = 0.0;
	for (const auto& Medicine_ptr : med_database)
	{
		base_price_ingr += Medicine_ptr->get_base_price_gr();
		taxed_price += Medicine_ptr->get_calculated_price();
	}
	mo << "The total value of medicine in database with no tax included is: " << (double)base_price_ingr/100 << std::endl 
		<< "-||- with tax included: " << taxed_price << std::endl;

	mo << "There is: " << syrups_num << " pieces of Syrup in the database" << std::endl;
	mo << "There is: " << pills_num << " pieces of Pills in the database" << std::endl;
	mo << "There is: " << drops_num << " pieces of Drops in the database" << std::endl;
	mo << "There is: " << ointments_num << " pieces of Ointment in the database" << std::endl;

	mo << std::endl;
}

//drukowanie informacji o ka¿dym leku po kolei (szczegó³owo)

void MDatabase::print_all_data(File_dial_out& mo) const
{
	if (med_database.size() != 0)
	{
		for (const auto& Medicine_ptr : med_database)
		{
			mo << *Medicine_ptr;
		}
	}
	else
		mo << "No objects in database" << std::endl;
}
//usuñ lek z bazy danych
void MDatabase::delete_medicine(int pos)
{
	for (std::list<std::unique_ptr<Medicine>>::iterator it = med_database.begin(); it != med_database.end(); it++)
	{
		if (it->get()->get_position() == pos)
		{
			med_database.erase(it);
			return;
		}
	}
	throw MedicineNotFoundException(pos);
}
//szukanie leku w bazie danych po pozycji na pó³ce
Medicine MDatabase::find_by_position(int pos) const
{
	for (const auto& Medicine_ptr : med_database)
	{
		if (Medicine_ptr->get_position() == pos)
		{
			return *Medicine_ptr;
		}
	}
	throw MedicineNotFoundException(pos);
}

//szukanie leku w bazie danych po imieniu
Medicine MDatabase::find_by_name(std::string name) const
{
	for (const auto& Medicine_ptr : med_database)
	{
		if (Medicine_ptr->get_name() == name)
		{
			return *Medicine_ptr;
		}
	}
	throw MedicineNotFoundException(name);
}

void MDatabase::print_by_name(std::string name, File_dial_out& mo) const
{
	for (const auto& Medicine_ptr : med_database)
	{
		if (Medicine_ptr->get_name() == name)
		{
			mo << *Medicine_ptr;
		}
	}
	throw MedicineNotFoundException(name);
}

bool MDatabase::check_if_exist_pos(int pos) const
{
	for (const auto& Medicine_ptr : med_database)
	{
		if (Medicine_ptr->get_position() == pos)
		{
			return true;
		}
	}
	return false;
}
bool MDatabase::check_if_exist_name(std::string name) const
{
	for (const auto& Medicine_ptr : med_database)
	{
		if (Medicine_ptr->get_name() == name)
		{
			return true;
		}
	}
	return false;
}

int MDatabase::get_drops_num() const
{
	return drops_num;
}

int MDatabase::get_pills_num() const
{
	return pills_num;
}

int MDatabase::get_syrups_num() const
{
	return syrups_num;
}

int MDatabase::get_ointments_num() const
{
	return ointments_num;
} 

// operator to compare objects by position (to use it in sorting)


bool operator<(const std::unique_ptr<Medicine>& Med, const std::unique_ptr<Medicine>& Med2)
{
	return Med2->get_position() < Med->get_position();
}
