#ifndef __QUEST_CPP__
#define __QUEST_CPP__

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "./../headers/Room.hpp"
#include "./../headers/Factory.hpp"
#include "./CombatRoom.cpp"

class Quest{
private:
    std::string description;
    std::vector<Room*> map;
    Enemy* boss;
    unsigned int reward;
public:
    Quest();
    Quest(unsigned int r, Enemy* b, std::string d) { //reward, boss, and task passed in from Town
        RoomFactory factory;
        EnemyFactory enemies;

        reward = r;
        boss = b;
        description = d;

        unsigned mapSize = 5;
        map.clear();
        for (unsigned i = 0; i < mapSize; ++i) {
            map.push_back(factory.generate((rand() % NUM_AMBIENT_ROOMS) + 35001));
        }

        unsigned fightLocation = ((rand() % (mapSize - 1)) + 1);
        unsigned enemyLimit = ((rand() % 5) + 1); // 1 - 5 enemies
        delete map.at(fightLocation);
        CombatRoom* arena = new CombatRoom("Arena","You enter a small room and are ambushed by enemies!","With the enemies slain, you can carry on.");
        for (unsigned i = 0; i < enemyLimit; ++i) {
            arena->addEnemy(enemies.generate((rand() % NUM_ENEMIES) + 10001));
        }
        map.at(fightLocation) = arena;

        unsigned oddLocation = ((rand() % (mapSize - 1)) + 1);
        delete map.at(oddLocation);
        map.at(oddLocation) = factory.generate((rand() % 4) + 30001);

        unsigned bossAllies = ((rand() % 4) + 2); // 2 - 6 enemies (+ boss)
        CombatRoom* bossRoom = new CombatRoom("Boss Arena","You enter an arena and stare down the enemy you were tasked to defeat.","With your adversary defeated, it's only you in the arena now. You can go home.");
        for (unsigned i = 0; i < bossAllies; ++i) {
            bossRoom->addEnemy(enemies.generate((rand() % NUM_ENEMIES) + 10001));
        }
        bossRoom->addEnemy(boss);
        bossRoom->setEnd();
        delete map.at(mapSize - 1);
        map.at(mapSize - 1) = bossRoom;

        for (unsigned i = 0; (i + 1) < mapSize; ++i) {
            map.at(i)->addExit(map.at(i+1));
        }
        map.shrink_to_fit();
    }

    ~Quest() {
        for (unsigned int i = 0; i < map.size(); ++i) {
            delete map.at(i);
        }
    }

    /**
     * linkPlayers(): this function links the player to all rooms in the quest.
     * args: p (the player to be linked)
     * outputs: none
     * */ 
    void linkPlayers(Adventurer* p) {
        for (unsigned i = 0; i < map.size(); ++i) {
            map.at(i)->linkPlayer(p);
        }
    }

    /**
     * getBeginning(): this function returns the start of the quest room.
     * This always gets the first value in the map vector, so you should always push the beginning first.
     * Use this to start a new quest from the town interface.
     * args: none
     * outputs: a pointer to the start of the quest
     * */
    Room& getBeginning(){
        return *map[0];
    }

    /**
     * addRoom(Room*): this function adds a new room to the quest.
     * args: r (the room to be added)
     * outputs: none
     * */
    void addRoom(Room* r){
        map.push_back(r);
    }

    /**
     * oneWayLink(int, int): this method links 2 rooms in the map with each other.
     * It creates a one-way exit between the first room and the second. 
     * Indices start at 0. So the first pushed room has index 0, second has index 1, etc. 
     * args: index1 (the origin room), index2 (the destination room)
     * outputs: none
     * */
    void oneWayLink(int index1, int index2){
        if ((index1) > map.size() || (index2) > map.size()){
            std::cout << "Something went wrong. This room linkage is invalid.\n";
        } else {
            map[index1]->addExit(map[index2]);
        }
    }

    /**An alternate version of the above method that creates a two-way exit instead.*/
    void twoWayLink(int index1, int index2){
        if ((index1 + 1) > map.size() || (index2 + 1) > map.size()){
            std::cout << "Something went wrong. This room linkage is invalid.\n";
        } else {
            map[index1]->addExit(map[index2]);
            map[index2]->addExit(map[index1]);
        }
    }

    /**Returns the spoils of war.*/
    int getReward(){
        return reward;
    }

    //testing function just to make sure stuff saved
    void showQuestContent() {
        std::cout << "Quest description: " << description << boss->getName() << std::endl;
        std::cout << "Quest boss:" << std::endl;
        boss->inspect(); std::cout << std::endl;
        std::cout << "Quest reward: " << reward << " gold" << std::endl;
    }
};

#endif
