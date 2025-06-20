#include "game-class.h"

#include "interface.h"
#include <iostream>
#include "json-loader.h"
#include "main-functions.h"
#include "battle.h"

void Game::set_data()
{
    locations =     locations_loader("Json-Files/locations.json");
    interactions =  interactions_loader("Json-Files/interactions.json");
    actions =       actions_loader("Json-Files/interactions.json");
    entities =      entities_loader("Json-Files/entities.json");
};

void Game::build_indexes()
{
    for (Location& location : locations)
    {
        locations_by_name[location.name] = &location;
    }

    for (Interaction& interaction : interactions)
    {
        interaction_by_id[interaction.id] = &interaction;
    }

    for (Action& action : actions)
    {
        actions_by_id[action.id] = &action;
    }
}

void Game::create_player()
{
    player = std::make_unique<Player>(entities.at(0).id, entities.at(0).name, entities.at(0).get_attr(), &locations.at(0));
}

void Game::create_commands()
{
    commands_by_type["get_location_info"] = [&]()
        {
            std::cout << player->get_location()->name << std::endl;
        };
    commands_by_type["change_location"] = [&]()
        {
            std::cout << "Enter location name: ";
            std::string location_name = "";
            std::cin >> location_name;

            if (locations_by_name.contains(location_name))
            {
                player->set_location(locations_by_name[location_name]);
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
            battle(*player, entities.at(1));
        };
}

void Game::run()
{
    set_data();
    build_indexes();
    create_player();
    create_commands();

    for (int day = 0, interaction_id = 0; day < 7; day++)
    {
        write_frame(day, *player, interaction_by_id);

        std::cin >> interaction_id;

        auto& loc_interactions = player->get_location()->interactions_id;

        if (interaction_by_id.contains(interaction_id) &&
            std::find(loc_interactions.begin(), loc_interactions.end(), interaction_by_id[interaction_id]->id) != loc_interactions.end())
        {
            complete_interaction(interaction_by_id[interaction_id], actions_by_id, commands_by_type);
        }
        else
        {
            std::cout << "Unknown interaction\n";
        }

        std::cout << "\nPress enter to continue";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}

Game::Game()
{
    run();
}
