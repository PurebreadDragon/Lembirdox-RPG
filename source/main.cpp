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

using namespace std;

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
                  << "3.\tSamurai: A physical class that attacks fast and controls the tides of combat.\n";
        int classChoice[]{1, 2, 3};
        pickedClass = reader.readInput(classChoice, 3);
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
    }
    return player;
}

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
