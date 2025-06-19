#include "classes.h"
#include "json-loader.h"
#include "main-functions.h"

#include <unordered_map>
#include <functional>
#include <iostream>

// Base classes

Location::Location(int _id, std::string _name, std::vector<int> _interactions_id)
	: id(_id), name(_name), interactions_id(_interactions_id) {}

Interaction::Interaction(int _id, std::string _text, std::vector<int> _actions_id)
	: id(_id), text(_text), actions_id(_actions_id) {}

Action::Action(int _id, std::string _type)
	: id(_id), type(_type) {}

// Inventory class

void Inventory::add_item(int item_id)
{
    inventory[item_id] += 1;
}

void Inventory::remove_item(int item_id)
{
    if (inventory.contains(item_id))
    {
        int& item_quantity = inventory[item_id];
        if (item_quantity == 1)
        {
            inventory.erase(item_id);
        }
        item_quantity -= 1;
    }
}

void Inventory::check()
{
    if (inventory.size())
    {
        for (auto& item : inventory)
        {
            std::cout << item.first << " " << item.second;
        }
    }
    else
    {
        std::cout << "inventory is empty";
    }
}

// Player class

Player::Player(Location* _current_location)
	: current_location(_current_location) {}

void Player::set_location(Location* location) { current_location = location; }

const Location* Player::get_location() const { return current_location; }

// Game class

Game::Game() : locations(locations_loader("Json-Files/locations.json")), interactions(interactions_loader("Json-Files/interactions.json")),
actions(actions_loader("Json-Files/interactions.json")), player(Player(&locations.at(0)))
{ }

void Game::run()
{
    std::unordered_map<std::string, Location*> locations_by_name;
    for (Location& location : locations)
    {
        locations_by_name[location.name] = &location;
    }

    std::unordered_map<int, Interaction*> interactions_by_id;
    for (Interaction& interaction : interactions)
    {
        interactions_by_id[interaction.id] = &interaction;
    }

    std::unordered_map<int, Action*> actions_by_id;
    for (Action& action : actions)
    {
        actions_by_id[action.id] = &action;
    }

    std::unordered_map<std::string, std::function<void()>> commands_by_type;
    commands_by_type["change_location"] = [&]()
        {
            std::cout << "Enter location name\n";
            std::string location_name = "";
            std::cin >> location_name;

            if (locations_by_name.contains(location_name))
            {
                player.set_location(locations_by_name[location_name]);
                std::cout << "Location changed to " << location_name;
            }
        };
    commands_by_type["get_location_info"] = [&]()
        {
            std::cout << player.get_location()->name;
        };
    commands_by_type["check_inventory"] = [&]()
        {
            player.inventory.check();
        };
    commands_by_type["add_item"] = [&]()
        {
            player.inventory.add_item(0);
        };
    commands_by_type["remove_item"] = [&]()
        {
            player.inventory.remove_item(0);
        };

    int interaction_id = 0;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "day" << i << std::endl;

        std::cin >> interaction_id;

        if (interactions_by_id.contains(interaction_id))
        {
            complete_interaction(player, interactions_by_id[interaction_id], actions_by_id, commands_by_type);
        }
        else
        {
            std::cout << "unknown interaction";
        }

        std::cout << std::endl;
    }
}
