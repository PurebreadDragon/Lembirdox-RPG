#include <iostream>
#include <string>
#include "Room.hpp"
#include "EmptyRoom.cpp"
#include "CombatRoom.cpp"
#include "Item.hpp"
#include "Town.hpp"

using namespace std;

int main(){
    Room* currentRoom; // master variable that tracks where we are

    // build some room objects
    // Room tree("tree", "This room has a large tree in it. Two openings lie in front of you. One leads to a room with a large pool of water in it. The other leads deeper into the cave.");
    // tree.interact();

    // Room pool("pool", "this room has a big pool");
    // tree.addExit(pool);
    // Room cave("cave", "this is a dark cave");
    // tree.addExit(cave);

    // // update the current room
    // currentRoom = &tree;
    // currentRoom->printExits();

    // Item stick("large stick", "it's a stick");
    // stick.inspect();

 /* Entity joe("Joe", "It's an average joe.", 200, 50, 30, 5, 30, 100);
    joe.inspect();

    Entity jill("Jill", "Joe's friend Jill", 150, 5, 5, 50, 50, 80);
    jill.inspect();

    Entity rat("Big rat", "Oh shit a rat", 20, 20, 5, 0, 5, 133);

    CombatRoom arena("arena", "You're standing in a large open arena. There's a big fuckin rat");
    arena.addEntity(joe);
    arena.addEntity(jill);
    arena.addEntity(rat);
    arena.interact();
    // This entire segment is hilarious XD
    */



    //Testing out my Town things :) Comment out if you need to.
    std::cout << "Constructing Town..." << std::endl;
    Town* testTown = new Town();
    
    testTown->RoamTown();
    //Town stuff ends here.

    return 0;
}
