#include "inventory.hpp"

#include <iostream>

void Inventory::add(int item_id, int count)
{
	inventory[item_id] += count;
}

void Inventory::remove(int item_id, int count)
{
	inventory[item_id] -= count;
}

void Inventory::print(std::unordered_map<int, Item*>& item_by_id)
{
	for (auto& item : inventory)
	{
		std::cout << item_by_id[item.first]->name << " - " <<
			item.second << std::endl;
	}
}

void Inventory::select(std::string& item_name, std::unordered_map<int, Item*>& item_by_id)
{
	for (auto& item : inventory)
	{
		if (item_by_id[item.first]->name == item_name)
		{
			selected_item = item_by_id[item.first];
			break;
		}
	}
}
