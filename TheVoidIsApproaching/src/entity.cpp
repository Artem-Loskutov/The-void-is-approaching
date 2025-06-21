#include "entity.hpp"

Entity::Entity(int _id, std::string _name, Stats _stats)
    : id(_id), name(std::move(_name)), stats(std::move(_stats))
{}

Player::Player(int _id, std::string _name, Stats _stats, Location& _current_location)
    : Entity(_id, _name, _stats), current_location(&_current_location)
{
    inventory = std::make_unique<Inventory>();
}
