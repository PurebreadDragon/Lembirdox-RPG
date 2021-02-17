#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity{
private:
    std::string name;
    std::string description;
    int health, maxHealth, physAtk, physDef, magAtk, magDef, speed;

public:
    Entity(std::string name, std::string description){
        this->name = name;
        this->description = description;
    };

    void inspect(){
        std::cout << name << ": " << description << "\n";
    }

    virtual ~Entity() = default;
};

#endif