#pragma once

#include <string>
#include <vector>

struct Location
{
	int					id;
	std::string			name;
	std::vector<int>	interactions_id;

	Location(int _id, std::string _name, std::vector<int> _interactions_id)
		: id(_id), name(std::move(_name)), interactions_id(std::move(_interactions_id))
	{}
};

struct Interaction
{
	int					id;
	std::string			description;
	std::vector<int>	actions_id;
	std::vector<int>	item_args;

	Interaction(int _id, std::string _description, std::vector<int> _actions_id, std::vector<int> _item_args)
		: id(_id), description(std::move(_description)), actions_id(std::move(_actions_id)), item_args(std::move(_item_args))
	{}
};

struct Action
{
	int				id;
	std::string		type;

	Action(int _id, std::string _type)
		: id(_id), type(std::move(_type))
	{}
};

struct Battle_Action
{
	int				id;
	std::string		name;
	std::string		target;
	int				health;
	int				resist;
	int				damage;
	int				movement;

	Battle_Action(int _id, std::string _name, std::string _target, int _health, int _resist, int _damage, int _movement)
		: id(_id), name(std::move(_name)), target(std::move(_target)), health(_health), resist(_resist), damage(_damage), movement(_movement)
	{}
};

struct Item
{
	int				id;
	std::string		name;
	int				damage;

	Item(int _id, std::string _name, int _damage)
		: id(_id), name(_name), damage(_damage)
	{ }
};
