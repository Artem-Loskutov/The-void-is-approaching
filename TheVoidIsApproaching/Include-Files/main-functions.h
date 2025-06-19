#pragma once

#include "game-class.h"
#include <unordered_map>
#include <functional>

void complete_interaction(Player& player, Interaction* interaction,
	std::unordered_map<int, Action*>& actions_by_id,
	std::unordered_map<std::string, std::function<void()>>& commands_by_type);
