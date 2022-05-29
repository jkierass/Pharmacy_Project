#pragma once
#include <fstream>
#include <iostream>
#include "mdatabase.h"

class Database_meds_reader
{
	std::string path;
public:
	Database_meds_reader(std::string path);
	MDatabase read_database();
};

