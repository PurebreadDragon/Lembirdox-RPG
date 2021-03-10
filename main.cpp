/*	 _    ___  __ __  __   _  ___  __   ___ __  __
 *	| |  | __||  |  || _\ | || _ ||  \ |   |\ \/ /
 *	| |_ | _| | |_| || _ || ||  | | | || | | |  |
 *	|___||___||_| |_||___||_||_|_||__/ |___|/_/\_\
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Room.hpp"
#include "CombatRoom.cpp"
#include "OddityRoom.cpp"
#include "Item.hpp"
#include "Town.hpp"
#include "Factory.hpp"
#include "InputReader.cpp"
#include "Warrior.cpp"
#include "Wizard.cpp"
#include "Samurai.cpp"

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
    srand(time(0));
    InputReader reader;
    EnemyFactory enemies; //Use these factories with the generate(id) function.
    ItemFactory items;
    RoomFactory rooms;

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
                  << "1:\tWarrior: A physical class focused around being able to take a lot of hits and dish out a lot of damage.\n"
                  << "2:\tWizard: A magical class with powerful area of effect damage and control abilities.\n"
                  << "3:\tSamurai: A physical class focused around lightning fast speed, rapid strikes and keeping the flow of combat.\n";
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
        case 1: player = new Warrior(playername, "It's you!"); break;
        case 2: player = new Wizard(playername, "It's you!"); break;
        case 3: player = new Samurai(playername, "It's you!"); break;
    }

    // build all room objects
    Room *tree = new Room("tree", "This is the entrance to the dungeon. This room has a large dead tree in it. The dry leaves underneath make a satisfying *crunch* as you walk over them.");
    Room *pool = new Room("pool", "The air in this room is a bit damp. Soft green moss grows underneath your feet. In the center of the room is a large pool.");
    CombatRoom *arena = new CombatRoom("arena", "You're standing in a large open arena. Two skeletons stare you down menacingly. You ready your weapon.", "You're standing in a large open arena. It's empty.");
    Skeleton* skelly = new Skeleton();
    // BigRat* ratticus = new BigRat();
    GrowSlime* growslime = new GrowSlime();
    // TrainingDummy* dummy = new TrainingDummy();
    StrangeFairy* fairy = new StrangeFairy();
    ShieldSkeleton* shieldSkelly = new ShieldSkeleton();
    arena->addEnemy(skelly);
    // arena->addEnemy(ratticus);
    // arena->addEnemy(growslime);
    arena->addEnemy(fairy);
    arena->addEnemy(skelly);
    arena->addEnemy(shieldSkelly);
    arena->linkPlayer(player);
    GoldStatueRoom *goldstatue = new GoldStatueRoom();
    goldstatue->linkPlayer(player);
    DartTrapRoom *darttrap = new DartTrapRoom();
    darttrap->linkPlayer(player);
    CatRoom *catroom = new CatRoom();
    catroom->linkPlayer(player);
    MirrorRoom* mirror = new MirrorRoom();
    mirror->linkPlayer(player);
    CombatRoom *boss = new CombatRoom("boss", "It's the boss room. There's a big slime in it.", "It's the boss room. The boss is dead.");
    boss->addEnemy(growslime);
    boss->linkPlayer(player);

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

    Town* testTown = new Town();
    Room* currentRoom;
    Quest* currentQuest = new Quest(500, growslime, "Defeat the evil grow slime");
    currentQuest->addRoom(tree); //0
    //currentQuest->addRoom(cave); //1
    currentQuest->addRoom(mirror); //1, but only because I can't link 7 it seems
    currentQuest->addRoom(darttrap); //2
    currentQuest->addRoom(arena); //3
    currentQuest->addRoom(catroom); //4
    currentQuest->addRoom(goldstatue); //5
    currentQuest->addRoom(pool); //6
    boss->setEnd();
    currentQuest->addRoom(boss); //7
    currentQuest->oneWayLink(0, 1);
    currentQuest->oneWayLink(1, 2);
    currentQuest->oneWayLink(2, 3);
    currentQuest->oneWayLink(3, 4);
    currentQuest->oneWayLink(3, 5);
    currentQuest->oneWayLink(4, 5);
    currentQuest->oneWayLink(5, 6);
    currentQuest->oneWayLink(6, 7); 
    currentRoom = &currentQuest->getBeginning();

    while (true){
        // roam the town. get a new quest and start it
        // Quest* currentQuest = testTown->RoamTown();
        Quest* newQuest = testTown->RoamTown(player);

	if (newQuest == nullptr){
		std::string temp;
		std::cout << "Thanks for playing!\n";
		cin >> temp;
		delete newQuest;
		break;
	}

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

    delete fairy;
    delete shieldSkelly;
    delete skelly;
    //delete growslime;
    delete currentQuest;
    delete player;
    delete testTown;
    return 0;
}
