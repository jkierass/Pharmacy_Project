#include "MedicineNotFoundException.h"

MedicineNotFoundException::MedicineNotFoundException(std::string wrong_name) : 
	std::invalid_argument("Medicine with name: " + wrong_name + " not found.") {}

MedicineNotFoundException::MedicineNotFoundException(int wrong_position) :
	std::invalid_argument("Medicine with position number: : " + std::to_string(wrong_position) + " not found.") {}