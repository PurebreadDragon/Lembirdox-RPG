#include <iostream>
#include <string>
#include <vector>
#include "Room.hpp"

class EmptyRoom : public Room{
public:
    EmptyRoom(std::string description){
        this->description = description;
    }

    void interact(){
        printDescription();
    }
};