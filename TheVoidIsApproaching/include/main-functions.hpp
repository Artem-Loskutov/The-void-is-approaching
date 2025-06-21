#pragma once

#include "game.hpp"
#include <unordered_map>
#include <functional>

void complete_interaction(Interaction& interaction,
	std::unordered_map<int, Action*>& actions_by_id,
	std::unordered_map<std::string, std::function<void()>>& commands_by_type,
	std::unordered_map<std::string, std::function<void(int, int)>>& inventory_change_commands);
