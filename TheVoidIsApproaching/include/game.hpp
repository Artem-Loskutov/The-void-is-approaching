#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <functional>
#include <memory>
#include "json-structs.hpp"
#include "entity.hpp"

class Game
{
private:
	std::vector<Location>		locations;
	std::vector<Interaction>	interactions;
	std::vector<Action>			actions;
	std::vector<Battle_Action>	battle_actions;
	std::vector<Item>			items;

	std::vector<Entity>			entities;

	std::unordered_map<std::string, Location*>		locations_by_name;
	std::unordered_map<int, Interaction*>			interaction_by_id;
	std::unordered_map<int, Action*>				action_by_id;
	std::unordered_map<int, Battle_Action*>			battle_action_by_id;
	std::unordered_map<int, Item*>					item_by_id;

	std::unordered_map<std::string, std::function<void()>>	commands_by_type;
	std::unordered_map<std::string, std::function<void(int, int)>>	inventory_change_commands;

	std::unique_ptr<Player> player;

	void get_data();
	void build_indexes();
	void create_player();
	void create_commands();
public:
	Game();
	void run();
};
