#pragma once
#include <list>
#include <memory>
#include "medicine.h"
#include "ointment.h"
#include "drops.h"
#include "syrup.h"
#include "pills.h"

struct chosen_medicine;

class MDatabase
{
	friend class Pharmacist;
	int syrups_num = 0;
	int pills_num = 0;
	int drops_num = 0;
	int ointments_num = 0;
	std::list<std::unique_ptr<Medicine>> med_database;
	friend std::vector<chosen_medicine> get_all_meds_for_symptoms(std::vector<std::string> vector_symptoms, MDatabase& database);
public:
	void add_Syrup(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string cough_type);
	void add_Pills(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string pills_type);
	void add_Drops(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string drops_type);
	void add_Ointment(std::string name, std::string producer, std::string substance, std::vector<std::string>, int amount, int base_price_gr, bool, std::string ointment_type);
	void print_total_value(File_dial_out&) const;
	void print_all_data(File_dial_out&) const;
	void print_by_name(std::string, File_dial_out&) const;
	void delete_medicine(int);
	Medicine find_by_position(int pos) const;
	Medicine find_by_name(std::string name) const;
	bool check_if_exist_pos(int pos) const;
	bool check_if_exist_name(std::string name) const;
	int get_syrups_num() const;
	int get_pills_num() const;
	int get_drops_num() const;
	int get_ointments_num() const;
};