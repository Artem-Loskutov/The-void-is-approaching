#pragma once

#include "entity.hpp"

void wait_for_enter();

std::string color_text(const std::string& string, const std::string& color_code);
// Template: "\033[34m". Put number between [ and m.
// Colors codes:
// 30: Black;		31: Red;		32 : Green;		33 : Yellow;
// 34: Blue;		35: Magenta;	36 : Cyan;		37 : White;
// 90 - 97 : Bright versions of the above colors.

void write_main_info(
	int day,
	Player& player);
void write_available_interactions(
	Player& player,
	std::unordered_map<int,Interaction*>& interaction_by_id);
void write_frame(
	int day,
	Player& player,
	std::unordered_map<int,Interaction*>& interaction_by_id);

void write_battle_info(
	Entity& player,
	Entity& enemy);
void write_available_battle_actions(
	std::unordered_map<int,Battle_Action*>& battle_actions_by_id);
void write_battle_frame(
	Entity& player,
	Entity& enemy,
	std::unordered_map<int,Battle_Action*>& battle_actions_by_id);
