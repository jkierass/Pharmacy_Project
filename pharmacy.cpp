#include "pharmacy.h"

Pharmacy::Pharmacy(std::vector<Window> windows, std::vector<Pharmacist> pharmacists, Queue queue, RandomObjectsGenerator generator)
{
	set_windows(windows);
	set_pharmacists(pharmacists);
	set_queue(queue);
	set_generator(generator);
}

void Pharmacy::set_windows(std::vector<Window> windows)
{
	this->windows = windows;
}

void Pharmacy::set_pharmacists(std::vector<Pharmacist> pharmacists)
{
	this->pharmacists = pharmacists;
}

void Pharmacy::set_queue(Queue queue)
{
	this->queue = queue;
}

void Pharmacy::set_generator(RandomObjectsGenerator generator)
{
	this->generator = generator;
}

void Pharmacy::start_simpulation(int iteration_num, std::string output_file_path, std::string path, MDatabase& pharmacist_knowledge)
{
	File_dial_out mo(output_file_path);

	while (iteration_num > 0)
	{
		iteration_num = iteration_num - 1;

		mo << "Windows number: " << windows.size() << std::endl;
		mo << "Pharmacists number: " << pharmacists.size() << std::endl;
		mo << "Clients in queue number: " << queue.get_clients().size() << std::endl << std::endl;

		//Assigning Clients to window
		for (int i = 0; i < windows.size(); i++)
		{
			if (windows[i].get_open_status() == true && windows[i].get_empty_status() == true)
			{
				if (queue.get_clients().size() != 0)
				{
					windows[i].set_client(queue.get_clients().front());
					queue.remove_client();
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
					action_number = generator.generate_number(1, 3);
				}

				//Wchodzi jak klient zapyta³ o leki
				if (windows[i].get_client_operation() == 1)
				{
					//Program wybiera opcjê od 2 do 4
					action_number = generator.generate_number(2, 4);
				}

				//Wchodzi jak klient zapyta³ o substytut
				if (windows[i].get_client_operation() == 2)
				{
					//Program wybiera opcjê od 2 do 3
					action_number = generator.generate_number(2, 3);
				}

				if (windows[i].get_client_operation() == 3)
				{
					//Program wybiera opcjê od 2 do 3
					action_number = generator.generate_number(5, 6);
				}

				switch (action_number)
				{
					//Klient pyta o leki, czyli wyœwietlaj¹ siê proponowane leki i zapisuj¹ siê u niego w koszyku
				case 1:
				{
					windows[i].get_client().set_action("ask about medicines");
					//Ustawienie operacji na 1
					windows[i].set_client_operation(1);
					mo << "- Hello, please help me with my symptoms: " << std::endl;
					for (int z = 0; z < windows[i].get_client().get_symptoms().size(); z++)
					{
						mo << "*" << windows[i].get_client().get_symptoms()[z] << std::endl;
					}
					try
					{
						windows[i].get_pharmacist().choose_medicines(windows[i].get_client(), pharmacist_knowledge);
					}
					catch (MedicineNotFoundException& b)
					{
						std::cerr << b.what() << std::endl;
					}

					mo << "- Hello! There you go: \n\n";
					for (int it = 0; it < windows[i].get_client().get_cart().size(); it++)
					{
						if (windows[i].get_client().get_cart()[it].get_prescription() == false)
							mo << windows[i].get_client().get_cart()[it] << " ";
					}
					mo << std::endl;
					mo << windows[i].get_pharmacist();
					mo << windows[i].get_client() << std::endl;
					//Sleep(2000);
					break;
				}

				//Klient kupuje odrazu leki, czyli program mu je wybiera i on je odrazu kupuje - dostaje paragon
				case 2:
				{
					windows[i].get_client().set_action("buy medicines");
					windows[i].get_pharmacist().choose_medicines(windows[i].get_client(), pharmacist_knowledge);
					mo << windows[i].get_pharmacist();
					mo << windows[i].get_client() << std::endl;
					//Zresetowanie akcji okienka
					windows[i].set_client_operation(3);
					//zatrzymuje czas na 2s
					//Sleep(2000);
					break;
				}

				//Klient odchodzi - opró¿nia siê okno
				case 3:
				{
					windows[i].get_client().set_action("leave Pharmacy");
					windows[i].status_empty();
					mo << windows[i].get_pharmacist();
					mo << windows[i].get_client() << std::endl;
					windows[i].set_client_operation(0);
					//Sleep(2000);
					break;
				}


				//Klient pyta o zamiennik
				case 4:
				{
					windows[i].get_client().set_action("ask about substitute");
					windows[i].set_client_operation(2);
					mo << windows[i].get_pharmacist();
					mo << windows[i].get_client() << std::endl;
					mo << "Please replace: \n" << windows[i].get_client().get_cart()[0] << "Medicine replacement found?\n";
					try
					{
						std::vector<Medicine> replaced_meds;

						replaced_meds = windows[i].get_pharmacist().choose_cheaper_replacements_and_replace(windows[i].get_client(), pharmacist_knowledge, windows[i].get_client().get_cart()[0]);
						mo << " Replaced with: ";
						for (const auto& med_replaced : replaced_meds)
							mo << med_replaced.get_name() << " ";
						mo << std::endl;
					}
					catch (MedicineNotFoundException& a)
					{
						std::cerr << a.what() << std::endl;
					}
					//Sleep(2000);
					break;
				}

				case 5:
				{
					windows[i].get_client().set_action("get receipt");
					mo << windows[i].get_client() << std::endl;
					windows[i].get_pharmacist().print_receipt(windows[i].get_client(), mo);
					windows[i].status_empty();
					windows[i].set_client_operation(0);
					//Sleep(2000);
				}

				case 6:
				{
					windows[i].get_client().set_action("get invoice");
					mo << windows[i].get_client() << std::endl;
					windows[i].get_pharmacist().print_invoide(windows[i].get_client(), mo);
					windows[i].status_empty();
					windows[i].set_client_operation(0);
					//Sleep(2000);
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
}