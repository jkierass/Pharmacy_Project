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

int main()
{
	std::string path_symptoms = "symptoms.txt";
	std::string path = "Med_database_info.txt";
	std::string path_name = "name.txt";
	Database_meds_reader database_reader_file(path);
	MDatabase pharmacist_knowledge;
	pharmacist_knowledge = database_reader_file.read_database();
	TxtFile file(path_name, path_symptoms);
	RandomObjectsGenerator generator(file.read_names(), file.read_symptoms());
	


	int start_iteration = 10;
	int iteration_num = start_iteration;

	std::vector<Window> windows = generator.generate_windows(5);
	Queue queue(generator.generate_clients_vector(10));
	std::vector<Pharmacist> pharmacists;

	while (iteration_num > 0)
	{
		/*Go to if when program start or in half program iterations.
		It simulates shifts between Pharmacy employees*/
		if (iteration_num == start_iteration || iteration_num == start_iteration / 2)
		{
			pharmacists = generator.generate_pharmacists(5);
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

		iteration_num = iteration_num - 1;

		std::cout << windows.size() << std::endl;
		std::cout << pharmacists.size() << std::endl;
		std::cout << queue.get_clients().size() << std::endl;

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
					windows[i].get_client().set_action("ask about medicines");
					//Ustawienie operacji na 1
					windows[i].set_client_operation(1);
					std::vector<Medicine> medicines = windows[i].get_pharmacist().choose_medicines(windows[i].get_client(), pharmacist_knowledge);
					windows[i].get_client().set_basket(medicines);
					std::cout << windows[i].get_pharmacist();
					std::cout << windows[i].get_client() << std::endl;
					Sleep(2000);
					break;
				}

				//Klient kupuje odrazu leki, czyli program mu je wybiera i on je odrazu kupuje - dostaje paragon
				case 2:
				{
					windows[i].get_client().set_action("buy medicines");
					std::vector<Medicine> medicines = windows[i].get_pharmacist().choose_medicines(windows[i].get_client(), pharmacist_knowledge);
					windows[i].get_client().set_basket(medicines);
					windows[i].status_empty();
					std::cout << windows[i].get_pharmacist();
					std::cout << windows[i].get_client() << std::endl;
					//zatrzymuje czas ale nie wiem na ile chyba 2 s XD
					Sleep(2000);
					break;
				}
						
					//Klient odchodzi - opró¿nia siê okno
				case 3:
				{
					windows[i].get_client().set_action("leave Pharmacy");
					windows[i].status_empty();
					std::cout << windows[i].get_pharmacist();
					std::cout << windows[i].get_client() << std::endl;
					Sleep(2000);
					break;
				}

					//Klient pyta o zamiennik
				case 4:
				{
					windows[i].get_client().set_action("ask about substitute");
					windows[i].set_client_operation(2);
					std::cout << windows[i].get_pharmacist();
					std::cout << windows[i].get_client() << std::endl;
					Sleep(2000);
					break;
				}
				}
			}
		}
	}
	return 0;
}