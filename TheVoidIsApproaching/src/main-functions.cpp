#include "main-functions.hpp"

#include <iostream>

void complete_interaction(Interaction& interaction,
	std::unordered_map<int, Action*>& actions_by_id,
	std::unordered_map<std::string, std::function<void()>>& commands_by_type,
	std::unordered_map<std::string, std::function<void(int, int)>>& inventory_change_commands,
	std::unordered_map<std::string, std::function<void(int, int, int, int)>>& exchange_command)
{
	for (const int& action_id : interaction.actions_id)
	{
		if (actions_by_id.contains(action_id))
		{
			Action* action = actions_by_id[action_id];
			if (commands_by_type.contains(action->type))
			{
				commands_by_type[action->type]();
			}
			if (inventory_change_commands.contains(action->type))
			{
				inventory_change_commands[action->type](interaction.item_args.at(0), interaction.item_args.at(1));
			}
			if (exchange_command.contains(action->type))
			{
				exchange_command[action->type](interaction.item_args.at(0), interaction.item_args.at(1), interaction.item_args.at(2), interaction.item_args.at(3));
			}
		}
	}
}
