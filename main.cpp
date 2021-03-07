/*	 _    ___  __ __  __   _  ___  __   ___ __  __
 *	| |  | __||  |  || _\ | || _ ||  \ |   |\ \/ /
 *	| |_ | _| | |_| || _ || ||  | | | || | | |  |
 *	|___||___||_| |_||___||_||_|_||__/ |___|/_/\_\
 */

#include <iostream>
#include <string>

#include "Room.hpp"
#include "CombatRoom.cpp"
#include "Item.hpp"
#include "Town.hpp"
#include "InputReader.cpp"

using namespace std;

  /* This is a draft of how the game will be expected to proceed.
   *  - If you have questions, ask the discord :)
   *  - If you have ideas, by all means, write them in <3
   *
   * Upon starting the program, the main menu should open.
   *  - The New Game option will be available.
   *  - If there is a save file, the Continue option will be available.
   *  - The High Scores option will be available :: IDEA FOR EXPANSION
   *  - The Quit option will be available.
   *
   * Upon pressing Continue, the game will load the current town from the available file.
   * Upon pressing New Game, the game will prompt the user to create the adventuring party.
   *  - The party can include up to (4?) characters.
   *  - Each character can be named.
   *  - Each character's class can be chosen.
   *  - After the party is created, the first Town is made.
   * 
   * Town is the "management" part of the game.
   *  - The Inn (Quest Board) option will be available.
   *  - The Store option will be available.
   * 	  - Items can be bought or sold to and from character's inventories.
   *  - The Clinic option will be available.
   * 	  - Characters at 0 HP can be brought back to life for a price.
   *  - The Embark option is only available after a Quest has been accepted.
   * 	  - This will move the player into the quest and delete the town.
   *  - The Save and Quit option will be available.
   * 	  - This will save:
   * 	      - the adventuring party (levels, names, inventories, classes)
   *          - the current Town (quest stubs, store inventory)
   *          - everything will be saved to its own file (name to be determined), overwriting contents
   *      - This will erase all currently allocated memory (memcheck-clean!)
   *      - and then will then close the game.
   * 
   * Questing is the "gameplay" part of the game.
   *  - I have no idea how the quests work lol
   *  - Upon finishing the quest, a new Town is made.
   */

int main() {
// rough draft of final project, feel free to add to it! Add your tests below this section please.
    


// ALL PERSONAL TESTING STUFFS SHOULD BE IMPLEMENTED BELOW THIS LINE

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

    CombatRoom *arena = new CombatRoom("arena", "You're standing in a large open arena. There's a skellington");
    Skeleton* skelly = new Skeleton();
    BigRat* ratticus = new BigRat();
    Adventurer* joe = new Adventurer("Joe", "You're an average joe.", 200, 30, 10, 30, 10, 100);
    arena->addEnemy(skelly);
    arena->addEnemy(ratticus);
    arena->linkPlayer(joe);
    pool->addExit(arena);
    arena->addExit(tree);

    DullBlade *dullBlade = new DullBlade();
    WindRazor *windRazor = new WindRazor();
    StickWand *stickWand = new StickWand();
    BasicPotion *potion = new BasicPotion();
    joe->addItem(dullBlade);
    joe->addItem(windRazor);
    joe->addItem(stickWand);
    joe->addItem(potion);
    joe->inspect();

    // update the current room
    currentRoom = tree;
    currentRoom->printExits();

    for (int i = 0; i < 5; ++i){
        std::cout << "Where would you like to go?\n";
        currentRoom = &(currentRoom->getExit(reader.readInput(currentRoom->getExitLabels())));
        currentRoom->interact();
        currentRoom->printExits();
    }

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

    //Testing out my Town things :) Comment out if you need to.
    // Town* testTown = new Town();
    // Quest* currentQuest = testTown->RoamTown();
    // delete testTown;
    // currentQuest->showQuestContent();
    // std::cout << "done displaying content!\n";
    // delete currentQuest;
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
