/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Player header file.
*********************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Item.hpp"
#include "Space.hpp"
#include <vector>
#include <memory>

class Player
{
    public:

        void setCurrentRoom(std::shared_ptr<Space>);
        std::shared_ptr<Space> getCurrentRoom();

        std::vector<Item> getDuffle();
        void pickupItem(Item*);
        int moveTo(std::string);

        int performAction(std::string);

    protected:

    private:
        bool crowbar = false;
        bool powerModule = false;
        std::vector<Item> duffle;
        std::shared_ptr<Space> currentRoom;
};

#endif // PLAYER_HPP
