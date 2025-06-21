#pragma once

#include <string>
#include <memory>
#include "json-structs.hpp"
#include "inventory.hpp"

struct Stats
{
	int	health;
	int	resist;
	int	damage;
	int	movement;

	Stats(int _health, int _resist, int _damage, int _movement)
		: health(_health), resist(_resist), damage(_damage), movement(_movement)
	{ }
};

class Entity
{
public:
	const int id;
	const std::string name;
	Stats stats;

	Entity(int _id, std::string _name, Stats _stats);
};

class Player : public Entity
{
public:
	Location* current_location;
	std::unique_ptr<Inventory> inventory;

	Player(int _id,	std::string _name, Stats _stats, Location& _current_location);
};
