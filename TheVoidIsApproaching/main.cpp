#include "json-loader.h"
#include "classes.h"
#include <iostream>
#include <string>

int main() 
{
    // Remove later to file, that start and run game
    auto locations =    locations_loader("Json-Files/locations.json");
    auto interactions = interactions_loader("Json-Files/interactions.json");
    Player player(&locations.at(0));


    // This is test of program. Remove later
    std::string command,location_name = "";

    for (int i = 0; i < 3; i++)
    {
        std::cout << "day" << i << std::endl;

        std::cin >> command;

        if (command == "location-info")
        {
            std::cout << player.get_location()->get_name();
        }
        else if (command == "change-location")
        {
            std::cin >> location_name;

            for (Location& location : locations)
            {
                if (location.get_name() == location_name)
                {
                    player.set_location(&location);
                    std::cout << "Location changed to " << location_name;
                }
            }
        }
        else
        {
            std::cout << "unknown command";
        }

        std::cout << std::endl;
    }
}
