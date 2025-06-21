#pragma once

#include "entity.hpp"

void player_move(
	int battle_action_id,
	Player& player,
	Entity& enemy,
	std::unordered_map<int, Battle_Action*>& battle_action_by_id,
	std::vector<Entity>& entities);

void enemy_move(
	Player& player,
	Entity& enemy);

void battle(
	Player& player,
	Entity enemy,
	std::unordered_map<int,Battle_Action*>& battle_action_by_id,
	std::vector<Entity>& entities);
