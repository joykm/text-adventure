/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Item implementation file.
*********************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>


class Item
{
    public:
        Item(std::string);
        std::string getType();

    protected:

    private:
        std::string type;
};

#endif // ITEM_HPP
