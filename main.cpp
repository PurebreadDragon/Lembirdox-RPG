#include <iostream>
#include <string>
#include "Room.hpp"
#include "EmptyRoom.cpp"
#include "Item.hpp"

using namespace std;

int main(){
    Room* tree = new Room("tree room", "theres a tree");
    tree->interact();

    Item* stick = new Item("large stick", "it's a stick");
    stick->inspect();

    Entity* joe = new Entity("joe", "average joe");
    joe->inspect();
    return 0;
}
