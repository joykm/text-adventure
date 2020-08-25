/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Player implementation file.
*********************/

#include "Player.hpp"

/*********************
**Description: sets current room for player.
*********************/
void Player::setCurrentRoom(std::shared_ptr<Space> room)
{
    currentRoom = room;
}

/*********************
**Description: returns room player is in
*********************/
std::shared_ptr<Space> Player::getCurrentRoom()
{
    return currentRoom;
}

/*********************
**Description: returns players duffle bag
*********************/
std::vector<Item> Player::getDuffle()
{
    return duffle;
}

/*********************
**Description: picks up item, puts it into duffle bag.
*********************/
void Player::pickupItem(Item *type)
{
    duffle.push_back(*type);
}

/*********************
**Description: Performs action
*********************/
int Player::performAction(std::string choice)
{
    if (choice == "c" && getCurrentRoom()->itemExists("Crowbar") == 1)
    {
        pickupItem(getCurrentRoom()->removeItem("Crowbar"));
        return 1;
    }
    else if (choice == "c" && getCurrentRoom()->itemExists("Crowbar") == 0)
    {
        return 0;
    }
    else if (choice == "p" && getCurrentRoom()->itemExists("Power Module") == 0)
    {
        return 2;
    }
    else if (choice == "p" && getCurrentRoom()->itemExists("Power Module") == 1)
    {
        pickupItem(getCurrentRoom()->removeItem("Power Module"));
        return 1;
    }
    else if (choice == "a")
    {
        if(getCurrentRoom()->getName() == "Hatch Room")
        {
            for (int i = 0; i < duffle.size(); i++)
            {
                if(duffle[i].getType() == "Crowbar")
                {
                    crowbar = true;
                }
            }

            if (crowbar == false)
            {
                std::cout << "The hatch is stuck, you need to pry that some b open" << std::endl;
            }
            else
            {
                std::cout << "You popped the hatch open with the crowbar and in the process you hurt your hand. I hope you're happy." << std::endl;
                getCurrentRoom()->doSpecial();
            }

        }
        else if (getCurrentRoom()->getName() == "Escape Pod")
        {
            for (int i = 0; i < duffle.size(); i++)
            {
                if(duffle[i].getType() == "Power Module")
                {
                    powerModule = true;
                }
            }

            if (powerModule == false)
            {
                std::cout << "The escape pod has no gas man, you need yourself a power module" << std::endl;
            }
            else
            {
                std::cout << "We've got power baby, time to blow this joint!" << std::endl;
                getCurrentRoom()->doSpecial();
            }

        }
        else
        {
            getCurrentRoom()->doSpecial();
        }
        return 1; //Test
    }
    else
    {
        return 0;
    }
}

/*********************
**Description: moves player
*********************/
int Player::moveTo(std::string choice)
{
    if (choice == "n" && getCurrentRoom()->getNorth() != nullptr)
    {
        setCurrentRoom(getCurrentRoom()->getNorth());
        return 1;
    }
    else if (choice == "s" && getCurrentRoom()->getSouth() != nullptr)
    {
        setCurrentRoom(getCurrentRoom()->getSouth());
        return 1;
    }
    else if (choice == "e" && getCurrentRoom()->getEast() != nullptr)
    {
        setCurrentRoom(getCurrentRoom()->getEast());
        return 1;
    }
    else if (choice == "w" && getCurrentRoom()->getWest() != nullptr)
    {
        setCurrentRoom(getCurrentRoom()->getWest());
        return 1;
    }
    else if (choice == "u" && getCurrentRoom()->getUp() != nullptr)
    {
        setCurrentRoom(getCurrentRoom()->getUp());
        return 1;
    }
    else if (choice == "d" && getCurrentRoom()->getDown() != nullptr && getCurrentRoom()->getSpecial() != "  (a)ction - open hatch")
    {
        setCurrentRoom(getCurrentRoom()->getDown());
        return 1;
    }
    else if (getCurrentRoom()->getName() == "Hatch Room" && getCurrentRoom()->getSpecial() == "  (a)ction - open hatch")
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

