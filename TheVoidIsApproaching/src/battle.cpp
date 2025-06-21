#include "battle.hpp"

#include <iostream>
#include "interface.hpp"
#include "main-functions.hpp"

void player_move(
	int battle_action_id,
	Player& player,
	Entity& enemy,
	std::unordered_map<int, Battle_Action*>& battle_action_by_id,
	std::vector<Entity>& entities)
{
	if (battle_action_by_id.contains(battle_action_id))
	{
		auto& battle_action = battle_action_by_id[battle_action_id];
		if (battle_action->target == "opponent")
		{
			int clear_damage = (player.stats.damage * player.inventory->selected_item->damage) * battle_action->damage - enemy.stats.resist;
			if (clear_damage > 0)
			{
				enemy.stats.health -= clear_damage;
			}
			player.stats.movement -= battle_action->movement;
		}
		else
		{
			if (player.stats.health < entities.at(player.id).stats.health)
			{
				player.stats.health += battle_action->health;
			}
			player.stats.resist += battle_action->resist;
			player.stats.movement -= battle_action->movement;
		}
	}
	else
	{
		std::cout << "Nothing happend";
		player.stats.movement -= 1;
	}
}

void enemy_move(
	Player& player,
	Entity& enemy)
{
	int clear_damage = enemy.stats.damage - player.stats.resist;
	if (clear_damage > 0)
	{
		player.stats.health -= clear_damage;
	}
	enemy.stats.movement -= 1;
}

void battle(
	Player& player,
	Entity enemy,
	std::unordered_map<int, Battle_Action*>& battle_action_by_id,
	std::vector<Entity>& entities)
{	
	int battle_action_id;
	while (player.stats.health > 0 && enemy.stats.health > 0)
	{
		write_battle_frame(player, enemy, battle_action_by_id);

		while (player.stats.movement > 0 && enemy.stats.health > 0)
		{
			std::cin >> battle_action_id;

			player_move(battle_action_id, player, enemy, battle_action_by_id, entities);

			write_battle_frame(player, enemy, battle_action_by_id);
		}

		if (enemy.stats.health <= 0 || player.stats.health <= 0)
		{
			player.stats.resist = entities.at(player.id).stats.resist;
			player.stats.movement = entities.at(player.id).stats.movement;
			break;
		}

		while (enemy.stats.movement > 0)
		{
			enemy_move(player, enemy);

			write_battle_frame(player, enemy, battle_action_by_id);
		}

		player.stats.resist = entities.at(player.id).stats.resist;
		player.stats.movement = entities.at(player.id).stats.movement;
		enemy.stats.movement = entities.at(enemy.id).stats.movement;
		wait_for_enter();
	}
}
