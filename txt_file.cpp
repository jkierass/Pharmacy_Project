#include <fstream>
#include <string>
#include "txt_file.h"

TxtFile::TxtFile(std::string path)
{
    set_path(path);
    std::ifstream file;
}

void TxtFile::set_path(std::string path)
{
    this->path = path;
}

std::string TxtFile::get_path()
{
    return path;
}

bool TxtFile::openFile()
{
    file.open(path.c_str());
    if (!file.good())
        throw std::invalid_argument("This file does not exist");
    return true;
}

bool TxtFile::closeFile()
{
    file.close();
    return true;
}

Client TxtFile::create_client(std::string name)
{
    return Client(name);
}
