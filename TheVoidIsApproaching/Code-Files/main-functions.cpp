#include "main-functions.h"

#include <unordered_map>
#include <functional>
#include <iostream>

void complete_interaction(Player& player, Interaction* interaction,
	std::unordered_map<int, Action*> actions_by_id, std::unordered_map<std::string, std::function<void()>> commands_by_type)
{
	const auto& interactions = player.get_location()->get_interactions();	//Vector of interactions of this location

	if (std::find(interactions.begin(), interactions.end(), interaction->get_id()) != interactions.end())	//If interaction in this location exists
	{
		std::cout << interaction->get_text() << std::endl;

		for (const int& action_id : interaction->get_actions())
		{
			if (actions_by_id.contains(action_id))
			{
				Action* action = actions_by_id[action_id];
				if (commands_by_type.contains(action->get_type()))
				{
					commands_by_type[action->get_type()]();
				}
			}
		}
	}
	else
	{
		std::cout << "interaction not completable";
	}
}
