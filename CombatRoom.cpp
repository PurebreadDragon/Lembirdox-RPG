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
    bool combatDone = false;
    std::string combatDoneDescription;

public:
    CombatRoom(std::string name, std::string description, std::string combatDoneDescription) : Room(name, description){
        this->combatDoneDescription = combatDoneDescription;
    }

    ~CombatRoom(){
        for (auto e : entities) delete e;
        entities.clear();
    }

    /**
     * interact: Combat method. 
     * This is where combat is handled. more details to come when entity is finished
     * args: none
     * outputs: none
     * */
    void interact(){
        // Run the combat. This only happens once, win or lose. 
        if (!combatDone){
            printDescription();

            player->initializeOrigStats();
            for (auto e : entities) e->initializeOrigStats();

            int goldReward = 0, expReward = 0, turn = 1;
            while (!combatOver()){
                updateTurn();
                printTurnBar();
                
                // execute player turn, if it is their turn
                if (player->getTurnBar() >= MAX_TURN_BAR){
                    std::cout << "================================[TURN " << turn << "]===============================\n";
                    player->printSpecialFeature();
                    player->turn(entities);
                    player->updateBuffs();
                    player->setTurnBar(player->getTurnBar() - MAX_TURN_BAR);
                    std::cout << "================================[TURN " << turn << "]===============================\n";
                    turn++;
                }

                // check if anything died, remove them from the vector if so and accumulate gold/xp reward
                std::vector<Enemy*>::iterator iter;
                for (iter = entities.begin(); iter != entities.end(); /* nothing */ ) {
                    if (!(*iter)->isAlive()){
                        std::cout << (*iter)->getDeathMessage() << "\n";
                        goldReward += (*iter)->getGoldReward();
                        expReward += (*iter)->getExpReward();
                        delete (*iter);
                    }
                    else ++iter;
                }

                // execute any enemy turns
                for (auto e : entities){
                    if (e->getTurnBar() >= MAX_TURN_BAR){
                        e->turn(player);
                        e->updateBuffs();
                        e->setTurnBar(e->getTurnBar() - MAX_TURN_BAR);
                    }
                }
            }

            // if the player won the combat
            if (player->isAlive()){
                std::cout << "You receive " << goldReward << " gold and " << expReward << " experience.\n";
                player->addGold(goldReward);
                player->addExp(expReward);
                combatDone = true; //we don't set this to true if the player died. they can return?
                player->clearBuffs();
            } else {
                std::cout << "You died.\n";
                end = true;
                player->deathPenalty();
            }
        } else {
            std::cout << combatDoneDescription << "\n";
        }
    }

    /**
     * printTurnBar: Prints out the current state of the turn bar and all entities' position on the turn bar. 
     * args: none
     * outputs: none
     * */
    void printTurnBar(){
        // print header
        std::cout << "NAME\t\t\t00%-----25%------50%------75%-----100%\n"
                         "\t\t\t[        |        |        |        ]\n";
        
        // print adventurer info
        std::string tempName = player->getName();
        std::cout << resize(tempName, 16) << " (" << player->getTurnBar() / 10 << "%)\t[";
        for (int k = 0; k < floor((double)std::min(player->getTurnBar(), MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
        std::cout << "o";
        for (int k = 0; k < TURN_BAR_LENGTH - floor((double)std::min(player->getTurnBar(), MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
        std::cout << "] (" << player->getCurrentHealth() << "/" << player->getMaxHealth() << ")\t";
        player->displayBuffs();
        std::cout << "\n";

        // print enemy info
        for (auto e : entities){
            // print name
            tempName = e->getName();
            // print turn percentage
            std::cout << resize(tempName, 16) << " (" << e->getTurnBar() / 10 << "%)\t[";
            // print turn bar
            for (int k = 0; k < floor((double)std::min(e->getTurnBar(), MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
            std::cout << "o";
            for (int k = 0; k < TURN_BAR_LENGTH - floor((double)std::min(e->getTurnBar(), MAX_TURN_BAR) / MAX_TURN_BAR * TURN_BAR_LENGTH); ++k) std::cout << "-";
            // print health
            std::cout << "] (" << e->getCurrentHealth() << "/" << e->getMaxHealth() << ")\t";
            // print buffs
            e->displayBuffs();
            std::cout << "\n";
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
        // for (auto e : entities){
        //     if (e->getTurnBar() >= MAX_TURN_BAR) e->setTurnBar(0);
        // }

        // if (player->getTurnBar() >= MAX_TURN_BAR) player->setTurnBar(0);

        // loop through all entities and update their turn bars until somebody reaches maximum. 
        bool reachedEnd = false;
        while (!reachedEnd){
            player->addTurnBar(player->getSpeed());
            if (player->getTurnBar() >= MAX_TURN_BAR) reachedEnd = true;

            for (auto e : entities){
                if (e->isAlive()){
                    e->addTurnBar(e->getSpeed());
                    if (e->getTurnBar() >= MAX_TURN_BAR) reachedEnd = true;
                }
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
        if (player->getCurrentHealth() < 0) return true;

        bool over = true;
        for (auto e: entities){ // check if each enemy is alive
            if (e->getCurrentHealth() > 0) over = false;
        }
        
        return over;
    }
};