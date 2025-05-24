#include "classes.h"

#include <iostream>
#include <fstream>
#include "json.hpp" // nlohmann::json

std::vector<Location> locations_loader(std::string path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Locations file is not found" << std::endl;
        return {};
    }
    else
    {
        nlohmann::json json;
        file >> json;

        std::vector<Location> locations;

        for (const auto& location_in_json : json["locations"])
        {
            int _id =               location_in_json["location_id"];
            std::string _name =     location_in_json["location_name"];
            auto _interactions_id = location_in_json["interactions_id"].get<std::vector<int>>();

            locations.emplace_back(_id, _name, _interactions_id);
        }

        return locations;
    }
}

std::vector<Interaction> interactions_loader(std::string path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Interactions file is not found" << std::endl;
        return {};
    }
    else
    {
        nlohmann::json json;
        file >> json;

        std::vector<Interaction> interactions;

        for (const auto& interaction_in_json : json["interactions"])
        {
            int _id =               interaction_in_json["interaction_id"];
            std::string _text =     interaction_in_json["text"];
            auto _actions_id =      interaction_in_json["actions_id"].get<std::vector<int>>();

            interactions.emplace_back(_id, _text, _actions_id);
        }

        return interactions;
    }
}

std::vector<Action> actions_loader(std::string path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Actions file is not found" << std::endl;
        return {};
    }
    else
    {
        nlohmann::json json;
        file >> json;

        std::vector<Action> actions;

        for (const auto& action_in_json : json["actions"])
        {
            int _id =               action_in_json["action_id"];
            std::string _type =     action_in_json["type"];
            int _item_id =          action_in_json["item_id"];

            actions.emplace_back(_id, _type, _item_id);
        }

        return actions;
    }
}
