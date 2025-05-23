#pragma once

#include <vector>
#include <string>

class Location
{
private:
	const int id;
	const std::string name;
	const std::vector<int> interactions_id;
public:
	Location(const int _id, const std::string _name, const std::vector<int> _interactions_id);

	int					get_id();
	std::string			get_name();
	std::vector<int>	get_interactions();
};

class Interaction
{
private:
	const int id;
	const std::string text;
	const std::vector<int> actions_id;
public:
	Interaction(const int _id, const std::string _text, const std::vector<int> _actions_id);

	int					get_id();
	std::string			get_text();
	std::vector<int>	get_actions();
};

void complete_interaction(Interaction* interaction);

class Player
{
private:
	Location* current_location;
public:
	Player(Location* _current_locations);

	void				set_location(Location*);
	Location*			get_location();
};
