#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <iomanip>
class File_dial_out : public std::streambuf
{
private:
    std::string path;
    std::ostream& out1 = std::cout;
    std::ofstream out2;
public:
    File_dial_out(std::string path);
    ~File_dial_out();
    template <typename T>
    friend File_dial_out& operator<<(File_dial_out& mo, T const& t) { mo.out1 << t; mo.out2 << t; return mo;}
    friend File_dial_out& operator<<(File_dial_out& mo, std::ostream& (*f)(std::ostream&)) {  mo.out1 << f; mo.out2 << f; return mo;}
};

