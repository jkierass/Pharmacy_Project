#include <iostream>
#include "pharmacist.h"
#include "random_objects_generator.h"
#include <vector>
#include "client.h"
#include "mdatabase.h"
#include "database_meds_reader.h"
#include "txt_file.h"
#include "queue.h"
#include<windows.h>
#include <cstdlib>

//symptoms.txt Med_database_info.txt name.txt Medicines_prescription.txt

int main(int argc, char* argv[])
{
	if (argc != 5 && argc != 9)
	{
		std::cerr << "Incorrect number of command line arguments - expected 4 or 8, got " << argc << std::endl;
		return 1;
	}

	std::string path_symptoms = argv[1];
	std::string path = argv[2];
	std::string path_name = argv[3];
	std::string path_medicine_prescription = argv[4];

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
		std::cerr << "Wrong path to files " << std::endl;
		return 1;
	}

	RandomObjectsGenerator generator(names, symptoms, prescripted_medicines);

	std::vector<Pharmacist> pharmacists;
	std::vector<Window> windows;
	int iteration_num = 0;
	Queue queue;

	//Start parameters without user input
	if (argc == 5)
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
	if (argc == 9)
	{
		//Converting argv to ints
		for (int i = 5; i < 9; i++)
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


	while (iteration_num > 0)
	{
		iteration_num = iteration_num - 1;

		std::cout << "Windows number: " << windows.size() << std::endl;
		std::cout << "Pharmacists number: " << pharmacists.size() << std::endl;
		std::cout << "Clients in queue number: " << queue.get_clients().size() << std::endl << std::endl;

		//Assigning Clients to window
		for (int i = 0; i < windows.size(); i++)
		{
			if (windows[i].get_open_status() == true && windows[i].get_empty_status() == true)
			{
				if (queue.get_clients().size() != 0)
				{
					windows[i].set_client(queue.get_clients().front());
					queue.remove_client();
					//windows[i].status_busy();
				}
			}
		}

		//Iterate throw windows. Clients make their actions
		for (int i = 0; i < windows.size(); i++)
		{
			std::cout << "a" << std::endl;

			if (windows[i].get_open_status() == true && windows[i].get_empty_status() == false)
			{
				int action_number = 3;

				//Wchodzi jak klient jeszcze nie podj¹³ ¿adnej akcji
				if (windows[i].get_client_operation() == 0)
				{
					//Program wybiera opcjê od 1 do 3
					action_number = generator.generate_number(1,3);
				}

				//Wchodzi jak klient zapyta³ o leki
				if (windows[i].get_client_operation() == 1)
				{
					//Program wybiera opcjê od 2 do 4
					action_number = generator.generate_number(2,4);
				}

				//Wchodzi jak klient zapyta³ o substytut
				if (windows[i].get_client_operation() == 2)
				{
					//Program wybiera opcjê od 2 do 3
					action_number = generator.generate_number(2,3);
				}

				switch(action_number)
				{
					//Klient pyta o leki, czyli wyœwietlaj¹ siê proponowane leki i zapisuj¹ siê u niego w koszyku
				case 1:
				{
					std::cout << "b" << std::endl;
					windows[i].get_client().set_action("ask about medicines");
					//Ustawienie operacji na 1
					windows[i].set_client_operation(1);
					std::cout << "f" << std::endl;
					std::cout << windows[i].get_client().get_symptoms().size() << std::endl;
					for (int z = 0; z < windows[i].get_client().get_symptoms().size(); z++)
					{
						std::cout << windows[i].get_client().get_symptoms()[z] << std::endl;
					}
					windows[i].get_pharmacist().choose_medicines(windows[i].get_client(), pharmacist_knowledge);
					std::cout << "g" << std::endl;
					std::cout << windows[i].get_client().get_cart().size() << std::endl;
					std::cout << windows[i].get_pharmacist();
					std::cout << windows[i].get_client() << std::endl;
					Sleep(2000);
					break;
				}

				//Klient kupuje odrazu leki, czyli program mu je wybiera i on je odrazu kupuje - dostaje paragon
				case 2:
				{
					std::cout << "c" << std::endl;
					for (int z = 0; z < windows[i].get_client().get_symptoms().size(); z++)
					{
						std::cout << windows[i].get_client().get_symptoms()[z] << std::endl;
					}
					windows[i].get_client().set_action("buy medicines");
					windows[i].get_pharmacist().choose_medicines(windows[i].get_client(), pharmacist_knowledge);
					windows[i].status_empty();
					std::cout << windows[i].get_client().get_cart().size() << std::endl;
					std::cout << windows[i].get_pharmacist();
					std::cout << windows[i].get_client() << std::endl;
					windows[i].get_pharmacist().print_receipt(windows[i].get_client());
					//Zresetowanie akcji okienka
					windows[i].set_client_operation(0);
					//zatrzymuje czas ale nie wiem na ile chyba 2 s XD
					Sleep(2000);
					break;
				}
						
					//Klient odchodzi - opró¿nia siê okno
				case 3:
				{
					std::cout << "d" << std::endl;
					windows[i].get_client().set_action("leave Pharmacy");
					windows[i].status_empty();
					std::cout << windows[i].get_client().get_cart().size() << std::endl;
					std::cout << windows[i].get_pharmacist();
					std::cout << windows[i].get_client() << std::endl;
					windows[i].set_client_operation(0);
					Sleep(2000);
					break;
				}


				//Klient pyta o zamiennik
				case 4:
				{
					std::cout << "e" << std::endl;
					windows[i].get_client().set_action("ask about substitute");
					windows[i].set_client_operation(2);
					std::cout << windows[i].get_client().get_cart().size() << std::endl;
					std::cout << windows[i].get_pharmacist();
					std::cout << windows[i].get_client() << std::endl;
					std::cout << windows[i].get_client().get_cart()[0].get_name() << " -replace status:";
					try
					{
						std::vector<Medicine> replaced_meds;
						
						replaced_meds = windows[i].get_pharmacist().choose_cheaper_replacements_and_replace(windows[i].get_client(), pharmacist_knowledge, windows[i].get_client().get_cart()[0]);
						std::cout << " Replaced" << std::endl;
					}
					catch (MedicineNotFoundException)
					{
						std::cout << " No replacement" << std::endl;
					}
					Sleep(2000);
					break;
				}
				}
			}
		}
		
		int client_num = generator.generate_number(0, 2);
		std::vector<Client> new_clients = generator.generate_clients_vector(0, client_num);
		
		//appendinng queue
		for (int i = 0; i < new_clients.size(); i++)
		{
			queue.add_client(new_clients[i]);
		}

	}
	return 0;
}