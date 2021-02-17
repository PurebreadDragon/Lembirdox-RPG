#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "Entity.hpp"

class Room{
protected:
    std::string description = "";
    int weight;

public:
    virtual ~Room() = default;
    virtual void interact() = 0;

    void printDescription(){
        std::cout << description << "\n";
    }
};

#endif