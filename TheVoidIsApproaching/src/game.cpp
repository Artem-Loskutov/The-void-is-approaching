#include "game.hpp"

#include "interface.hpp"
#include <iostream>
#include "json-loader.hpp"
#include "main-functions.hpp"
#include "battle.hpp"

void Game::get_data()
{
    locations = load_locations("data/locations.json");
    interactions = load_interactions("data/interactions.json");
    actions = load_actions("data/interactions.json");
    battle_actions = load_battle_actions("data/battle-actions.json");

    entities = load_entities("data/entities.json");
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
        action_by_id[action.id] = &action;
    }

    for (Battle_Action& battle_action : battle_actions)
    {
        battle_action_by_id[battle_action.id] = &battle_action;
    }
}

void Game::create_player()
{
    player = std::make_unique<Player>(entities.at(0).id, entities.at(0).name, entities.at(0).stats, locations.at(0));
}

void Game::create_commands()
{
    commands_by_type["get_location_info"] = [&]()
        {
            std::cout << player->current_location->name << std::endl;
        };
    commands_by_type["change_location"] = [&]()
        {
            std::cout << "Enter location name: ";
            std::string location_name = "";
            std::cin >> location_name;

            if (locations_by_name.contains(location_name))
            {
                player->current_location = locations_by_name[location_name];
            }
        };
}

void Game::run()
{
    get_data();
    build_indexes();
    create_player();
    create_commands();

    for (int day = 0, interaction_id = 0; day < 7; day++)
    {
        write_frame(day, *player, interaction_by_id);
        std::cin >> interaction_id;

        auto& loc_interactions = player->current_location->interactions_id;
        
        if (interaction_by_id.contains(interaction_id) &&
            std::find(loc_interactions.begin(), loc_interactions.end(), interaction_by_id[interaction_id]->id) != loc_interactions.end())
        {
            complete_interaction(*interaction_by_id[interaction_id], action_by_id, commands_by_type);
        }
        else
        {
            std::cout << "Unknown interaction\n";
        }

        wait_for_enter();
    }
}

Game::Game()
{
    run();
}
