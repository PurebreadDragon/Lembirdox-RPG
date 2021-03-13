/*	 _    ___  __ __  __   _  ___  __   ___ __  __
 *	| |  | __||  |  || _\ | || _ ||  \ |   |\ \/ /
 *	| |_ | _| | |_| || _ || ||  | | | || | | |  |
 *	|___||___||_| |_||___||_||_|_||__/ |___|/_/\_\
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "./../headers/Room.hpp"
#include "./CombatRoom.cpp"
#include "./OddityRoom.cpp"
#include "./../headers/Item.hpp"
#include "./../headers/Town.hpp"
#include "./../headers/Factory.hpp"
#include "./InputReader.cpp"
#include "./Warrior.cpp"
#include "./Wizard.cpp"
#include "./Samurai.cpp"
#include "./Oracle.cpp"
//#include "./Monk.cpp"

using namespace std;


//vim doesn't have cut/paste. Would you mind moving this definition down below main and uncommenting this declaration? Thank you <3
//Adventurer* CharacterGeneration();

Adventurer* CharacterGeneration() {
    InputReader reader;
    std::string playername = "";
    int nameSelection = -1;
    int twoChoice[]{1, 2};

    while (nameSelection != 1) {
        std::cout << "\nWhat is your name? (No spaces, please)\n";
        std::cin >> playername;
        std::cout << "\nYou want to be called " << playername << "?\n"
                  << "1.\tYes.\n"
                  << "2.\tNo.\n";
        nameSelection = reader.readInput(twoChoice, 2);
    }

    int classSelection = 2, pickedClass;
    while (classSelection == 2) {
        std::cout << "\nPlease choose your class.\n"
                  << "1.\tWarrior: A physical class that can soak up and dish out damage in equal measure.\n"
                  << "2.\tWizard: A magical class with many unique and devastating abilities.\n"
                  << "3.\tSamurai: A physical class that attacks fast and controls the tides of combat.\n"
                  << "4.\tOracle: A magical class that relies on the winds of fate to overwhelm their foes.\n";
                  //<< "5.\tMonk: A physical class that draws power from their vows to punish to their enemies.\n";
        int classChoice[]{1, 2, 3, 4};
        pickedClass = reader.readInput(classChoice, NUM_CLASSES);
        switch (pickedClass){
            case 1: std::cout << "Warriors are slow, heavy hitters with the ability to tank a lot of damage and dish it back. The warrior thrives in the thick "
                "of battle, facing off against hordes of enemies. The warrior's defining "
                "feature is Revenge. When taking damage, the Warrior gains a stack of Revenge. The maximum amount of Revenge stacks increases with "
                "level. For each stack of Revenge, the warrior takes less damage "
                "and deals additional damage on their next attack. Revenge enables the Warrior to tank hits and retaliate with crushing force.\n";
                break;
            case 2: std::cout << "Wizards are masters of the arcane arts, commanding power over the elements to channel them and unleash devastating "
                "area of effect abilities on multiple targets. Their control over magic is so great they can even manipulate the flow of time. "
                "The Wizard lacks in single target damage, but even when a Wizard is outnumbered, it is still "
                "an even fight.\n";
                break;
            case 3: std::cout << "Samurai are masters of the blade, with skills as sharp as the honed edge of their katana. The Samurai, unlike other classes, lacks "
                "damaging abilities. Instead, their basic attack is replaced with an Iai Slash, a sword strike that has a chance to critically strike, dealing "
                "double damage. Their critical strike chance is dependant upon their Ki, a resource which fills when performing a successful Iai Slash, but lowers "
                "when taking damage. To augment this, the Samurai has various abilities that increase the amount of times their Iai Slashes hit or can block "
                "incoming damage. Striking fast and often and carefully selecting targets to prevent incoming damage is critical to maintaining high Ki and damage output.\n";
                break;
            case 4: std::cout << "Oracles derive their power from the ebb and flow of fate, allowing them to"
                    " administer buffs, debuffs, deal incredible damage, and even manipulate the future itself to"
                    " bend the universe to their advantage. This class is somewhat frail and lacks physical "
                    "prowess, but to underestimate the capabilities of an Oracle is to face certain death.\n";
        }
        std::cout << "\nAre you sure? You cannot change this later.\n"
                  << "1.\tYes.\n"
                  << "2.\tNo.\n";
        classSelection = reader.readInput(twoChoice, 2);
    }

    Adventurer *player;
    switch(pickedClass){
        case 1: player = new Warrior(playername, "It's you!"); break;
        case 2: player = new Wizard(playername, "It's you!"); break;
        case 3: player = new Samurai(playername, "It's you!"); break;
        case 4: player = new Oracle(playername, "It's you!"); break;
    }
    return player;
}

//this one too <3
//void TraverseQuest(Quest* quest, Adventurer* player);

void TraverseQuest(Quest* quest, Adventurer* player) {
    InputReader read;
    Room* currentRoom = &quest->getBeginning();
    while (true) {
        currentRoom->interact();
        if (currentRoom->isEnd()) break;
        int movementSelection = 0;
        while (movementSelection != 1) {
            std::cout << "\nWhat would you like to do?\n"
                      << "1.\tContinue forward\n"
                      << "2.\tDisplay player info\n"
                      << "3.\tCheck inventory\n";
            int movementChoices[]{1, 2, 3};
            movementSelection = read.readInput(movementChoices,3); 
            switch (movementSelection) {
                case 1:
                    std::cout << "\nWhere would you like to go?\n";
                    currentRoom->printExits();
                    currentRoom = &(currentRoom->getExit(read.readInput(currentRoom->getExitLabels())));
                    break;
                case 2:
                    player->inspect();
                    break;
                case 3:
                    player->checkInventory();
                    break;
             }
        }
    }
    if (player->isAlive()) { currentRoom->interact(); } //player made it to boss fight
}

int main() {
    srand(time(0));
    unsigned long long score = 0;

    std::cout << "\nWelcome!\n";
    Adventurer* player = CharacterGeneration();

    Town* currentTown = new Town();
    Quest* currentQuest = currentTown->RoamTown(player);

    while (currentQuest != nullptr) {
        currentQuest->linkPlayers(player);
        TraverseQuest(currentQuest, player);
        if (player->isAlive()) { score += currentQuest->getReward(); } //if quest successful, add to score

        delete currentQuest;
        delete currentTown;

        currentTown = new Town();
        currentQuest = currentTown->RoamTown(player);
    }

    score *= player->getLevel(); //final score = level * gold earned
    delete currentTown;
    delete player;

    std::cout << "\nThank you for playing!\n"
              << "Your final score: " << score << "\n";
    return 0;
}
