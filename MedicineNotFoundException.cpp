#include "MedicineNotFoundException.h"

MedicineNotFoundException::MedicineNotFoundException(std::string msg ) : 
	std::invalid_argument(msg) {}

MedicineNotFoundException::MedicineNotFoundException(int wrong_position) :
	std::invalid_argument("Medicine with position number: : " + std::to_string(wrong_position) + " not found.") {}