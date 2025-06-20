#include "main-functions.hpp"

#include <iostream>

void complete_interaction(Interaction& interaction,
	std::unordered_map<int, Action*>& actions_by_id,
	std::unordered_map<std::string, std::function<void()>>& commands_by_type)
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
		}
	}

	std::cout << interaction.result << std::endl;
}
