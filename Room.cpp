/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Room implementation file.
*********************/

#include "Room.hpp"

/*********************
**Description: Constructor sets name of room
*********************/
Room::Room(std::string name)
{
    this->name = name;
}

/*********************
**Description: Does special function for standard room.
*********************/
void Room::doSpecial()
{
        std::cout << std::endl;
        std::cout << "You see that the far side of the space station is a blazing inferno... it gives you the willies." << std::endl;
        std::cout << "There is something odd about the flame that you just can't put a finger on..." << std::endl;
        std::cout << "You look a little longer before losing interest." << std::endl;
}

/*********************
**Description: Returns actions available it default rooms.
*********************/
std::string Room::getSpecial()
{
    return "  (a)ction - look out window";
}
