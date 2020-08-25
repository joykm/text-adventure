/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Hatch header file.
*********************/

#ifndef HATCH_HPP
#define HATCH_HPP
#include "Space.hpp"

class Hatch : public Space
{
    public:
        Hatch(std::string);
        void doSpecial();
        std::string getSpecial();

        bool getHatchOpen();
        void openHatch();

    protected:

    private:
        bool hatchOpen = false;

};

#endif // HATCH_HPP
