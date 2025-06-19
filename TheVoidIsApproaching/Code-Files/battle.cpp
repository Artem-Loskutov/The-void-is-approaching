#include "battle.h"

#include <iostream>

void hit(Entity& entity, int damage)
{
	int clear_damage = entity.get_attr()["block"] - damage;
	entity.change_attr("hp", clear_damage);
}
void block(Entity& entity)
{
	entity.change_attr("block", 1);
}
void heal(Entity& entity)
{
	entity.change_attr("hp", 1);
}

void battle(Entity& player, Entity enemy)
{
	int action_id;

	while (player.get_attr()["hp"] > 0 && enemy.get_attr()["hp"] > 0)
	{
		std::cout << "choose action\n";
		std::cin >> action_id;

		switch (action_id)
		{
		case 0:
			hit(enemy, player.get_attr()["damage"]);
			break;
		case 1:
			block(player);
			break;
		case 2:
			heal(player);
			break;
		case 3:
			break;
		default:
			std::cout << "incorrect action";
			break;
		}

		if (enemy.get_attr()["hp"] <= 0 || action_id == 3) { break; }

		std::cout << enemy.name << " attack.\n";
		hit(player, enemy.get_attr()["damage"]);

		if (action_id == 1) { player.change_attr("block", -1); }
	}
	std::cout << "Battle end.\n";
}
