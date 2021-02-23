#include <iostream>
#include <string>
#include <vector>
#include "Room.hpp"

class EmptyRoom : public Room{
public:
    void interact(){
        printDescription();
    }
};