#include <iostream>
#include <string>
#include "Room.hpp"
#include "CombatRoom.cpp"
#include "Item.hpp"
#include "Town.hpp"
#include "InputReader.cpp"

using namespace std;

int main(){
    Room *currentRoom; // master variable that tracks where we are
    InputReader reader; // helper class that handles read/write

    // build some room objects
    Room *tree = new Room("tree", "This room has a large tree in it. Two openings lie in front of you. One leads to a room with a large pool of water in it. The other leads deeper into the cave.");
    tree->interact();

    Room *pool = new Room("pool", "The pool of water is very deep. Placeholder description");
    tree->addExit(pool);
    Room *cave = new Room("cave", "You proceed deeper into the cave. Placeholder description");
    tree->addExit(cave);
    pool->addExit(tree);
    cave->addExit(tree);

    // update the current room
    // currentRoom = tree;
    // currentRoom->printExits();

    // for (int i = 0; i < 5; ++i){
    //     std::cout << "Where would you like to go?\n";
    //     currentRoom = &(currentRoom->getExit(reader.readInput(currentRoom->getExitLabels())));
    //     currentRoom->interact();
    //     currentRoom->printExits();
    // }

    // Item stick("large stick", "it's a stick");
    // stick.inspect();

    // Entity joe("Joe", "It's an average joe.", 200, 50, 30, 5, 30, 100);
    // joe.inspect();

    // Entity jill("Jill", "Joe's friend Jill", 150, 5, 5, 50, 50, 80);
    // jill.inspect();

    // Entity rat("Big rat", "Oh shit a rat", 20, 20, 5, 0, 5, 133);

    // CombatRoom arena("arena", "You're standing in a large open arena. There's a big fuckin rat");
    // arena.addEntity(joe);
    // arena.addEntity(jill);
    // arena.addEntity(rat);
    // arena.interact();

    // CombatRoom arena("arena", "You're standing in a large open arena. There's a big fuckin rat");
    // arena.addEntity(joe);
    // arena.addEntity(jill);
    // arena.addEntity(rat);
    // arena.interact();



    //Testing out my Town things :) Comment out if you need to.
    std::cout << "Constructing Town..." << std::endl;
    Town* testTown = new Town();
    
    testTown->RoamTown();
    delete testTown;
    //Town stuff ends here.

    // InputReader reader;
    // std::cout << "You have 3 choices:\n"
    // "1: choice 1\n"
    // "2: choice 2\n"
    // "3: choice 3\n";
    // int choices[]{1, 2, 3};
    // std::cout << "User picked choice " << reader.readInput(choices, 3);
    return 0;
}
