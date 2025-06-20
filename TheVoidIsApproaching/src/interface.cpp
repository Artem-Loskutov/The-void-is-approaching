#include "interface.hpp"

#include <iostream>
#include <cstdlib>

void wait_for_enter()
{
	std::cout << "Press enter to continue";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

std::string color_text(const std::string& string, const std::string& color_code)
{
	return std::string(color_code + string + "\033[0m");
}

void write_main_info(
	int day,
	Player& player)
{
	std::string date = "1" + std::to_string(day) + ".05.2077";

	std::cout << color_text("Kepler-22b", "\033[34m") << " " <<
		date << " | " <<
		color_text(player.name, "\033[36m") << ", " <<
		"location: " << color_text(player.current_location->name, "\033[35m") << ", " <<
		"health:" << color_text(std::to_string(player.stats.health), "\033[31m") << "\n";
}
void write_available_interactions(
	Player& player,
	std::unordered_map<int,Interaction*>& interaction_by_id)
{
	for (auto& interaction : player.current_location->interactions_id)
	{
		std::cout << interaction << " - " <<
			interaction_by_id[interaction]->description << "\n";
	}
}
void write_frame(
	int day,
	Player& player,
	std::unordered_map<int,Interaction*>& interaction_by_id)
{
	system("cls");
	write_main_info(day, player);
	std::cout << std::endl;
	write_available_interactions(player, interaction_by_id);
	std::cout << std::endl;
	std::cout << "Choose action: ";
}

void write_battle_info(
	Entity& player,
	Entity& enemy)
{
	std::cout << color_text(player.name, "\033[36m") << ", " <<
		"health: " << color_text(std::to_string(player.stats.health), "\033[31m") << ", " <<
		"resist: " << color_text(std::to_string(player.stats.resist), "\033[31m") << ", " <<
		"damage: " << color_text(std::to_string(player.stats.damage), "\033[31m") << ", " <<
		"movement: " << color_text(std::to_string(player.stats.movement), "\033[31m") << ", " <<
		" | " <<
		color_text(enemy.name, "\033[35m") << ", " <<
		"health: " << color_text(std::to_string(enemy.stats.health), "\033[31m") << ", " <<
		"resist: " << color_text(std::to_string(enemy.stats.resist), "\033[31m") << ", " <<
		"damage: " << color_text(std::to_string(enemy.stats.damage), "\033[31m") << ", " <<
		"movement: " << color_text(std::to_string(enemy.stats.movement), "\033[31m") << "\n";
}

void write_available_battle_actions(
	std::unordered_map<int,Battle_Action*>& battle_actions_by_id)
{
	for (auto& battle_action : battle_actions_by_id)
	{
		std::cout << battle_action.second->id << " - " <<
			battle_action.second->name << "\n";
	}
}

void write_battle_frame(
	Entity& player,
	Entity& enemy,
	std::unordered_map<int,Battle_Action*>& battle_actions_by_id)
{
	system("cls");
	write_battle_info(player, enemy);
	std::cout << std::endl;
	if (player.stats.movement > 0)
	{
		write_available_battle_actions(battle_actions_by_id);
		std::cout << std::endl;
		std::cout << "Choose action: ";
	}
}
