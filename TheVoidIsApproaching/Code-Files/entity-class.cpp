#include "entity-class.h"

#include <iostream>

Entity::Entity(int _entity_id, std::string _entity_name, std::unordered_map<std::string, int> _attributes) :
    id(_entity_id), name(_entity_name), attributes(_attributes) {}

std::unordered_map<std::string, int> Entity::get_attr()
{
    return attributes;
}

void Entity::change_attr(std::string attr_name, int attr_change)
{
    attributes[attr_name] += attr_change;
}

// Player class

Player::Player(
    int _id,
    std::string _name,
    std::unordered_map<std::string, int> _attributes,
    Location* _current_location)
    :
    Entity(_id, _name, _attributes),
    current_location(_current_location)
{ }

void Player::set_location(Location* location)   { current_location = location; }
Location* Player::get_location()                { return current_location; }
