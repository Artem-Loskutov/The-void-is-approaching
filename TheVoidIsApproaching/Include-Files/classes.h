#pragma once

#include <vector>
#include <string>
#include <unordered_map>

class Location
{
public:
	const int id;
	const std::string name;
	const std::vector<int> interactions_id;

	Location(int _id, std::string _name, std::vector<int> _interactions_id);
};

class Interaction
{
public:
	const int id;
	const std::string text;
	const std::vector<int> actions_id;

	Interaction(int _id, std::string _text, std::vector<int> _actions_id);
};

class Action
{
public:
	const int id;
	const std::string type;

	Action(int _id, std::string _type);
};

class Inventory
{
private:
	std::unordered_map<int, int> inventory;
public:
	void add_item(int item_id);
	void remove_item(int item_id);
	void check();
};

class Player
{
private:
	Location* current_location;
public:
	Inventory inventory;

	Player(Location* _current_locations);

	void					set_location(Location*);
	const Location*			get_location()				const;
};

class Game
{
private:
	std::vector<Location>		locations;
	std::vector<Interaction>	interactions;
	std::vector<Action>			actions;

	Player player;
public:
	Game();

	void run();
};
