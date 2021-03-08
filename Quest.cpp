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
        delete boss;
        for (unsigned int i = 0; i < map.size(); ++i) {
            delete map.at(i);
        }
    }

    unsigned int getReward() { return reward; }
    std::string getTask() { return description; }
    Entity* getBoss() { return boss; }

    //testing function just to make sure stuff saved
    void showQuestContent() {
        std::cout << "Printing description and boss->getName()\n";
        std::cout << "Quest description: " << description << boss->getName() << std::endl;
        std::cout << "Printing quest boss and boss->inspect()\n";
        std::cout << "Quest boss:" << std::endl;
        boss->inspect(); std::cout << std::endl;
        std::cout << "Printing reward\n";
        std::cout << "Quest reward: " << reward << " gold" << std::endl;
    }
};
