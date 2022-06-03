#include <iostream>
#include "pharmacist.h"
#include "random_objects_generator.h"
#include <vector>
#include "client.h"
#include "mdatabase.h"
#include "database_meds_reader.h"
#include "txt_file.h"
#include "queue.h"

int main()
{
	std::string path_symptoms = "symptoms_patient.txt";
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

	//while (iteration_num > 0)
	//{
		iteration_num = iteration_num - 1;
		/*Go to if when program start or in half program iterations.
		It simulates shifts between Pharmacy employees*/
		if (iteration_num == start_iteration || iteration_num == start_iteration / 2)
		{
			std::vector<Pharmacist> pharmacists = generator.generate_pharmacists(5);
			//Assigning employees to windows
			for (int i = 0; i < windows.size(); i++)
			{
				windows[i].status_close();
				if (pharmacists.size() != 0)
				{
					if (windows[i].get_open_status() == false)
					{
						windows[i].set_pharmacist(pharmacists.front());
						pharmacists.erase(pharmacists.begin());
						windows[i].status_open();
					}
				}
			}
		}

		//Assigning Clients to window
		for (int i = 0; i < windows.size(); i++)
		{
			if (windows[i].get_open_status() == true && windows[i].get_empty_status() == true)
			{
				windows[i].set_client(queue.get_clients().front());
				queue.remove_client();
				windows[i].status_busy();
			}
		}

		//Iterate throw windows. Clients make their actions
		for (int i = 0; i < windows.size(); i++)
		{
			int action_number = generator.generate_number(3);
			
			switch (action_number)
			{
			case 1:
				windows[i].get_client().set_action(" buy medicines");
				std::cout << windows[i].get_client() << std::endl;
				break;
			case 2:
				windows[i].get_client().set_action(" leave Pharmacy");
				std::cout << windows[i].get_client() << std::endl;
				//nie kup (odejdŸ)
				break;
			case 3:
				windows[i].get_client().set_action(" leave Pharmacy");
				std::cout << windows[i].get_client() << std::endl;
				//kup tañszy zamiennik
				break;
			case 4:
				break;
			}

		}
	

	//}

	//my_database.print_all_data();

	/*std::vector<std::string> patient_symptoms = { "after_stroke", "dry_cough", "wet_cough"};
	std::vector<std::string> tmp_symptoms = patient_symptoms;
	std::vector<chosen_medicine> tmp_chosen_meds;
	std::vector<Medicine> medicines;
	chosen_medicine tmp_med;
	std::string tmp_med_name;*/


	return 0;
}