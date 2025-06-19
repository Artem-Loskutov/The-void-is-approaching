#pragma once

#include <string>
#include <vector>

struct Location
{
	const int id;
	const std::string name;
	const std::vector<int> interactions_id;
};

struct Interaction
{
	const int id;
	const std::string text;
	const std::vector<int> actions_id;
};

struct Action
{
	const int id;
	const std::string type;
};
