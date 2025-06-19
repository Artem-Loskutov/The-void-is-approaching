#include "inventory-class.h"

#include <iostream>

void Inventory::add_item(int item_id)
{
    inventory[item_id] += 1;
}

void Inventory::remove_item(int item_id)
{
    if (inventory.contains(item_id))
    {
        int& item_quantity = inventory[item_id];
        if (item_quantity == 1)
        {
            inventory.erase(item_id);
        }
        item_quantity -= 1;
    }
}

void Inventory::check()
{
    if (inventory.size())
    {
        for (auto& item : inventory)
        {
            std::cout << item.first << " " << item.second;
        }
    }
    else
    {
        std::cout << "inventory is empty";
    }
}
