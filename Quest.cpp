#include <iostream>
#include <string>
#include <vector>
#include "Room.hpp"

class Quest{
private:
    std::string description;
    std::vector<Room*> map;
    Entity* boss;
    unsigned int reward;
public:
    Quest();
    Quest(unsigned int r, Entity* b, std::string d) { //reward, boss, and task passed in from Town
        reward = r;
        boss = b;
        description = d;
        map.resize(0);
    }
    ~Quest() {
        // delete boss;
        // for (unsigned int i = 0; i < map.size(); ++i) {
        //     delete map.at(i);
        // }
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
        if ((index1 + 1) > map.size() || (index2 + 1) > map.size()){
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
