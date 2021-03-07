#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Room.hpp"
#include "Entity.hpp"
#include "Enemy.cpp"

const int TURN_BAR_LENGTH = 34;
const int MAX_TURN_BAR = 1000;

class CombatRoom : public Room{
private:
    std::vector<Enemy*> entities;

public:
    CombatRoom(std::string name, std::string description) : Room(name, description){}

    /**
     * interact: Combat method. 
     * This is where combat is handled. more details to come when entity is finished
     * args: none
     * outputs: none
     * */
    void interact(){
        // Print out the description and begin combat.
        printDescription();

        // Turn bar display
        printTurnBar();

        // Pseudocode:
        // while (all enemies or players are alive)
            // while (it's not the player's turn)
                // updateTurn();
                // printTurnBar();
                // all entities that are at or above 100% turn bar take their action. 
            // now it's the player's turn. 
            // print out all the player's options
            // prompt the player for their action
            // prompt the player for their target
            // execute the action.
        int i = 0;
        while (!combatOver() && i < 5){
            updateTurn();
            printTurnBar();
            if (player->getTurnBar() >= MAX_TURN_BAR){
                player->turn(entities);
                player->setTurnBar(0);
            }
            for (auto e : entities){
                if (e->getTurnBar() >= MAX_TURN_BAR){
                    e->setTurnBar(0);
                    e->turn(player);
                }
            }
            ++i;
        }
    }

    /**
     * printTurnBar: Prints out the current state of the turn bar and all entities' position on the turn bar. 
     * args: none
     * outputs: none
     * */
    void printTurnBar(){
        // print header
        std::cout << "NAME\t\t00%-----25%------50%------75%-----100%\n"
                         "\t\t[        |        |        |        ]\n";
        
        // print adventurer info
        std::cout << player->getName().substr(0, 8) << " (" << player->getTurnBar() / 10 << "%)\t[";
        for (int k = 0; k < floor((double)std::min(player->getTurnBar(), MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
        std::cout << "o";
        for (int k = 0; k < TURN_BAR_LENGTH - floor((double)std::min(player->getTurnBar(), MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
        std::cout << "] (" << player->getCurrentHealth() << "/" << player->getMaxHealth() << ")\n";

        // print enemy info
        for (auto e : entities){
            std::cout << e->getName().substr(0, 8) << " (" << e->getTurnBar() / 10 << "%)\t[";
            for (int k = 0; k < floor((double)std::min(e->getTurnBar(), MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
            std::cout << "o";
            for (int k = 0; k < TURN_BAR_LENGTH - floor((double)std::min(e->getTurnBar(), MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
            std::cout << "] (" << e->getCurrentHealth() << "/" << e->getMaxHealth() << ")\n";
        }
    }

    /**
     * addEnemy: This method adds an enemy to the room. Use this to populate a combat room with enemies. 
     * args: e (the enemy to be added)
     * outputs: none
     * */
    void addEnemy(Enemy* e){
        entities.push_back(e);
    }

    /**
     * updateTurn: This method updates the action bars of all entities currently engaged in combat until one of them reaches 100% turn bar. 
     * 100% turn bar is denoted by an integer value.
     * args: none
     * outputs: none
     * */
    void updateTurn(){
        // go through and find if someone is above max turn bar. reset them to zero if so
        for (auto e : entities){
            if (e->getTurnBar() >= MAX_TURN_BAR) e->setTurnBar(0);
        }

        if (player->getTurnBar() >= MAX_TURN_BAR) player->setTurnBar(0);

        // loop through all entities and update their turn bars until somebody reaches maximum. 
        bool reachedEnd = false;
        while (!reachedEnd){
            player->addTurnBar(player->getSpeed());
            if (player->getTurnBar() >= MAX_TURN_BAR) reachedEnd = true;

            for (auto e : entities){
                e->addTurnBar(e->getSpeed());
                if (e->getTurnBar() >= MAX_TURN_BAR) reachedEnd = true;
            }
        }
    }

    /**
     * combatOver: checks if combat is done
     * Goes through all entities and checks if their health is higher than zero. 
     * Entities vector should never be empty when calling this method. 
     * args: none
     * outputs: whether or not combat is over
     * */
    bool combatOver(){
        bool over = true;

        if (player->getCurrentHealth() > 0){ // if the player is still alive
            for (auto e: entities){ // check if each enemy is alive
                if (e->getCurrentHealth() > 0) over = false;
            }
        }

        return over;
    }
};