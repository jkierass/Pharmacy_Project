#pragma once
#include <list>
#include <memory>
#include <map>
#include "medicine.h"
#include "ointment.h"
#include "drops.h"
#include "syrup.h"
#include "pills.h"
#include "pharmacist.h"

class MDatabase
{
	friend class Pharmacist;
	std::list<std::unique_ptr<Medicine>> med_database;
	int syrups_num = 0;
	int pills_num = 0;
	int drops_num = 0;
	int ointments_num = 0;
public:
	void add_Syrup(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string cough_type);
	void add_Pills(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string pills_type);
	void add_Drops(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string drops_type);
	void add_Ointment(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string ointment_type);
	void print_total_value() const noexcept;
	void print_all_data() const noexcept;
	void print_by_name(std::string) const;
	void delete_medicine(int);
	Medicine find_by_position(int pos) const;
	Medicine find_by_name(std::string name) const;
	bool check_if_exist_pos(int pos) const;
	bool check_if_exist_name(std::string name) const;
};