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
    std::vector<Entity> entities;
    std::vector<int> turnBar;

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

        std::cout << "Calculating next turn\n";
        updateTurn();
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


    }

    /**
     * printTurnBar: Prints out the current state of the turn bar and all entities' position on the turn bar. 
     * args: none
     * outputs: none
     * */
    void printTurnBar(){
        std::cout << "NAME\t\t00%-----25%------50%------75%-----100%\n"
                         "\t\t[        |        |        |        ]\n";
        for (int i = 0; i < entities.size(); i++){
            std::cout << entities[i].getName().substr(0, 8) << " (" << turnBar[i] / 10 << "%)\t[";
            for (int k = 0; k < floor((double)std::min(turnBar[i], MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
            std::cout << "o";
            for (int k = 0; k < TURN_BAR_LENGTH - floor((double)std::min(turnBar[i], MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
            std::cout << "]\n";
        }
    }

    /**
     * addEntity: This method adds an entity to the room. Use this to populate a combat room with enemies. 
     * It pushes back a 0 into the turnBar vector to represent that unit's turn bar. 
     * args: e (the enemy to be added)
     * outputs: none
     * */
    void addEntity(Entity& e){
        entities.push_back(e);
        turnBar.push_back(0);
    }

    /**
     * updateTurn: This method updates the action bars of all entities currently engaged in combat until one of them reaches 100% turn bar. 
     * 100% turn bar is denoted by an integer value.
     * args: none
     * outputs: none
     * */
    void updateTurn(){
        // go through and find if someone is above max turn bar. reset them to zero if so
        for (int i = 0; i < entities.size(); ++i) if (turnBar[i] >= MAX_TURN_BAR) turnBar[i] = 0;

        // loop through all entities and update their turn bars until somebody reaches maximum. 
        bool reachedEnd = false;
        while (!reachedEnd){
            for (int i = 0; i < entities.size(); ++i){
                turnBar[i] += entities[i].getSpeed();
                if (turnBar[i] >= MAX_TURN_BAR) reachedEnd = true;
            }
        }
    }

    /**
     * combatOver: checks if combat is done
     * Goes through all entities and checks if their health is higher than zero. 
     * *** PROBABLY NEEDS MORE IMPLEMENTATION ***
     * args: none
     * outputs: 
     * */
    bool combatOver(){
        /*bool over = true;

        for (const auto& entity : entities){
            if (entities.getHealth() > 0) over = false;
        }

        return over;*/
        return false;
    }
};