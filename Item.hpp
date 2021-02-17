#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item{
private:
    std::string name;
    std::string description;
    // implement attributes

public:
    Item(std::string name, std::string description){
        this->name = name;
        this->description = description;
    }

    void inspect(){
        std::cout << "=====" << name << "=====\n" << description << "\n=====================";
    }

    // implement ability if needed
};

#endif