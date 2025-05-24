#include "json-loader.h"
#include "classes.h"
#include "main-functions.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

int main() 
{
    // Remove later to file, that start and run game
    auto locations =    locations_loader("Json-Files/locations.json");
    auto interactions = interactions_loader("Json-Files/interactions.json");
    auto actions =      actions_loader("Json-Files/interactions.json");
    Player player(&locations.at(0));

    std::unordered_map<std::string, Location*> locations_by_name;
    for (Location& location : locations)
    {
        locations_by_name[location.get_name()] = &location;
    }

    std::unordered_map<int, Interaction*> interactions_by_id;
    for (Interaction& interaction : interactions)
    {
        interactions_by_id[interaction.get_id()] = &interaction;
    }

    std::unordered_map<int, Action*> actions_by_id;
    for (Action& action : actions)
    {
        actions_by_id[action.get_id()] = &action;
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
            std::cout << player.get_location()->get_name();
        };

    // This is test of program. Remove later
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
