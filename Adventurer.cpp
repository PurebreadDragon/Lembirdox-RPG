#include <iostream>
#include <string>
#include "Adventurer.hpp" 

Adventurer::Adventurer(std::string name, std::string description) {
        this->name = name;
        this->description = description;
        level = 1;
        experience = 0;
        gold = 0;
    }

Adventurer::~Adventurer(){
    for (auto i : inventory) delete i;
    inventory.clear();
}

/**
 * levelUp(): levels up the player and applies all relevant bonuses.
 * args: none
 * outputs: none
 * */
void Adventurer::levelUp(){
    // update stats
    std::cout << "You leveled up!\n";
    if (hpLvl > 0){
        maxHealth += hpLvl;
        health += hpLvl;
        std::cout << "Health: +" << hpLvl <<"\n";
    }
    if (pAtkLvl > 0){
        physAtk += pAtkLvl; 
        std::cout << "Physical ATK: +" << pAtkLvl << "\n";
    }
    if (pDefLvl > 0){
        physDef += pDefLvl; 
        std::cout << "Physical DEF: +" << pDefLvl << "\n";
    }
    if (mAtkLvl > 0){
        magAtk += mAtkLvl; 
        std::cout << "Magical ATK: +" << mAtkLvl << "\n";
    }
    if (mDefLvl > 0){
        magAtk += mAtkLvl; 
        std::cout << "Magical DEF: +" << mDefLvl << "\n";
    }
    if (spdLvl > 0){
        speed += spdLvl;
        std::cout << "Speed: +" << spdLvl << "\n";
    }
	++level;	
}
	
int Adventurer::getLevel() const {
	return level;
}

void Adventurer::inspect(){
    std::cout << name << " - Level " << level << " classgoeshere";
    std::cout << "\nExperience: \t\t" << experience << ", " << 75 * pow(1.1, level) << " to level\n"
    "Gold: \t\t\t" << gold << "\n"
    "Health: \t\t" << health << "/" << maxHealth << " (+" << maxHealthBonus << ")\n"
    "Physical ATK: \t\t" << physAtk << " (+" << physAtkBonus << ")\n"
    "Physical DEF: \t\t" << physDef << " (+" << physDefBonus << ")\n"
    "Magical ATK: \t\t" << magAtk << " (+" << magAtkBonus << ")\n"
    "Magical DEF: \t\t" << magDef << " (+" << magDefBonus << ")\n"
    "Speed: \t\t\t" << speed << " (+" << speedBonus << ")\n";

    std::cout << "\nAbilities:\n";
    std::cout << "You don't have any abilities unlocked.\n";
}

/**
 * checkInventory(): allows the user to check their inventory and use any consumable items
 * args: none
 * outputs: none
 * */
void Adventurer::checkInventory(){
    if (inventory.size() <= 0) std::cout << "Your bag is empty!\n";
    else {
        InputReader reader;

        std::cout << "0:\tBack\n"
                  << "1:\tInspect\n"
                  << "2:\tUse\n";
        int invChoices[]{0, 1, 2};
        int invSelect = reader.readInput(invChoices, 3);
        switch(invSelect){
            case 0: break; // do nothing
            case 1: { // inspect
                std::cout << "Choose an option.\n";
                
                // print list of items
                int index = 1;
                int itemIndices[inventory.size()];
                for (auto item : inventory){
                    std::cout << index << ":\t" << item->getName() <<"\n";
                    itemIndices[index - 1] = index;
                    ++index;
                }

                // prompt user for their choice and inspect it
                inventory[reader.readInput(itemIndices, inventory.size()) - 1]->inspect();
            } break;
            case 2: {
                std::cout << "Choose an option.\n";

                // print list of items
                int index = 1;
                int itemIndices[inventory.size()];
                for (auto item : inventory){
                    std::cout << index << ":\t" << item->getName() <<"\n";
                    itemIndices[index - 1] = index;
                    ++index;
                }
                
                // prompt user for their choice and use it if it's a consumable
                int useChoice = reader.readInput(itemIndices, inventory.size());
                if (inventory[useChoice - 1]->isConsumable()){
                    inventory[useChoice - 1]->ability(this, NULL);
                    inventory.erase(inventory.begin() + useChoice - 1);
                } else {
                    std::cout << "You can't do that here.\n";
                }
            }
        }
    }
}

/**printSpecialFeature(): This is for displaying special features like the Samurai's Ki bar.
 * args: none
 * outputs: none
 * */
void Adventurer::printSpecialFeature(){

};

void Adventurer::addGold(int gold){
    this->gold += gold;
}


/**addExp: adds experience from combat victories
 * Level up the player if they reach a certain amount.
 * args: gain (exp to gain)
 * outputs: none
 * */
void Adventurer::addExp(int gain){
    experience += gain;
    while (experience > 75 * pow(1.1, level)){
        experience -= 75 * pow(1.1, level);
        levelUp();
    }
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

/**
 * deathPenalty: applies the penalty for dying to a player.
 * Currently the player loses half of their gold and EXP.
 * args: none
 * outputs: none
 * */
void Adventurer::deathPenalty(){
    gold /= 2;
    experience /= 2;
}

/**turn: This method is called when this adventurer takes a turn in combat.
 * args: enemies (vector of valid enemy targets)
 * outputs: none
 * */
void Adventurer::turn(std::vector<Enemy*> enemies){
    InputReader reader;

    int inputChoices[]{1, 2, 3, 4, 5};
    int selection = 0;

    //turn is not used up when the selection is equal to 4 (player chooses to inspect).
    while (selection != 1 && selection != 2 && selection != 3 && selection != 5){ 
        // prompt the user for their input and read it
        std::cout << "It's your turn. Available options:\n"
                << "1:\tAttack\n"
                << "2:\tAbility\n"
                << "3:\tUse Item\n"
                << "4:\tInspect\n"
                << "5:\tFlee\n";
        selection = reader.readInput(inputChoices, 5);
        
        switch(selection){
            /*************************** ATTACK ***************************/
            case 1:{ 
                // read the user's target
                int enemySelection = selectTarget(enemies);
                // execute the action
                if (enemySelection != 0) attack(enemies[enemySelection - 1]);
                else selection = 0;
            } break;
            /*************************** ABILITY ***************************/
            case 2:{
                selection = ability(enemies);
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
                        // read the user's target
                        int enemySelection = selectTarget(enemies);

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
            /*************************** INSPECT ***************************/
            case 4:{ //inspect
                // select a target
                int enemySelection = selectTarget(enemies);

                // execute the action
                if (enemySelection != 0) enemies[enemySelection - 1]->inspect();
                else selection = 0;
            } break;
            /*************************** FLEE ***************************/
            case 5:{ //flee
                std::cout << "Waste your turn and do nothing because this function isn't implemented.\n";
            } break;
            default:{
                std::cout << "There was an error in the selection.\n";
                selection = 1;
            } break;
        }
    }

    // cycle cooldowns
    updateCooldowns();
}

/**attack: Generic attack method. Only the player can use this.
 * Deals 100% physical attack in damage. Prints a short message.
 * args: the target of the attack
 * outputs: none
 * */
void Adventurer::attack(Enemy* target){
    std::cout << "You strike the " << target->getName() << " with your bare fists, dealing " << target->dealPDamage(physAtk) << " physical damage.\n";
}

/**
 * selectTarget(): Prompts the user to select a target from a list.
 * Returns 0 if the user cancels. 
 * args: a std::vector<Enemy*> of valid enemy targets
 * outputs: an integer with the index of the user's selection in the vector
 * */
int Adventurer::selectTarget(std::vector<Enemy*> targets){
    InputReader reader;
    // choose a target
    std::cout << "Choose a target.\n"
                << "0:\tCancel\n";

    // build enemy selection array
    int enemyChoices[targets.size()];
    int targetIndex = 1;
    int enemySelection = 0;
    for (auto e : targets){
        std::cout << targetIndex << ":\t" << e->getName() <<"\n";
        enemyChoices[targetIndex - 1] = targetIndex;
        ++targetIndex;
    }

    // read the user's target
    return reader.readInputCancel(enemyChoices, targets.size());
}

/**ability: Abilities that the character gains on level up. Levels 1, 4, 7, etc. unlock new ones.
 * Based on class. 
 * Warrior: A class focused around tanking and dealing a lot of single-target damage. Boss killer. 
 * 1: Expose. 0 turn CD. 20% PAtk physical damage. Applies 3 turn defense debuff.
 * 4: Drain. 4 turn CD. 200% PAtk physical damage. Heals for 30% of damage dealt. 
 * 7: Sunder. 2 turn CD. 170% PAtk physical damage. Hits twice if self has attack buff. Buffs own attack for 2 turns but debuffs own defense for 1 turn. 
 * ================================================================
 * Wizard: A class focused around AoE skills and control. 
 * 1: Chain Lightning. 3 turn CD. 120% MAtk magic damage. Hits all targets. 
 * 4: Frost Storm. 6 turn CD. 60% MAtk magic damage. Hits all targets. Pushes their turn bars back by 30% and applies 2 turn speed debuff. 
 * 7: Mana Tempest. 6 turn CD. 100% MAtk magic damage. Hits all targets. If it kills a target, this ability casts again at no cost. 
 * ================================================================
 * Samurai: A class focused around speed and turn cycling.
 * Samurai have a resource called Ki. They gain 20 Ki when performing Iai Slash but lose 10 Ki when taking damage, up to 100. 
 * Samurai are very fragile, but have high physical attack, speed, physical attack growth and speed growth. 
 * Basic attack: Replaced with Iai Slash. A lightning fast slash that cannot be seen by the naked eye.
 *      Deals 50% PAtk damage, but can crit for double damage. Crit chance is equal to the percentage of filled Ki bar. 
 * 1: Blink Strike: 3 turn CD. Teleport behind an enemy and cut them. Debuff their defense for 1 turn and perform an Iai Slash. Sets own turn bar to 50%. 
 * 4: Perfect Domain: 8 turn CD. 3 hit duration. Breathe deeply and draw upon the latent power within, sharpening your senses to detect all 
 * nearby movement. 
 *      Reset your turn on cast. Cleanse all debuffs. 
 *      When in your Perfect Domain state, you are immune to all debuffs and each Iai Slash hits twice. You always have speed buff. 
 *      Kills during Perfect Domain extend the duration by 1 hit. 
 *      Taking damage during Perfect Domain reduces the duration by 1 hit. 
 * 7: Bladestorm: 4 turn CD. Shower the enemy in countless slashes. Casts 3 Iai Slashes in quick succession.  
 * 11: Premonition: 6 turn CD. Focus your mind and predict the enemy's movements. Resets turn. Negate the next instance of damage. 
 *      Casting premonition multiple times will not stack the damage negation. 
 * 15: Ultimate Technique - Thunder Flash. 10 turn CD. Draw your blade and strike with the power of thunder and speed of lightning. Grant self 2T PAtk buff. 
 *      Perform an Iai Slash. This Iai Slash is guaranteed to crit and ignores all defense. Reset your turn. 
 * ================================================================
 * Psionic: A class of mage with the ability to transform into a psionic being.
 * Psionics have a resource called Psi. Using Psi Strike gains Psi, up to 5. They can expend it to fuel their more powerful abilities. 
 * 1: Psionic Form. 99 turn CD. Transforms into psionic form. Psionic form replaces your basic attack with Psi Strike. 
 *      Psi Strike: No CD. Deal 50% PAtk physical damage, 50% MAtk magical damage. Gain 1 Psi. 
 * 4: Mindblast. No CD. Consume 1 Psi. Deal 40% PAtk physical damage, 40% MAtk magical damage. Ignore all defense. 
 * 7: Psychic Fear. No CD. Consume 3 Psi. Doesn't do damage. Fully resets your own turn. Debuffs a target's speed for 1 turn and sets their turn bar to 0. 
 * 11: Psi Storm. No CD. Consume 5 Psi. Does 250% PAtk physical and 250% MAtk magic damage to all enemies and debuffs their 
 *      physical attack and magic attack for 2 turns. 
 * 15: Recharge. 9 turn CD. Instantly charges 5 Psi. Reset your turn. If this skill is used at 5 Psi, expend all Psi to buff all stats for 2 turns and 
 *      recover 25% health. 
 * ================================================================
 * Elementalist: A class with the ability to channel the power of the elements.
 * Elementalists can channel the power of 5 different elements: Lightning, Fire, Earth, Water and Wind. They can channel 2 at a time.
 * Lightning: Destructive element focused around single target damage.
 * Fire: Destructive element focused around area of effect damage.
 * Earth: Defensive element focused around reducing damage and slowing enemies.
 * Water: Defensive element focused around restoring health. 
 * Wind: Supportive element focused around bolstering your other elements. 
 * 
 * Each element has an energy meter, up to 100. When not active i.e. not using its ability or stored, an element regenerates 15 energy. 
 * 
 * Elementalists have no offensive spells of their own. Instead, their elements provide passive effects that activate at the end of every turn. 
 * They can modify their currently held elements with the following actions:
 * 1: Switch. Change the selected element with a new one.
 * 2: Offense. Changes the selected element into offense mode.
 *      Lightning: 10 energy. Deal 30% MAtk magical damage to a random target. 
 *      Fire: 20 energy. Deal 20% MAtk magical damage to all targets. 
 *      Earth: 10 energy. Deal 5% MAtk physical damage to a random target. 50% chance to debuff its physical attack for 1 turn. 
 *      Water: 10 energy. 25% chance each to apply 1 turn of defense debuff to each enemy. 
 *      Wind: 40 energy. Grant 1 turn of speed buff to yourself.
 * 3: Support. Changes the selected element into support mode.
 *      Lightning: 40 energy. Deal 10% MAtk magical damage to a random target and apply 1 turn of defense debuff. 
 *      Fire: 10 energy. You start your next turn at +10% turn bar. 
 *      Earth: 20 energy. 25% chance to grant 1 turn of physical defense buff to youself. 25% chance to grant 1 turn of magic defense buff. 50% to grant both.
 *      Water: 30 energy. Restore 5% max health. 
 *      Wind: 10 energy. Your other effect activates an extra time at no energy cost. 
 * 
 * When an element lacks the energy to activate its ability, it will regenerate energy at the normal rate. 
 * 
 * You start with Lightning and Earth. At level 4, you gain Fire. At level 7, you gain Water. At level 11, you gain Wind. At level 15, you gain Elemental
 * Hurricane. 
 * 
 * 15: Elemental Hurricane. 15 turn CD. Channel the full power of the elements. Fully restore all energy and deal 150% MAtk magical damage 
 *      4 times and 150% MAtk physical damage one time (for earth) to random enemies. 
 * 
 * args: targets (list of available targets)
 * outputs: a 0 if an ability was cast. 2 if not
 * */
int Adventurer::ability(std::vector<Enemy*> targets){
    std::cout << "You don't have any abilities.\n";
    return 0;
}

/**
 * updateCooldowns: reduces all cooldowns by 1 (if greater than 1)
 * Call this at the end of a turn.
 * args: none
 * outputs: none
 * */
void Adventurer::updateCooldowns(){
    if (abi1CD > 0) abi1CD--;
    if (abi2CD > 0) abi2CD--;
    if (abi3CD > 0) abi3CD--;
    if (abi4CD > 0) abi4CD--;
    if (abi5CD > 0) abi5CD--;
}

/**setHealth: used to set the user's health to a certain percentage.
 * Use this for % max health based healing and attacks.
 * args: the percentage to set the user's health to
 * outputs: none
 * */
void Adventurer::setHealth(double percent){
    health = maxHealth * percent;
}

void Adventurer::setHealth(int value){
    health = value;
}
