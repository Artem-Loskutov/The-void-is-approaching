#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <functional>
#include <memory>
#include "game-structs.h"
#include "entity-class.h"

class Game
{
private:
	std::vector<Location>		locations;
	std::vector<Interaction>	interactions;
	std::vector<Action>			actions;
	std::vector<Entity>			entitys;

	std::unordered_map<std::string, Location*>				locations_by_name;
	std::unordered_map<int, Interaction*>					interactions_by_id;
	std::unordered_map<int, Action*>						actions_by_id;
	std::unordered_map<std::string, std::function<void()>>	commands_by_type;

	std::unique_ptr<Player> player;

	void set_data();
	void build_indexes();
	void create_player();
	void create_commands();
public:
	Game();
	void run();
};
