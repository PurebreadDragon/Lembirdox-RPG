#include <iostream>
#include <string>
#include "Room.hpp"
#include "EmptyRoom.cpp"
#include "Item.hpp"

using namespace std;

int main(){
    Room* tree = new EmptyRoom("theres a tree");
    tree->interact();

    Item* stick = new Item("large stick", "it's a stick");
    stick->inspect();

    return 0;
}
