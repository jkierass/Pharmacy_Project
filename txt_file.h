#pragma once
#include <fstream>
#include <string>
#include "client.h"

class TxtFile
{
private:
    std::string path;
public:
    std::ifstream file;
    TxtFile(std::string path);

    void set_path(std::string path);
    std::string get_path();

    Client create_client(std::string name);

    bool openFile();

    bool closeFile();

};