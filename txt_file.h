#pragma once
#include <fstream>
#include <string>
#include "client.h"
#include <vector>

class TxtFile
{
private:
    std::string path_name;
    std::string path_symptoms;
    std::string path_medicine_prescription;

public:
    TxtFile(std::string path_name, std::string path_symptoms, std::string path_medicine_prescription);

    void set_path_name(std::string path_name);
    void set_path_symptoms(std::string path_symptoms);
    void set_path_medicine_prescription(std::string path_medicine_prescription);

    std::vector<std::string> read_names();
    std::vector<std::string> read_symptoms();
    std::vector<std::string> read_prescripted_medicines();
};