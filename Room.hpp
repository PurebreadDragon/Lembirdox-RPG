#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "Entity.hpp"

class Room{
protected:
    std::string description = "";
    int weight;
    std::vector<Room> exits;
    std::vector<std::string> exitLabels;

public:
    virtual ~Room() = default;

    /*
    interact(): this method happens when 
    */
    void interact(){
        std::cout << "";
    };

    /*
    addExit: this method adds an exit to the room 
    args: the room to be added
    outputs: none
    */
    void addExit(Room r){
        exits.push_back(r);
        exitLabels.push_back(std::to_string(exits.size()));
    }

    /*
    addExit: same as above
    args: r (the room to be added), l (the label for the exit)
    outputs: none
    */
    void addExit(Room r, std::string l){

    }

    /*
    printDescription: this method prints the room's description.
    args: none
    outputs: none
    */
    void printDescription(){
        std::cout << description << "\n";
    }
};

#endif