#pragma once

#include <unordered_map>

class Inventory
{
private:
	std::unordered_map<int, int> inventory;
public:
	void add_item(int);
	void remove_item(int);
	void check();
};
