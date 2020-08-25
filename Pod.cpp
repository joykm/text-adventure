/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Pod implementation file.
*********************/

#include "Pod.hpp"

/*********************
**Description: Constructor; sets name of room.
*********************/
Pod::Pod(std::string name)
{
    this->name = name;
}

/*********************
**Description: performs special function for pod.
*********************/
void Pod::doSpecial()
{
    insertModule();
}

/*********************
**Description: keeps track that power module has been inserted
*********************/
void Pod::insertModule()
{
    power = true;
}

/*********************
**Description: checks status of power on ship
*********************/
bool Pod::getPowerStatus()
{
    return power;
}

/*********************
**Description: returns special options to take.
*********************/
std::string Pod::getSpecial()
{
    if (power == false)
    {
        return "  (a)ction - take a spin in the new whip";
    }
    else
    {
        return "";
    }
}
