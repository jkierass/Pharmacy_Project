#include <windows.h>
#include <cstdlib>
#include "pharmacy.h"

//symptoms.txt Med_database_info.txt name.txt Medicines_prescription.txt dialog_output.txt

int main(int argc, char* argv[])
{
	if (argc != 6 && argc != 10)
	{
		std::cerr << "Incorrect number of command line arguments - expected 5 or 9, got " << argc << std::endl;
		return 1;
	}
	std::string path_symptoms = argv[1];
	std::string path = argv[2];
	std::string path_name = argv[3];
	std::string path_medicine_prescription = argv[4];
	std::string output_file_path = argv[5];

	Database_meds_reader database_reader_file(path);
	MDatabase pharmacist_knowledge;
	TxtFile file(path_name, path_symptoms, path_medicine_prescription);

	std::vector<std::string> names;
	std::vector<std::string> symptoms;
	std::vector<std::string> prescripted_medicines;

	try
	{
		pharmacist_knowledge = database_reader_file.read_database();
		names = file.read_names();
		symptoms = file.read_symptoms();
		prescripted_medicines = file.read_prescripted_medicines();
	}
	catch (std::invalid_argument const& ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}

	RandomObjectsGenerator generator(names, symptoms, prescripted_medicines);

	std::vector<Pharmacist> pharmacists;
	std::vector<Window> windows;
	int iteration_num = 0;
	Queue queue;

	//Start parameters without user input
	if (argc == 6)
	{
		iteration_num = 10;

		windows = generator.generate_windows(1, 5);
		queue.set_clients(generator.generate_clients_vector(2, 10));
		pharmacists = generator.generate_pharmacists(1, 5);
		int p_num = pharmacists.size();
		//Assigning employees to windows
		for (int i = 0; i < windows.size(); i++)
		{
			windows[i].status_close();
			if (p_num != 0)
			{
				p_num = p_num - 1;
				if (windows[i].get_open_status() == false)
				{
					windows[i].set_pharmacist(pharmacists[i]);
				}
			}
		}
	
	}
	
	std::vector<int> argv_ints;
	//Start parameters with user input
	if (argc == 10)
	{
		//Converting argv to ints
		for (int i = 6; i < 10; i++)
		{
			char* p;
			errno = 0;
			long conv = strtol(argv[i], &p, 10);

			// Check for errors
			if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN)
			{
				std::cerr << "Wrong start arguments. Fourth, fifth, sixth and seventh argument should be number!" << std::endl;
				return 1;

			}
			argv_ints.push_back(conv);
		}

		iteration_num = argv_ints[3];
		windows = generator.generate_windows(argv_ints[0]);
		queue.set_clients(generator.generate_clients_vector(argv_ints[1]));
		pharmacists = generator.generate_pharmacists(argv_ints[2]);
		int p_num = pharmacists.size();
		//Assigning employees to windows
		for (int i = 0; i < windows.size(); i++)
		{
			windows[i].status_close();
			if (p_num != 0)
			{
				p_num = p_num - 1;
				if (windows[i].get_open_status() == false)
				{
					windows[i].set_pharmacist(pharmacists[i]);
				}
			}
		}

	}

	Pharmacy pharmacy(windows, pharmacists, queue, generator);
	pharmacy.start_simpulation(iteration_num, output_file_path, pharmacist_knowledge);
	
	return 0;
}