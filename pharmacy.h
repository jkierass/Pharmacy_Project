#pragma once
#include "pharmacist.h"
#include "random_objects_generator.h"
#include <vector>
#include "client.h"
#include "mdatabase.h"
#include "database_meds_reader.h"
#include "txt_file.h"
#include "queue.h"
#include "File_dial_out.h"
#include <windows.h>

class Pharmacy
{
private:
	std::vector<Window> windows;
	std::vector<Client> clients;
	std::vector<Pharmacist> pharmacists;
	Queue queue;
	RandomObjectsGenerator generator;
public:
	Pharmacy(std::vector<Window> windows, std::vector<Pharmacist> pharmacists, Queue queue, RandomObjectsGenerator generator);

	void set_windows(std::vector<Window> windows);
	void set_pharmacists(std::vector<Pharmacist> pharmacists);
	void set_queue(Queue queue);
	void set_generator(RandomObjectsGenerator generator);

	void start_simpulation(int iteration_num, std::string output_file_path, MDatabase& pharmacist_knowledge);
};