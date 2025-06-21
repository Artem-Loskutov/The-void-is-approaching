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
    items = load_items("data/items.json");

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

    for (Item& item : items)
    {
        item_by_id[item.id] = &item;
    }
}

void Game::create_player()
{
    player = std::make_unique<Player>(entities.at(0).id, entities.at(0).name, entities.at(0).stats, locations.at(0));
    player->inventory->add(0, 1);
    player->inventory->selected_item = item_by_id[0];
}

void Game::create_commands()
{
    commands_by_type["get_locations_info"] = [&]()
        {
            for (const auto& location : locations)
            {
                std::cout << location.name << std::endl;
            }
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
    commands_by_type["check_inventory"] = [&]()
        {
        player->inventory->print(item_by_id);
        };
    commands_by_type["start_battle"] = [&]()
        {
        battle(*player, entities.at(1), battle_action_by_id, entities);
        };
    commands_by_type["change_weapon"] = [&]()
        {
            std::string item_name;
            std::cout << "Enter the weapon name: ";
            std::cin >> item_name;
            player->inventory->select(item_name, item_by_id);
        };
    commands_by_type["game_end"] = [&]()
        {
            if (player->stats.health <= 0)
            {
                std::cout << "You died.";
                exit(0);
            }
            if (player->inventory->has(3, item_by_id))
            {
                std::cout << "You win.";
                exit(0);
            }
        };

    inventory_change_commands["add_item"] = [&](int item_id, int count)
        {
            player->inventory->add(item_id, count);
        };
    inventory_change_commands["remove_item"] = [&](int item_id, int count)
        {
            player->inventory->remove(item_id, count);
        };

    exchange_command["exchange_items"] = [&](int get_item_id, int get_count, int set_item_id, int set_count)
        {
            if (player->inventory->remove(get_item_id, get_count))
            {
                player->inventory->add(set_item_id, set_count);
            }
        };
}

void Game::run()
{
    get_data();
    build_indexes();
    create_player();
    create_commands();

    for (int day = 0; day < 10; day++)
    {
        write_frame(day, *player, interaction_by_id);

        int interaction_id = 0;
        std::cin >> interaction_id;

        auto& loc_interactions = player->current_location->interactions_id;
        
        if (interaction_by_id.contains(interaction_id) &&
            std::find(loc_interactions.begin(), loc_interactions.end(), interaction_by_id[interaction_id]->id) != loc_interactions.end())
        {
            complete_interaction(*interaction_by_id[interaction_id], action_by_id, commands_by_type, inventory_change_commands, exchange_command);
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
