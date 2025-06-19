#include "main-functions.h"

#include <iostream>

void complete_interaction(Player& player, Interaction* interaction,
	std::unordered_map<int, Action*>& actions_by_id,
	std::unordered_map<std::string, std::function<void()>>& commands_by_type)
{
	const auto& interactions = player.get_location()->interactions_id;	//Vector of interactions of this location

	if (std::find(interactions.begin(), interactions.end(), interaction->id) != interactions.end())	//If interaction in this location exists
	{
		std::cout << interaction->text << std::endl;

		for (const int& action_id : interaction->actions_id)
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
	}
	else
	{
		std::cout << "interaction not completable";
	}
}
