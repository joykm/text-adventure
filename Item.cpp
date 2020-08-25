/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Item header file.
*********************/
#include "Item.hpp"

/*********************
**Description: Constructor sets item type
*********************/
Item::Item(std::string type)
{
    this->type = type;
}

/*********************
**Description: returns type of item.
*********************/
std::string Item::getType()
{
    return type;
}
