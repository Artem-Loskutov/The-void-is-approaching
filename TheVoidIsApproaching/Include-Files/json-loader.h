#pragma once

#include <vector>
#include "game-structs.h"
#include "entity-class.h"

std::vector<Location>		locations_loader		(std::string file_path);
std::vector<Interaction>	interactions_loader		(std::string file_path);
std::vector<Action>			actions_loader			(std::string file_path);
std::vector<Entity>			entities_loader			(std::string file_path);
