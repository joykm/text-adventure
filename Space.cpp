/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Space implementation file.
*********************/

#include "Space.hpp"

/*********************
**Description: Space de constructor
*********************/
Space::~Space()
{

}

/*********************
**Description: Checks if an item exists on map
*********************/
int Space::itemExists(std::string item)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].getType() == item)
        {
            return 1;
        }
    }

    return 0;
}

/*********************
**Description: Adds an item to the map.
*********************/
void Space::addItem(Item *item)
{
    items.push_back(*item);
}

/*********************
**Description: Removes an item from the map.
*********************/
Item* Space::removeItem(std::string item)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].getType() == item)
        {
            Item temp(item);
            items.erase(items.begin() + i);
            return &temp;
        }
    }
}

/*********************
**Description: Prints available options for player to chose.
*********************/
int Space::getActions()
{
    std::string special = getSpecial();
    if (special != "")
    {
        std::cout << getSpecial() << std::endl;
    }
    else
    {
        return 0;
    }

    if (items.size() > 0)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getType() == "Crowbar")
            {
                std::cout << "  Pickup (c)rowbar" << std::endl;
            }

            if (items[i].getType() == "Power Module")
            {
                std::cout << "  Pickup (p)ower module" << std::endl;
            }
        }
    }
    return 1;
}

/*********************
**Description: Validates input.
*********************/
int Space::inputValidation(std::string input, int inputMin, int inputMax)
{
    while (input.length() != 1 || input[0] < inputMin || input[0] > inputMax)
    {
        std::cout << "Please enter a valid menu option: ";
        getline(std::cin, input);
        std::cout << std::endl;
    }

    int choice = atoi(input.c_str());
    return choice;
}

/*********************
**Description: Prints available directions to move
*********************/
void Space::getPortalOptions()
{
    if (north != nullptr)
    {
        std::cout << "  (n)orth" << std::endl;
    }

    if (south != nullptr)
    {
        std::cout << "  (s)outh" << std::endl;
    }

    if (east != nullptr)
    {
        std::cout << "  (e)ast" << std::endl;
    }

    if (west != nullptr)
    {
        std::cout << "  (w)est" << std::endl;
    }

    if (up != nullptr)
    {
        std::cout << "  (u)p" << std::endl;
    }

    if (down != nullptr)
    {
        std::cout << "  (d)own" << std::endl;
    }
}

/*********************
**Description: returns the name of the room
*********************/
std::string Space::getName()
{
    return name;
}

/*********************
**Description: sets north
*********************/
void Space::setNorth(std::shared_ptr<Space> north)
{
    this->north = north;
}

/*********************
**Description: sets south
*********************/
void Space::setSouth(std::shared_ptr<Space> south)
{
    this->south = south;
}

/*********************
**Description: sets east
*********************/
void Space::setEast(std::shared_ptr<Space> east)
{
    this->east = east;
}

/*********************
**Description: sets west
*********************/
void Space::setWest(std::shared_ptr<Space> west)
{
    this->west = west;
}

/*********************
**Description: sets up
*********************/
void Space::setUp(std::shared_ptr<Space> up)
{
    this->up = up;
}

/*********************
**Description: sets down
*********************/
void Space::setDown(std::shared_ptr<Space> down)
{
    this->down = down;
}

/*********************
**Description: returns north
*********************/
std::shared_ptr<Space> Space::getNorth()
{
    return north;
}

/*********************
**Description: returns south
*********************/
std::shared_ptr<Space> Space::getSouth()
{
    return south;
}

/*********************
**Description: returns east
*********************/
std::shared_ptr<Space> Space::getEast()
{
    return east;
}

/*********************
**Description: returns west
*********************/
std::shared_ptr<Space> Space::getWest()
{
    return west;
}

/*********************
**Description: returns up
*********************/
std::shared_ptr<Space> Space::getUp()
{
    return up;
}

/*********************
**Description: returns down
*********************/
std::shared_ptr<Space> Space::getDown()
{
    return down;
}
