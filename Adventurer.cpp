#include <iostream>
#include <string>
#include <vector>
#include "Item.hpp"
#include "Entity.hpp"

class Adventurer : public Entity{
private:
    std::vector<Item> inventory;
    int experience, level;

public:
    Adventurer(std::string name, std::string description, int maxHealth, int physAtk, int physDef, int magAtk, int magDef, int speed) {
        this->name = name;
        this->description = description;
        this->maxHealth = maxHealth;
        health = maxHealth;
        this->physAtk = physAtk;
        this->physDef = physDef;
        this->magAtk = magAtk;
        this->magDef = magDef;
        this->speed = speed;
        turnBar = 0;
    }

    /**printAbilities(): This 
     * */
    void printAbilities(){
        std::cout << "Your available abilities are:";
    }
};