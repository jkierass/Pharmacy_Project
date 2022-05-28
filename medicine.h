#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include "MedicineNotFoundException.h"
#include "NegativePriceTagException.h"
#include "NegativeAmountException.h"
#include "NegativePositionException.h"

class Medicine
{
protected:
	int amount;
	int position = 0;
	std::string name;
	std::string producer;
	std::string substance;
	int base_price_gr;
	double calculated_price;
	std::string med_type = "No data";

public:
	Medicine(std::string, std::string, std::string, int, int);
	friend std::ostream& operator<<(std::ostream& os, const Medicine& Med);
	virtual void print(std::ostream&) const;
	virtual void calculate_price();
	virtual ~Medicine();

	int get_position() const;
	std::string get_name() const;
	std::string get_producer() const;
	std::string get_substance() const;
	int get_amount() const;
	int get_base_price_gr() const;
	double get_calculated_price() const;
	std::string get_med_type() const;

	void set_name(std::string);
	void set_producer(std::string);
	void set_substance(std::string);
	void set_amount(int);
	void set_base_price_gr(int);
	void set_position(int);

};

