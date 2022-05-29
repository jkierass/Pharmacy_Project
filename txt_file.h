#pragma once
#include <fstream>
#include <string>
#include "client.h"
#include <list>

class TxtFile
{
private:
    std::string path_name;
    std::string path_symptoms;

public:
    TxtFile(std::string path_name, std::string path_symptoms);

    void set_path_name(std::string path_name);
    void set_path_symptoms(std::string path_symptoms);

    std::list<std::string> read_names();
    std::list<std::string> read_symptoms();

    int lines_num(std::string path);
};