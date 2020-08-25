/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Hatch implementation file.
*********************/

#include "Hatch.hpp"
/*********************
**Description: Constructor sets name
*********************/
Hatch::Hatch(std::string name)
{
    this->name = name;
}

/*********************
**Description: Performs special function for Hatch
*********************/
void Hatch::doSpecial()
{
    openHatch();
}

/*********************
**Description: returns special function for hatch
*********************/
std::string Hatch::getSpecial()
{
    if (hatchOpen == false)
    {
        return "  (a)ction - open hatch";
    }
    else
    {
        return "";
    }
}

/*********************
**Description: checks if hatch is open
*********************/
bool Hatch::getHatchOpen()
{
    return hatchOpen;
}

/*********************
**Description: opens hatch
*********************/
void Hatch::openHatch()
{
    hatchOpen = true;
}
