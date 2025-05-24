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
	Location(int _id, const std::string _name, const std::vector<int> _interactions_id);

	int					get_id()			const;
	std::string			get_name()			const;
	std::vector<int>	get_interactions()	const;
};

class Interaction
{
private:
	const int id;
	const std::string text;
	const std::vector<int> actions_id;
public:
	Interaction(int _id, const std::string _text, const std::vector<int> _actions_id);

	int					get_id()		const;
	std::string			get_text()		const;
	std::vector<int>	get_actions()	const;
};

class Action
{
private:
	const int id;
	const std::string type;
	const int item_id;
public:
	Action(int _id, const std::string _type, int _item_id);

	int					get_id()		const;
	std::string			get_type()		const;
	int					get_item_id()	const;
};

class Player
{
private:
	Location* current_location;
public:
	Player(Location* _current_locations);

	void				set_location(Location*);
	Location*			get_location()				const;
};
