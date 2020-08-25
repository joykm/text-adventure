/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Pod header file.
*********************/

#ifndef POD_HPP
#define POD_HPP
#include "Space.hpp"

class Pod : public Space
{
    public:
        Pod(std::string);
        void doSpecial();
        std::string getSpecial();

        void insertModule();
        bool getPowerStatus();

    protected:

    private:
        bool power = false;
};

#endif // POD_HPP
