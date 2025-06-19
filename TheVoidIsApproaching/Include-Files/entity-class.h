#pragma once

#include <unordered_map>
#include <string>
#include "game-structs.h"
#include "inventory-class.h"

class Entity
{
protected:
	std::unordered_map<std::string, int> attributes;
public:
	const int id;
	const std::string name;

	Entity(int, std::string, std::unordered_map<std::string, int>);

	std::unordered_map<std::string, int> get_attr();
	void change_attr(std::string, int);
};

class Player : public Entity
{
private:
	Location* current_location;
public:
	Inventory inventory;
	Player(
		int id,
		std::string name,
		std::unordered_map<std::string, int> attributes,
		Location* current_location);

	void		set_location(Location*);
	Location* get_location();
};
