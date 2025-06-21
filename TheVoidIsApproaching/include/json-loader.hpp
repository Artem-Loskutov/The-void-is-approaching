#pragma once

#include <string>
#include <vector>
#include <functional>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "json-structs.hpp"
#include "entity.hpp"

template <typename Type>
std::vector<Type> json_to_vector(
    const std::string& path,
    const std::string& key_word,
    std::function<Type(const nlohmann::json&)> object)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cout << path << " is not found. Program will be closed.\n";
        return {};
    }

    nlohmann::json json;
    file >> json;

    std::vector<Type> result_vector;

    for (const auto& data_in_json : json[key_word])
    {
        result_vector.emplace_back(object(data_in_json));
    }

    return result_vector;
}

std::vector<Location>       load_locations(const std::string& path);
std::vector<Interaction>    load_interactions(const std::string& path);
std::vector<Action>         load_actions(const std::string& path);
std::vector<Battle_Action>  load_battle_actions(const std::string& path);
std::vector<Item>           load_items(const std::string& path);

std::vector<Entity>         load_entities(const std::string& path);
