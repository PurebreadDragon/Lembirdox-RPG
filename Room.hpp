#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "Adventurer.hpp"

class Room{
protected:
    std::string name;
    std::string description;
    int weight;
    std::vector<Room*> exits;
    std::vector<std::string> exitLabels;
    Adventurer* player;

public:
    virtual ~Room() = default;

    /**
     * Constructor
     * args: name (the name of the room), description (the description of the room)
     * */
    Room(std::string name, std::string description){
        this->name = name;
        this->description = description;
        weight = 0;
    }

    /**
     * Default constructor
     * Sets fields to empty strings
     * */
    Room(){
        name = "unknown";
        description = "";
        weight = 0;
    }

    /**
     * linkPlayer: links the player to this room so they can be interacted with
     * args: pointer to the player's object
     * outputs: none
     * */
    void linkPlayer(Adventurer* player){
        this->player = player;
    }

    /**
     * getName: gets the name
     * Usually used when displaying this room as a valid exit
     * args: none
     * outputs: a std::string containing the name
     * */
    std::string getName(){
        return name;
    }

    /**
     * interact(): this method is called whenever the user wants to interact with the room. Should be called during normal traversal
     * Redefine this method in child classes as they have unique functionality. 
     * args: none
     * outputs: none
     * */
    virtual void interact(){
        printDescription();
    };

    /**
     * addExit: this method adds an exit to the room. It automatically assigns it a numerical label based on the 
     * args: r (the room to be added)
     * outputs: none
     * */
    void addExit(Room* r){
        exits.push_back(r);
        exitLabels.push_back(std::to_string(exits.size()));
    }

    /**
     * addExit: same as above except it adds a string label for the exit. Use if you want to label exits
     * args: r (the room to be added), l (the label for the exit)
     * outputs: none
     * */
    void addExit(Room* r, std::string l){
        exits.push_back(r);
        exitLabels.push_back(l);
    }

    /**
     * getExit: takes in an input label. Returns the matching room if one exists, prints an error if otherwise
     * args: input (the label for the room we want to search for)
     * outputs: the desired room. Returns nullptr if nothing is found
     * */
    Room& getExit(std::string input){
        for (int i = 0; i < exitLabels.size(); ++i){
            if (exitLabels[i] == input) return *exits[i];
        }
        std::cout << "Invalid exit. Please try again.\n"; //theoretically you should never reach this
        //return NULL;
    }

    /**
     * This is an integer version of the above getExit. 
     * */
    Room& getExit(int input){
        for (int i = 0; i < exitLabels.size(); ++i){
            if (std::stoi(exitLabels[i]) == input) return *exits[i];
        }
        std::cout << "Invalid exit. Please try again.\n";
        //return NULL;
    }

    /**
     * printDescription: this method prints the room's description.
     * args: none
     * outputs: none
     * */
    void printDescription(){
        std::cout << description << "\n";
    }

    /**
     * printExits: this method prints out all available exits and their names.
     * args: none
     * outputs: none
     * */
    void printExits(){
        std::cout << "Available exits: \n";
        for (int i = 0; i < exits.size(); ++i){
            std::cout << exitLabels[i] << ":\t" << exits[i]->getName() << "\n";
        }
    }

    /**
     * getExitLabels: this method returns a vector containing all the exit labels. 
     * args: none
     * outputs: a std::vector<string> with all exit labels
     * */
    std::vector<std::string> getExitLabels(){
        return exitLabels;
    }

    /**
     * resize: This method resizes a string to a given length. Use for formatting
     * args: word (the string to be modified), length (the desired length)
     * outputs: the modified string
     * */
    std::string resize(std::string word, int length){
        if (word.length() == length) return word;
        if (word.length() > length) return word.substr(0, length);
        if (word.length() < length){
            while (word.length() < length){
                word += ' ';
            }
            return word;
        }
    }
};

#endif