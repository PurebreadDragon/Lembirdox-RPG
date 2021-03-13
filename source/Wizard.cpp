#ifndef __WIZARD__
#define __WIZARD__

#include "./../headers/Adventurer.hpp"
#pragma once

class Wizard : public Adventurer{
private:
    int timeWalk, antimagicField;
public:
    Wizard(std::string name, std::string description) : Adventurer(name, description) {
        className = "Wizard";
        levelMessage = "You leveled up! You can feel your magical prowess increasing.\n";

        maxHealth = 200;
        maxHPOrig = 200;
        health = maxHealth;
        hpLvl = 30;

        physAtk = 10;
        pAtkLvl = 0;
        physDef = 10;
        pDefLvl = 2;

        magAtk = 60;
        mAtkLvl = 5;
        magDef = 10;
        mDefLvl = 3;

        speed = 100;
        spdLvl = 0;

        // start with 1 ability unlocked
        abi1MaxCD = 3;
        timeWalk = 0;
        antimagicField = 0;
    }

    /** Wizard: A class focused around AoE skills and control. 
     * 1: Chain Lightning. 3 turn CD. 120% MAtk magic damage. Hits all targets. 
     * 4: Frost Storm. 6 turn CD. 60% MAtk magic damage. Hits all targets. Pushes their turn bars back by 30% and applies 2 turn speed debuff. 
     * 7: Mana Tempest. 6 turn CD. 70% MAtk magic damage. Hits all targets. If it kills a target, this ability casts again. Can cast infinitely. 
     * 10: Antimagic Field. 8 turn CD. Become immune to 3 instances of magic damage. Buff your MAtk for 3 turns.
     * 13: Time Walk. 20 turn CD. Reset your turn 3 times in a row. 
     * */

    void levelUp(){
        // update stats
        Adventurer::levelUp();
        // update abilities
        if (level == 4){
            abi2MaxCD = 6;
            std::cout << "You unlocked Frost Storm.\n";
        }
        if (level == 7){
            abi3MaxCD = 6;
            std::cout << "You unlocked Mana Tempest.\n";
        }
        if (level == 10){
            abi4MaxCD = 8;
            std::cout << "You unlocked Antimagic Field.\n";
        }
        if (level == 13){
            abi5MaxCD = 20;
            std::cout << "You unlocked Time Walk.\n";
        }
    }

    void inspect(){
        Adventurer::inspect();
        printSpecialFeature();

        std::cout << "\nAbilities:\n";
        if (abi1MaxCD != -1) std::cout << "Chain Lightning (" << abi1MaxCD << " turn CD): Conjure a blast of lightning that arcs from enemy to enemy. "
                                       << "Hits all targets for 120% MAtk magic damage.\n";
        if (abi2MaxCD != -1) std::cout << "Frost Storm (" << abi2MaxCD << " turn CD): Summon a storm of icicles to pierce through your enemies. "
                                       << "Hits all targets for 60% MAtk magic damage, reduces their turn bars by 30% and debuffs their speed "
                                       << "for 2 turns.\n";
        if (abi3MaxCD != -1) std::cout << "Mana Tempest (" << abi3MaxCD << " turn CD): Invoke a tempest of pure mana. Hits all targets for 70% MAtk "
                                       << "magic damage. If this ability kills an enemy, it casts again for free.\n";
        if (abi4MaxCD != -1) std::cout << "Antimagic Field (" << abi4MaxCD << " turn CD): Your mastery over magic is so strong that you can even affect "
                                       << "spells cast by others. Project a barrier of magical energy around you that protects you from "
                                       << "up to 3 magical attacks. Buff your own MAtk for 3 turns. Dispel all debuffs on yourself.\n";
        if (abi5MaxCD != -1) std::cout << "Time Walk (" << abi5MaxCD << " turn CD): Using the power of ancient magic, open a door to the temporal plane. "
                                       << "In the temporal plane, time flows freely for you but is stopped for your enemies.\n"
                                       << "Take 3 turns in a row.\n";
    }

    void printSpecialFeature(){
        if (timeWalk > 0){
            for (int i = 0; i < timeWalk; ++i) std::cout << "+====+ ";
            std::cout << "\n";
            for (int i = 0; i < timeWalk; ++i) std::cout << "|(::)| ";
            std::cout << "\n";
            for (int i = 0; i < timeWalk; ++i) std::cout << "| )( | ";
            std::cout << "\n";
            for (int i = 0; i < timeWalk; ++i) std::cout << "|(..)| ";
            std::cout << "\n";
            for (int i = 0; i < timeWalk; ++i) std::cout << "+====+ ";
            std::cout << "\n";
        }

        if (antimagicField > 0) std::cout << "Antimagic field: " << antimagicField << " layer(s) remaining\n";
    }

    /**Call this at the end of every combat action.*/
    void checkTimeWalk(){
        if (timeWalk > 0){
            --timeWalk;
            turnBar += 1000;
            std::cout << "Your time in the temporal plane draws near. You have " << timeWalk << " turns remaining.\n";
        }
    }

    void attack(Enemy* target){
        std::cout << "You fire a bolt of magical energy from your wand at " << target->getName() << ", dealing " << target->dealMDamage(magAtk) << " magical damage.\n";
        checkTimeWalk();
    }

    /**Redefine these for antimagic field*/
    int dealMDamage(int damage){
        if (antimagicField <= 0){
            double reduction = 1 - (double) magDef / (magDef + 100);
            health -= (int)((double)damage * reduction + 0.5);
            return (int)((double)damage * reduction + 0.5);
        } else {
            --antimagicField;
            return 0;
        }
    }

    int dealMDamage(int damage, double ignoreDef){
        if (antimagicField <= 0){
            double reduction = 1 - (double) magDef * (1 - ignoreDef) / (magDef * (1 - ignoreDef) + 100);
            health -= (int)((double)damage * reduction + 0.5);
            return (int)((double)damage * reduction + 0.5);
        } else {
            --antimagicField;
            return 0;
        }
    }

    int useItem(std::vector<Enemy*> enemies){
        if (inventory.size() <= 0){
            std::cout << "You don't have any items.\n";
            return 0;
        }

        InputReader reader;
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
                else return 0; // if a cancel was selected, set selection to 0 so we don't consume the turn. 
            } else { // else just use it on yourself 
                inventory[itemSelection - 1]->ability(this, NULL);
            }
            // if the item is consumable, destroy it
            if (inventory[itemSelection - 1]->isConsumable()){
                inventory.erase(inventory.begin() + itemSelection - 1);
            }
            // item was used so we return a 3
            checkTimeWalk();
            return 3;
        } else return 0;
    }

    int ability(std::vector<Enemy*> targets){
        InputReader reader;
        int choice[]{0, 1, 2, 3, 4, 5};
        int abilityOptions = 1;
        if (abi5MaxCD != -1) abilityOptions++;
        // prompt for ability choice
        std::cout << "Choose an ability to use.\n"
                    << "0:\tCancel\n";
        
        // print ability 1
        if (abi1MaxCD != -1){ 
            abilityOptions++;
            std::cout << "1:\tChain Lighting ";
            if (abi1CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi1CD << " turn(s))\n";
        }

        // print ability 2
        if (abi2MaxCD != -1){
            abilityOptions++;
            std::cout << "2:\tFrost Storm ";
            if (abi2CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi2CD << " turn(s))\n";
        }

        // print ability 3
        if (abi3MaxCD != -1){
            abilityOptions++;
            std::cout << "3:\tMana Tempest ";
            if (abi3CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi3CD << " turn(s))\n";
        }

        // print ability 4
        if (abi4MaxCD != -1){
            abilityOptions++;
            std::cout << "4:\tAntimagic Field ";
            if (abi4CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi4CD << " turn(s))\n";
        }

        // print ability 5
        if (abi5MaxCD != -1){
            abilityOptions++;
            std::cout << "5:\tTime Walk ";
            if (abi5CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi5CD << " turn(s))\n";
        }

        // get user prompt and execute the action
        int abiChoice = reader.readInput(choice, abilityOptions);
        switch(abiChoice){
            case 0: return 0; // cancel selected
            case 1:{ // chain lighting
                if (abi1CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    std::cout << "You channel the arcane power flowing around you to unleash a blast of lightning that arcs from enemy to enemy.\n";
                    for (auto e : targets){
                        std::cout << e->getName() << " takes " << e->dealMDamage(magAtk * 1.2) << " magic damage.\n";
                    }
                    abi1CD = abi1MaxCD;
                    checkTimeWalk();
                    return 2;
                }
            } break;
            case 2:{ // frost storm
                if (abi2CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    std::cout << "You summon countless shards of ice and send them flying at your enemies. The shards slice "
                                << "through them, the sheer cold impeding their movement.\n";
                    for (auto e : targets){
                        std::cout << e->getName() << " takes " << e->dealMDamage(magAtk * 0.6) << " magic damage.\n";
                        std::cout << e->getName() << " had their speed reduced and their turn bar reduced by 30%.\n";
                        e->buff(SPEED, -2);
                        e->affectTurnBar(-300);
                    }
                    abi2CD = abi2MaxCD;
                    checkTimeWalk();
                    return 2;
                }
            } break;
            case 3:{ // mana tempest
                if (abi3CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    std::cout << "You channel the latent mana flowing around you and summon a devastating hurricane of magic power.\n";
                    bool reset = true, hasAlive = true;

                    while (reset){
                        reset = false;

                        for (auto e : targets){
                            if (e->isAlive()){ //attack all enemies
                                std::cout << e->getName() << " takes " << e->dealMDamage(magAtk * 0.7) << " magic damage.\n";

                                if (!e->isAlive() && !reset){ //if a previously alive target died
                                    std::cout << "The tempest rips up " << e->getName() << " and absorbs their life essence, fueling the tempest's power.\n";
                                    reset = true;
                                } else hasAlive = true;
                            }
                        }

                        if (reset && hasAlive){
                            std::cout << "The tempest surges with power and strikes all enemies again.\n";
                            hasAlive = false;
                        }
                    }
                    abi3CD = abi3MaxCD;
                    checkTimeWalk();
                    return 2;
                }
            } break;
            case 4:{ // antimagic field
                if (abi4CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    std::cout << "You focus your mana into creating several magical barriers around you. You remove all debuffs on yourself and "
                              << "and increase your magic output for 3 turns.\n";

                    buff(MAG_ATK, 3);
                    antimagicField = 3;
                    checkTimeWalk();
                    abi4CD = abi4MaxCD;
                    return 2;
                }
            } break;
            case 5:{ // time walk
                if (abi5CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    std::cout << "Using the power of ancient magic, you conjure a door in space that connects to the temporal plane. You enter "
                              << "the door into an identical mirror world, except here, everything except you is frozen in time. From here, you can survey "
                              << "the entire battlefield and move freely as you wish. However, crossing to the temporal plane costs an incredible amount "
                              << "of mana, and maintaining your connection is no small feat. You only have time to make 3 actions before you're forced to return.\n";
                    
                    timeWalk = 3;
                    turnBar += 1000;
                    abi5CD = abi5MaxCD;
                    return 2;
                }
            }
        }
        return 0;
    }
};

#endif
