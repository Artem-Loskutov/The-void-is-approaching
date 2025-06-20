#include "interface.h"

#include <iostream>
#include <cstdlib>

void write_main_info(int day, Player& player)
{
	std::string date = "1" + std::to_string(day) + ".05.2077";

	std::cout << "\033[34mKepler-22b\033[0m " << date << " | " <<
		"\033[36m" << player.name << "\033[0m, " <<
		"location: \033[35m" << player.get_location()->name	<< "\033[0m, " <<
		"hp: \033[31m" << player.get_attr()["hp"] << "\033[0m\n";
}

void write_available_interactions(Player& player, std::unordered_map<int, Interaction*>& interaction_by_id)
{
	for (auto& interaction : player.get_location()->interactions_id)
	{
		std::cout << interaction << " - " <<
			interaction_by_id[interaction]->description << "\n";
	}
}

void write_frame(int day, Player& player, std::unordered_map<int, Interaction*>& interaction_by_id)
{
	system("cls");
	write_main_info(day, player);
	std::cout << std::endl;
	write_available_interactions(player, interaction_by_id);
	std::cout << std::endl << "Choose action: ";
}
