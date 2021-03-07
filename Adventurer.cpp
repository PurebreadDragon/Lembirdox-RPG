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

void Adventurer::setLevel(int l){
	level = l; 
}
	
int Adventurer::getLevel() const {
	return level;
}

void Adventurer::inspect(){
    std::cout << "It's you!\n";
    std::cout << "Health: \t\t" << health << "/" << maxHealth << " (+" << maxHealthBonus << ")\n"
    "Experience: \t\t" << experience << "\n"
    "Gold: \t\t\t" << gold << "\n"
    "Physical ATK: \t\t" << physAtk << " (+" << physAtkBonus << ")\n"
    "Physical DEF: \t\t" << physDef << " (+" << physDefBonus << ")\n"
    "Magical ATK: \t\t" << magAtk << " (+" << magAtkBonus << ")\n"
    "Magical DEF: \t\t" << magDef << " (+" << magDefBonus << ")\n"
    "Speed: \t\t\t" << speed << " (+" << speedBonus << ")\n";
}

void Adventurer::addGold(int gold){
    this->gold += gold;
}

void Adventurer::addExp(int experience){
    this->experience += experience;
}

/**addItem: adds an item to the player's inventory.
 * This method grants the player any additional stats the item may have.  
 * args: the item to be added
 * outputs: none
 * */
void Adventurer::addItem(Item* item){
    inventory.push_back(item);
    maxHealth += item->getMaxHealth();
    maxHealthBonus += item->getMaxHealth();
    health += item->getMaxHealth();
    physAtk += item->getPAtk();
    physAtkBonus += item->getPAtk();
    physDef += item->getPDef();
    physDefBonus += item->getPDef();
    magAtk += item->getMAtk();
    magAtkBonus += item->getMAtk();
    magDef += item->getMDef();
    magDefBonus += item->getMDef();
    speed += item->getSpeed();
    speedBonus += item->getSpeed();
}

/**turn: This method is called when this adventurer takes a turn in combat.
 * args: enemies (vector of valid enemy targets)
 * outputs: none
 * */
void Adventurer::turn(std::vector<Enemy*> enemies){
    InputReader reader;

    int inputChoices[]{1, 2, 3, 4};
    int selection = 0;

    //turn is not used up when the selection is equal to 2 (player chooses to inspect).
    while (selection != 1 && selection != 3 && selection != 4){ 
        // prompt the user for their input and read it
        std::cout << "It's your turn. Available options:\n"
                << "1:\tAttack\n"
                << "2:\tInspect\n"
                << "3:\tUse Item\n"
                << "4:\tFlee\n";
        selection = reader.readInput(inputChoices, 4);
        
        switch(selection){
            /*************************** ATTACK ***************************/
            case 1:{ 
                // prompt the user for target selection
                std::cout << "Choose a target.\n"
                          << "0:\tCancel\n";

                // build enemy selection array
                int enemyChoices[enemies.size()];
                int targetIndex = 1;
                int enemySelection = 0;
                for (auto e : enemies){
                    std::cout << targetIndex << ":\t" << e->getName() <<"\n";
                    enemyChoices[targetIndex - 1] = targetIndex;
                    ++targetIndex;
                }

                // read the user's target
                enemySelection = reader.readInputCancel(enemyChoices, enemies.size());

                // execute the action
                if (enemySelection != 0) attack(enemies[enemySelection - 1]);
                else selection = 0;
            } break;
            /*************************** INSPECT ***************************/
            case 2:{ //inspect
                // prompt the user for target selection
                std::cout << "Choose a target.\n"
                          << "0:\tCancel\n";

                // build enemy selection array
                int enemyChoices[enemies.size()];
                int targetIndex = 1;
                int enemySelection = 0;
                for (auto e : enemies){
                    std::cout << targetIndex << ":\t" << e->getName() <<"\n";
                    enemyChoices[targetIndex - 1] = targetIndex;
                    ++targetIndex;
                }

                // read the user's target
                enemySelection = reader.readInputCancel(enemyChoices, enemies.size());

                // execute the action
                if (enemySelection != 0) enemies[enemySelection - 1]->inspect();
                else selection = 0;
            } break;
            /*************************** ITEM ***************************/
            case 3:{ //use item
                std::cout << "Choose an item to use.\n"
                          << "0:\tCancel\n";

                // build item selection array
                int itemChoices[inventory.size()];
                int itemIndex = 1;
                int itemSelection = 0;
                if (inventory.size() > 0){
                    for (auto item : inventory){
                        std::cout << itemIndex << ":\t" << item->getName() << ": " << item->getAbilityName() << "\n";
                        itemChoices[itemIndex - 1] = itemIndex;
                        ++itemIndex;
                    }
                }

                // read what item the user wants to use
                itemSelection = reader.readInputCancel(itemChoices, inventory.size());

                if (itemSelection != 0){
                    // if the item is a self usage item, prompt for their target
                    if (!inventory[itemSelection - 1]->isSelfUse()){
                        // prompt the user for target selection
                        std::cout << "Choose a target.\n"
                                << "0:\tCancel\n";

                        // build enemy selection array
                        int enemyChoices[enemies.size()];
                        int targetIndex = 1;
                        int enemySelection = 0;
                        for (auto e : enemies){
                            std::cout << targetIndex << ":\t" << e->getName() <<"\n";
                            enemyChoices[targetIndex - 1] = targetIndex;
                            ++targetIndex;
                        }

                        // read the user's target
                        enemySelection = reader.readInputCancel(enemyChoices, enemies.size());

                        // execute the action
                        if (enemySelection != 0) inventory[itemSelection - 1]->ability(this, enemies[enemySelection - 1]);
                        else selection = 0; // if a cancel was selected, set selection to 0 so we don't consume the turn. 
                    } else { // else just use it on yourself 
                        inventory[itemSelection - 1]->ability(this, NULL);
                    }
                    // if the item is consumable, destroy it
                    if (inventory[itemSelection - 1]->isConsumable()){
                        inventory.erase(inventory.begin() + itemSelection - 1);
                    }
                } else selection = 0;
            } break;
            /*************************** FLEE ***************************/
            case 4:{ //flee
                std::cout << "Waste your turn and do nothing because this function isn't implemented.\n";
            } break;
            default:{
                std::cout << "There was an error in the selection.\n";
                selection = 1;
            } break;
        }
    }
}

/**attack: Generic attack method. Only the player can use this.
 * Deals 100% physical attack in damage. Prints a short message.
 * args: the target of the attack
 * outputs: none
 * */
void Adventurer::attack(Enemy* target){
    std::cout << name << " strikes the " << target->getName() << " with their bare fists, dealing " << target->dealPDamage(physAtk) << " physical damage.\n";
}

/**setHealth: used to set the user's health to a certain percentage.
 * Use this for % max health based healing and attacks.
 * args: the percentage to set the user's health to
 * outputs: none
 * */
void Adventurer::setHealth(double percent){
    health = std::min(maxHealth, (int)ceil(maxHealth * percent));
}

void Adventurer::setHealth(int value){
    health = value;
}