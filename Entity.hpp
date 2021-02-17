#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity{
private:
    std::string name;
public:
    virtual ~Entity() = default;
};

#endif