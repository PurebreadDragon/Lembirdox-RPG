/*	 _    ___  __ __  __   _  ___  __   ___ __  __
 *	| |  | __||  |  || _\ | || _ ||  \ |   |\ \/ /
 *	| |_ | _| | |_| || _ || ||  | | | || | | |  |
 *	|___||___||_| |_||___||_||_|_||__/ |___|/_/\_\
 */

#include <iostream>
#include <string>

#include "Room.hpp"
#include "CombatRoom.cpp"
#include "OddityRoom.cpp"
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

    InputReader reader;

    // welome screen. prompt the user for their name and class selection
    std::string playername;
    int nameSelection = -1;
    while (nameSelection != 1){
        std::cout << "Enter your name. (No spaces)\n";
        std::cin >> playername;
        std::cout << "Is this what you want to be called? " << playername << "\n"
                << "1:\tYes\n"
                << "2:\tNo\n";
        int nameChoice[]{1, 2};
        nameSelection = reader.readInput(nameChoice, 2);
    }

    int classSelection = 2, pickedClass;
    while (classSelection == 2){
        std::cout << "Choose your class.\n"
                  << "1:\tWarrior\n"
                  << "2:\tWizard\n"
                  << "3:\tRogue\n";
        int classChoice[]{1, 2, 3};
        pickedClass = reader.readInput(classChoice, 3);

        std::cout << "Are you sure? You cannot change your choice later.\n"
                  << "1:\tYes\n"
                  << "2:\tNo\n";
        int nameChoice[]{1, 2};
        classSelection = reader.readInput(nameChoice, 2);
    }

    Adventurer *player;

    switch(pickedClass){
        case 1: player = new Adventurer(Warrior, playername, "It's you!"); break;
        case 2: player = new Adventurer(Wizard, playername, "It's you!"); break;
        case 3: player = new Adventurer(Rogue, playername, "It's you!"); break;
    }


// ALL PERSONAL TESTING STUFFS SHOULD BE IMPLEMENTED BELOW THIS LINE

    // Room *currentRoom; // master variable that tracks where we are

    // // build some room objects
    Room *tree = new Room("tree", "This room has a large tree in it. Two openings lie in front of you. One leads to a room with a large pool of water in it. The other leads deeper into the cave.");
    // tree->interact();

    Room *pool = new Room("pool", "The air in this room is a bit damp. Soft green moss grows underneath your feet. In the center of the room is a large pool.");
    pool->setEnd();
    // tree->addExit(pool);
    Room *cave = new Room("cave", "You proceed deeper into the cave.");
    // tree->addExit(cave);
    // pool->addExit(tree);
    // cave->addExit(tree); 

    CombatRoom *arena = new CombatRoom("arena", "You're standing in a large open arena. Two skeletons stare you down menacingly. You ready your weapon.", "You're standing in a large open arena. It's empty.");
    Skeleton* skelly = new Skeleton();
    // // BigRat* ratticus = new BigRat();
    // GrowSlime* growslime = new GrowSlime();
    ShieldSkeleton* shieldSkelly = new ShieldSkeleton();
    arena->addEnemy(skelly);
    // arena->addEnemy(ratticus);
    // arena->addEnemy(growslime);
    arena->addEnemy(shieldSkelly);
    arena->linkPlayer(player);
    // pool->addExit(arena);
    // arena->addExit(tree);
    GoldStatueRoom *goldstatue = new GoldStatueRoom();
    goldstatue->linkPlayer(player);
    DartTrapRoom *darttrap = new DartTrapRoom();
    darttrap->linkPlayer(player);
    CatRoom *catroom = new CatRoom();
    catroom->linkPlayer(player);
    // arena->addExit(goldstatue);
    // goldstatue->addExit(cave);
    // cave->addExit(darttrap);
    // darttrap->addExit(pool);
    // darttrap->addExit(catroom);
    // catroom->addExit(tree);

    DullBlade *dullBlade = new DullBlade();
    WindRazor *windRazor = new WindRazor();
    StickWand *stickWand = new StickWand();
    FlareOrb *flareOrb = new FlareOrb();
    BasicPotion *potion = new BasicPotion();
    DebuffStick *debuffstick = new DebuffStick();
    player->addItem(dullBlade);
    player->addItem(windRazor);
    player->addItem(stickWand);
    player->addItem(potion);
    player->addItem(flareOrb);
    player->addItem(debuffstick);
    // player->inspect();

    // // update the current room
    // currentRoom = tree;
    // currentRoom->printExits();

    // while (true){
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

    //Testing out my Town things :) Comment out if you need to.
    Town* testTown = new Town();
    Room* currentRoom;
    GrowSlime* growslime = new GrowSlime();
    Quest* currentQuest = new Quest(500, growslime, "Defeat the evil grow slime");
    currentQuest->addRoom(tree); //0
    currentQuest->addRoom(cave); //1
    currentQuest->addRoom(darttrap); //2
    currentQuest->addRoom(arena); //3
    currentQuest->addRoom(catroom); //4
    currentQuest->addRoom(goldstatue); //5
    currentQuest->addRoom(pool); //6
    currentQuest->oneWayLink(0, 1);
    currentQuest->oneWayLink(1, 2);
    currentQuest->oneWayLink(2, 3);
    currentQuest->oneWayLink(3, 4);
    currentQuest->oneWayLink(3, 5);
    currentQuest->oneWayLink(4, 5);
    currentQuest->oneWayLink(5, 6);
    currentRoom = &currentQuest->getBeginning();

    while (true){
        // roam the town. get a new quest and start it
        // Quest* currentQuest = testTown->RoamTown();
        Quest* newQuest = testTown->RoamTown();

        currentRoom = &currentQuest->getBeginning();
        while (true){
            currentRoom->interact();
            if (currentRoom->isEnd()) break;
            // ask the user for what they want to do
            int movementSelection = 0;
            while (movementSelection != 1){
                std::cout << "What would you like to do?\n"
                        << "1:\tContinue forward\n"
                        << "2:\tDisplay player info\n"
                        << "3:\tCheck inventory\n";
                int movementChoices[]{1, 2, 3};
                movementSelection = reader.readInput(movementChoices, 3);

                switch(movementSelection){
                    case 1:{ // the player chose to leave
                        std::cout << "Where would you like to go?\n";
                        currentRoom->printExits();
                        currentRoom = &(currentRoom->getExit(reader.readInput(currentRoom->getExitLabels())));
                    } break;
                    case 2:{
                        player->inspect();
                    } break;
                    case 3:{
                        player->checkInventory();
                    } break;
                }
            }
        }
    }
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
