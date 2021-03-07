#include <iostream>
#include <string>
#include "Adventurer.hpp" 

Adventurer::Adventurer(std::string name, std::string description, int maxHealth, int physAtk, int physDef, int magAtk, int magDef, int speed) 
    : Entity(name, description, maxHealth, physAtk, physDef, magAtk, magDef, speed){ 
        level = 1;
        experience = 0;
    }

void Adventurer::levelUp(){
	setLevel(getLevel()+1); 	
}

void Adventurer::actions(){

}

void Adventurer::setLevel(int l){
	level = l; 
}
	
int Adventurer::getLevel() const {
	return level;
}

/**addItem: adds an item to the player's inventory.
 * args: the item to be added
 * outputs: none
 * */
void Adventurer::addItem(Item* item){
    inventory.push_back(item);
}

/**turn: This method is called when this adventurer takes a turn in combat.
 * args: enemies (vector of valid enemy targets)
 * outputs: none
 * */
void Adventurer::turn(std::vector<Enemy*> enemies){
    InputReader reader;
    std::cout << "It's your turn. Available options:\n"
              << "1:\tAttack\n"
              << "2:\tInspect\n"
              << "3:\tUse Item\n"
              << "4:\tFlee\n";

    int choices[]{1, 2, 3, 4};
    int selection = reader.readInput(choices, 4);
    switch(selection){
        case 1:{ //attack

        } break;
        case 2:{ //inspect

        } break;
        case 3:{ //use item

        } break;
        case 4:{ //flee

        } break;
    }
}