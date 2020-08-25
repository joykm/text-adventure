/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Room header file.
*********************/

#ifndef ROOM_HPP
#define ROOM_HPP
#include "Space.hpp"

class Room : public Space
{
    public:
        Room(std::string);
        void doSpecial();
        std::string getSpecial();

    protected:

    private:
};

#endif // ROOM_HPP
