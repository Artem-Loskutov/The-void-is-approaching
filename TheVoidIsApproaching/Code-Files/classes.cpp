#include "classes.h"

// Location class

Location::Location(int _id, const std::string _name, const std::vector<int> _interactions_id)
	: id(_id), name(_name), interactions_id(_interactions_id) {}

int Location::get_id() const { return id; }

std::string Location::get_name() const { return name; }

std::vector<int> Location::get_interactions() const {	return interactions_id; }

// Interaction class

Interaction::Interaction(int _id, const std::string _text, const std::vector<int> _actions_id)
	: id(_id), text(_text), actions_id(_actions_id) {}

int Interaction::get_id() const { return id; };

std::string Interaction::get_text() const { return text; }

std::vector<int> Interaction::get_actions() const { return actions_id; }

// Action class

Action::Action(int _id, const std::string _type, int _item_id)
	: id(_id), type(_type), item_id(_item_id) {}

int Action::get_id() const { return id; }

std::string Action::get_type() const { return type; }

int Action::get_item_id() const { return item_id; }

// Player class

Player::Player(Location* _current_location)
	: current_location(_current_location) {}

void Player::set_location(Location* location) { current_location = location; }

Location* Player::get_location() const { return current_location; }
