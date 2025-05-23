#pragma once

#include <vector>

#include "classes.h"

std::vector<Location> locations_loader(std::string path);
std::vector<Interaction> interactions_loader(std::string path);
