#ifndef __WIZARD__
#define __WIZARD__

#include "./../headers/Adventurer.hpp"
#pragma once

class Wizard : public Adventurer{
private:
    int timeWalk;
public:
    Wizard(std::string name, std::string description) : Adventurer(name, description) {
        maxHealth = 200;
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

        description = "Wizards are masters of the arcane arts, commanding power over the elements to channel them and unleash devastating "
        "area of effect abilities on multiple targets. The Wizard lacks in single target damage, but when they are outnumbered, it is still "
        "an even fight.";
    }

    /** Wizard: A class focused around AoE skills and control. 
     * 1: Chain Lightning. 3 turn CD. 120% MAtk magic damage. Hits all targets. 
     * 4: Frost Storm. 6 turn CD. 60% MAtk magic damage. Hits all targets. Pushes their turn bars back by 30% and applies 2 turn speed debuff. 
     * 7: Mana Tempest. 6 turn CD. 70% MAtk magic damage. Hits all targets. If it kills a target, this ability casts again. Can cast infinitely. 
     * 10: Antimagic Field. 10 turn CD. Become immune to 3 instances of magic damage. Become immune to all debuffs while this is active. 
     * 13: Time Walk. 20 turn CD. Reset your turn 3 times in a row. 
     * */

    void levelUp(){
        // update stats
        std::cout << "You leveled up! You can feel your magical prowess increasing.\n";
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
            abi4MaxCD = 20;
            std::cout << "You unlocked Time Walk.\n";
        }
    }

    void inspect(){
        std::cout << name << " - Level " << level << " Wizard";
        std::cout << "\nExperience: \t\t" << experience << ", " << 75 * pow(1.1, level) << " to level\n"
        "Gold: \t\t\t" << gold << "\n"
        "Health: \t\t" << health << "/" << maxHealth << " (+" << maxHealthBonus << ")\n"
        "Physical ATK: \t\t" << physAtk << " (+" << physAtkBonus << ")\n"
        "Physical DEF: \t\t" << physDef << " (+" << physDefBonus << ")\n"
        "Magical ATK: \t\t" << magAtk << " (+" << magAtkBonus << ")\n"
        "Magical DEF: \t\t" << magDef << " (+" << magDefBonus << ")\n"
        "Speed: \t\t\t" << speed << " (+" << speedBonus << ")\n";
        printSpecialFeature();

        std::cout << "\nAbilities:\n";
        if (abi1MaxCD != -1) std::cout << "Chain Lightning (" << abi1MaxCD << " turn CD): Conjure a blast of lightning that arcs from enemy to enemy. "
                                        << "Hits all targets for 120% MAtk magic damage.\n";
        if (abi2MaxCD != -1) std::cout << "Frost Storm (" << abi2MaxCD << " turn CD): Summon a storm of icicles to pierce through your enemies. "
                                        << "Hits all targets for 60% MAtk magic damage, reduces their turn bars by 30% and debuffs their speed "
                                        << "for 2 turns.\n";
        if (abi3MaxCD != -1) std::cout << "Mana Tempest (" << abi2MaxCD << " turn CD): Conjure up a tempest of pure mana. Hits all targets for 70% MAtk "
                                        << "magic damage. If this ability kills an enemy, it casts again for free.\n";
    }

    void printSpecialFeature(){
        for (int i = 0; i < timeWalk; ++i){
            std::cout << "+====+ \n";
            std::cout << "|(::)| \n";
            std::cout << "| )( | \n";
            std::cout << "|(..)| \n";
            std::cout << "+====+ \n";
        }
    }

    void attack(Enemy* target){
        std::cout << "You summon a bolt of magical energy at " << target->getName() << ", dealing " << target->dealMDamage(magAtk) << " magical damage.\n";
        if (timeWalk > 0){
            --timeWalk;
            turnBar += 1000;
        }
    }

    int ability(std::vector<Enemy*> targets){
        InputReader reader;
        int choice[]{0, 1, 2, 3, 4, 5};
        int abilityOptions = 1;
        if (abi3MaxCD != -1) abilityOptions++;
        if (abi4MaxCD != -1) abilityOptions++;
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
            std::cout << "4:\tTime Walk ";
            if (abi4CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi4CD << " turn(s))\n";
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
                    return 2;
                }
            } break;
        }
        return 0;
    }
};

#endif
