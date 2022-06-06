#include "File_dial_out.h"

File_dial_out::File_dial_out(std::string path) : out2(path, std::ofstream::out)
{
	if (out2.fail())
		throw std::invalid_argument("Could not find a path to the file to save output to.");
	if (!(out2.is_open()))
		throw std::invalid_argument("Could not open the file to save output.");
}
File_dial_out::~File_dial_out()
{
	out2.close();
}