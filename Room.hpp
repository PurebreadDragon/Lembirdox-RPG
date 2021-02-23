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
    interact(): this method is called whenever the user wants to interact with the room. Should be called during normal traversal
    args: none
    outputs: none
    */
    void interact(){
        std::cout << "";
    };

    /*
    addExit: this method adds an exit to the room. It automatically assigns it a numerical label based on the 
    args: r (the room to be added)
    outputs: none
    */
    void addExit(Room r){
        exits.push_back(r);
        exitLabels.push_back(std::to_string(exits.size()));
    }

    /*
    addExit: same as above except it adds a string label for the exit. Use if you want to label exits
    args: r (the room to be added), l (the label for the exit)
    outputs: none
    */
    void addExit(Room r, std::string l){
        exits.push_back(r);
        exitLabels.push_back(l);
    }

    /*
    getExit: takes in an input label. Returns the matching room if one exists, prints an error if otherwise
    args: input (the label for the room we want to search for)
    outputs: the desired room. Returns nullptr if nothing is found
    */
    Room* getExit(std::string input){
        for (int i = 0; i < exitLabels.size(); ++i){
            if (exitLabels.at(i) == input) return exits.at(i);
        }
        std::cout << "Invalid exit. Please try again.\n";
        return nullptr;
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