#pragma once

#include <unordered_map>
#include "json-structs.hpp"

class Inventory
{
private:
	std::unordered_map<int, int> inventory;
public:
	Item* selected_item = nullptr;

	void add(int item_id, int count);
	bool remove(int item_id, int count);
	bool has(int item_id, std::unordered_map<int, Item*>& item_by_id);
	void print(std::unordered_map<int,Item*>& item_by_id);
	void select(std::string& item_name, std::unordered_map<int,Item*>& item_by_id);
};
