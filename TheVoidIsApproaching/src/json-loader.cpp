#include "json-loader.hpp"

std::vector<Location> load_locations(const std::string& path)
{
	return json_to_vector<Location>(
		path,
		"locations",
		[](const nlohmann::json& json)
		{
			return Location(
				json["location_id"],
				json["name"],
				json["interactions_id"].get<std::vector<int>>());
		});
}

std::vector<Interaction> load_interactions(const std::string& path)
{
	return json_to_vector<Interaction>(
		path,
		"interactions",
		[](const nlohmann::json& json)
		{
			return Interaction(
				json["interaction_id"],
				json["description"],
				json["actions_id"].get<std::vector<int>>(),
				json["item_args"].get<std::vector<int>>());
		});
}

std::vector<Action> load_actions(const std::string& path)
{
	return json_to_vector<Action>(
		path,
		"actions",
		[](const nlohmann::json& json)
		{
			return Action(
				json["action_id"],
				json["type"]);
		});
}

std::vector<Battle_Action> load_battle_actions(const std::string& path)
{
	return json_to_vector<Battle_Action>(
		path,
		"battle_actions",
		[](const nlohmann::json& json)
		{
			return Battle_Action(
				json["battle_action_id"],
				json["name"],
				json["target"],
				json["health"],
				json["resist"],
				json["damage"],
				json["movement"]);
		});
}

std::vector<Item> load_items(const std::string& path)
{
	return json_to_vector<Item>(
		path,
		"items",
		[](const nlohmann::json& json)
		{
			return Item(
				json["item_id"],
				json["name"],
				json["damage"]);
		});
}

std::vector<Entity> load_entities(const std::string& path)
{
	return json_to_vector<Entity>(
		path,
		"entities",
		[](const nlohmann::json& json)
		{
			return Entity(
				json["entity_id"],
				json["name"],
				Stats(
					json["health"],
					json["resist"],
					json["damage"],
					json["movement"]));
		});
}
