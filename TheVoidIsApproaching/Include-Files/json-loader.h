#pragma once

#include "classes.h"

#include <vector>

std::vector<Location> locations_loader(std::string path);
std::vector<Interaction> interactions_loader(std::string path);
std::vector<Action> actions_loader(std::string path);
