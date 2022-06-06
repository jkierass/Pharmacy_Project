#pragma once
#include <string>
#include <iostream>
#include <fstream>
class File_dial_out :
    public std::ostream
{
private:
    std::string path;
public:
    File_dial_out(std::string path);

};

