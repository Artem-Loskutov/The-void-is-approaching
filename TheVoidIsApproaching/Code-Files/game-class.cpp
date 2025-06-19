#include "game-class.h"

#include <iostream>
#include "json-loader.h"
#include "main-functions.h"
#include "battle.h"

void Game::set_data()
{
    locations =     locations_loader("Json-Files/locations.json");
    interactions =  interactions_loader("Json-Files/interactions.json");
    actions =       actions_loader("Json-Files/interactions.json");
    entitys =       entitys_loader("Json-Files/entitys.json");
};

void Game::build_indexes()
{
    for (Location& location : locations)
    {
        locations_by_name[location.name] = &location;
    }

    for (Interaction& interaction : interactions)
    {
        interactions_by_id[interaction.id] = &interaction;
    }

    for (Action& action : actions)
    {
        actions_by_id[action.id] = &action;
    }
}

void Game::create_player()
{
    player = std::make_unique<Player>(entitys.at(0).id, entitys.at(0).name, entitys.at(0).get_attr(), &locations.at(0));
}

void Game::create_commands()
{
    commands_by_type["get_location_info"] = [&]()
        {
            std::cout << player->get_location()->name;
        };
    commands_by_type["change_location"] = [&]()
        {
            std::cout << "Enter location name\n";
            std::string location_name = "";
            std::cin >> location_name;

            if (locations_by_name.contains(location_name))
            {
                player->set_location(locations_by_name[location_name]);
                std::cout << "Location changed to " << location_name;
            }
        };
    commands_by_type["check_inventory"] = [&]()
        {
            player->inventory.check();
        };
    commands_by_type["add_item"] = [&]()
        {
            player->inventory.add_item(0);
        };
    commands_by_type["remove_item"] = [&]()
        {
            player->inventory.remove_item(0);
        };
    commands_by_type["start_battle"] = [&]()
        {
            battle(*player, entitys.at(1));
        };
}

void Game::run()
{
    set_data();
    build_indexes();
    create_player();
    create_commands();

    int interaction_id = 0;

    for (int i = 0; i < 7; i++)
    {
        std::cout << "day" << i << std::endl;

        std::cin >> interaction_id;

        if (interactions_by_id.contains(interaction_id))
        {
            complete_interaction(*player, interactions_by_id[interaction_id], actions_by_id, commands_by_type);
        }
        else
        {
            std::cout << "unknown interaction";
        }
        std::cout << std::endl;
    }
}

Game::Game()
{
    run();
}
