#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity{
private:
    std::string name;
    int health, maxHealth, physAtk, physDef, magAtk, magDef, speed;

public:
    Entity(std::string name){
        this->name = name;
    };

    virtual ~Entity() = default;
};

#endif