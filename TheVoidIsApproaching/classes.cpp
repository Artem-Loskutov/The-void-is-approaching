#include "classes.h"

#include <vector>
#include <string>
#include <iostream>

// Location class

Location::Location(const int _id, const std::string _name, const std::vector<int> _interactions_id)
	: id(_id), name(_name), interactions_id(_interactions_id) {}

int Location::get_id() { return id; }

std::string Location::get_name() { return name; }

std::vector<int> Location::get_interactions() {	return interactions_id; }

// Interaction class

Interaction::Interaction(const int _id, const std::string _text, const std::vector<int> _actions_id)
	: id(_id), text(_text), actions_id(_actions_id) {}

int Interaction::get_id() { return id; }

std::string Interaction::get_text() { return text; }

std::vector<int> Interaction::get_actions() { return actions_id; }

void complete_interaction(Player& player, Interaction& interaction)
{
	if (interaction in player.get_location()->get_interactions())

	std::cout << interaction.get_text() << std::endl;

	for (const int& action_id : interaction.get_actions())
	{
		std::cout << action_id;
		//add actions
	}
}

// Player class

Player::Player(Location* _current_location)
	: current_location(_current_location) {}

void Player::set_location(Location* location) { current_location = location; }

Location* Player::get_location() { return current_location; }

void change_location(Player* player, Location* location) { player->set_location(location); }