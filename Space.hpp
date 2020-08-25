/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Space header file.
*********************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include "Item.hpp"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>

class Space
{
    public:
        ~Space();

        int inputValidation(std::string, int, int);

        void setNorth(std::shared_ptr<Space>);
        void setSouth(std::shared_ptr<Space>);
        void setEast(std::shared_ptr<Space>);
        void setWest(std::shared_ptr<Space>);
        void setUp(std::shared_ptr<Space>);
        void setDown(std::shared_ptr<Space>);

        void addItem(Item*);
        Item* removeItem(std::string);
        int itemExists(std::string);

        std::shared_ptr<Space> getNorth();
        std::shared_ptr<Space> getSouth();
        std::shared_ptr<Space> getEast();
        std::shared_ptr<Space> getWest();
        std::shared_ptr<Space> getUp();
        std::shared_ptr<Space> getDown();

        void getPortalOptions();
        int getActions();

        std::string getName();

        virtual void doSpecial() = 0;
        virtual std::string getSpecial() = 0;

    protected:
        std::vector<Item> items;
        std::string name;

        std::shared_ptr<Space> north = nullptr;
        std::shared_ptr<Space> south = nullptr;
        std::shared_ptr<Space> east = nullptr;
        std::shared_ptr<Space> west = nullptr;
        std::shared_ptr<Space> up = nullptr;
        std::shared_ptr<Space> down = nullptr;

    private:

};

#endif // SPACE_HPP
