/*********************
**Program Name: Space Station Escape
**Author: Kevin Joy
**Date: 12/3/17
**Description: Main file for space station escape.
*********************/

#include <iostream>
#include "Player.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include "Hatch.hpp"
#include "Pod.hpp"

void setupGame(Player*);
void playGame(Player*);
int inputValidation(std::string, int, int);
std::string portalValidation(std::string);
std::string actionValidation(std::string);

/*********************
**Description: Main function.
*********************/
int main()
{
    Player player;
    setupGame(&player);
    playGame(&player);
}

/*********************
**Description: Sets up the game
*********************/
void setupGame(Player *player)
{
    //Create rooms
    std::shared_ptr<Space> quarters;
    quarters = std::make_shared<Room>("Quarters");

    std::shared_ptr<Space> hallway;
    hallway = std::make_shared<Room>("Hallway");

    std::shared_ptr<Space> tool;
    tool = std::make_shared<Room>("Maintenance");

    std::shared_ptr<Space> observation;
    observation = std::make_shared<Room>("Observation");

    std::shared_ptr<Space> science;
    science = std::make_shared<Room>("Science");

    std::shared_ptr<Space> hatch;
    hatch = std::make_shared<Hatch>("Hatch Room");

    std::shared_ptr<Space> pod;
    pod = std::make_shared<Pod>("Escape Pod");

    //Link rooms
    quarters->setEast(hallway);
    hallway->setWest(quarters);
    hallway->setSouth(tool);
    hallway->setNorth(observation);
    tool->setNorth(hallway);
    observation->setSouth(hallway);
    observation->setEast(science);
    observation->setNorth(hatch);
    science->setWest(observation);
    hatch->setSouth(observation);
    hatch->setDown(pod);
    pod->setUp(hatch);

    //Default room;
    Item crowbar("Crowbar");
    Item powerModule("Power Module");

    tool->addItem(&crowbar);
    science->addItem(&powerModule);

    //quarters->removeItem("Crowbar");
    player->setCurrentRoom(quarters);
}

/*********************
**Description: Plays the game
*********************/
void playGame(Player *player)
{
    std::cout << "<<<< Welcome to the Unitaris Space Station: >>>>" << std::endl;
    std::cout << std::endl;
    std::cout << "You've awakened to the sound of distant alarms." << std::endl;
    std::cout << "You need to work your way through the ship and find the escape pod." << std::endl;
    std::cout << "Go get 'em champ, I'm rooting for you." << std::endl;
    std::cout << "PS... There is a time limit but I'm not going to let you know it..." << std::endl;
    std::cout << std::endl;
    std::cout << "You are in " << player->getCurrentRoom()->getName() << ": " << std::endl;

    int i = 0;
    bool survived = false;
    while(i == 0)
    {
        for (int j = 0; j < 25; j++)
        {
            std::string input;
            std::cout << "What would you like to do?" << std::endl;
            std::cout << "1.) Move to another room" << std::endl;
            std::cout << "2.) Perform an action" << std::endl;

            std::cout << "Choice: ";
            getline(std::cin, input);
            std::cout << std::endl;

            int choice = inputValidation(input, 49, 50);

            if (choice == 1)
            {
                std::cout << "Doors: " << std::endl;
                player->getCurrentRoom()->getPortalOptions();

                std::cout << "Choice: ";
                getline(std::cin, input);
                std::cout << std::endl;

                int portalMove = player->moveTo(portalValidation(input));

                if (portalMove == 0)
                {
                    std::cout << "There isn't even a door there" << std::endl;
                    std::cout << std::endl;
                }
                else if (portalMove == 2)
                {
                    std::cout << "How are you going to get down the hatch when it's in the closed position? The corps issued you a rifle not a crowbar." << std::endl;
                    std::cout << std::endl;
                }

                std::cout << "You are in " << player->getCurrentRoom()->getName() << ": " << std::endl;
            }
            else if (choice == 2)
            {
                std::cout << "Actions: " << std::endl;
                int action = player->getCurrentRoom()->getActions();
                if (action == 0)
                {
                    std::cout << "  there are no actions left to perform in this room" << std::endl;
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Choice: ";
                    getline(std::cin, input);

                    int actionChoice = player->performAction(actionValidation(input));
                    std::cout << std::endl;

                    if (actionChoice == 0)
                    {
                        std::cout << "Are you done playing pretend with the imaginary crowbar?" << std::endl;
                        std::cout << std::endl;
                    }
                    else if (actionChoice == 2)
                    {
                        std::cout << "I don't see a power module. Do you see a power module?" << std::endl;
                        std::cout << std::endl;
                    }
                }
            }

            if (player->getCurrentRoom()->getName() == "Escape Pod" && player->getCurrentRoom()->getSpecial() == "")
            {
                i++;
                j = 35;
                survived = true;
                std::cout << "You see the space station blow to smithereens as you fly off sipping on a gin and tonic." << std::endl;
            }

        }
        if (survived == false)
        {
            std::cout << std::endl;
            std::cout << "You are dead. You are so dead. You didn't even see it coming and POW. Dead. Didn't stand a chance." << std::endl;
            i++;
        }
    }
}

/*********************
**Description: Validates first menu
*********************/
int inputValidation(std::string input, int inputMin, int inputMax)
{
    while (input.length() != 1 || input[0] < inputMin || input[0] > inputMax)
    {
        std::cout << "Please enter a valid menu option: ";
        getline(std::cin, input);
        std::cout << std::endl;
    }

    int choice = atoi(input.c_str());
    return choice;
}

/*********************
**Description: Validation movement inputs.
*********************/
std::string portalValidation(std::string input)
{
    while (input.length() != 1 || (input != "n" && input != "s" && input != "e" && input != "w" && input != "u" && input != "d"))
    {
        std::cout << "Please enter a valid menu option: ";
        getline(std::cin, input);
        std::cout << std::endl;
    }

    return input;
}

/*********************
**Description: Validates action inputs.
*********************/
std::string actionValidation(std::string input)
{
    while (input.length() != 1 || (input != "c" && input != "p" && input != "a"))
    {
        std::cout << "Please enter a valid menu option: ";
        getline(std::cin, input);
        std::cout << std::endl;
    }

    return input;
}
