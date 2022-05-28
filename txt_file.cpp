#include <fstream>
#include <string>
#include "txt_file.h"

TxtFile::TxtFile(std::string path)
{
    set_path(path);
}

void TxtFile::set_path(std::string path)
{
    this->path = path;
}

std::string TxtFile::get_path()
{
    return path;
}

std::ifstream& TxtFile::get_file()
{
    return file;
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

Client TxtFile::create_client(std::string name, std::vector<std::string> symptoms)
{
    return Client(name, symptoms);
}

int TxtFile::lines_num()
{
    std::string line;
    int count = 0;

    if (file.is_open())
    {
        while (file.peek() != EOF)
        {
            std::getline(file, line);
            count++;
        }
    }

    return count;
}
