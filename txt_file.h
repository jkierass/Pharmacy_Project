#pragma once
#include <fstream>
#include <string>
#include "client.h"

class TxtFile
{
private:
    std::string path;
    std::ifstream file;

public:
    TxtFile(std::string path);

    void set_path(std::string path);
    std::string get_path();

    Client create_client(std::string name, std::vector<std::string> symptoms);

    std::ifstream& get_file();

    int lines_num();

    bool openFile();

    bool closeFile();

};