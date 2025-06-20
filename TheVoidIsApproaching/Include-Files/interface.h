#pragma once

#include "entity-class.h"

void write_main_info(int day, Player& player);
void write_available_interactions(Player& player, std::unordered_map<int, Interaction*>& interaction_by_id);

void write_frame(int day, Player& player, std::unordered_map<int, Interaction*>& interaction_by_id);
