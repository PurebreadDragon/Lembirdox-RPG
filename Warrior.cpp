#include "Adventurer.hpp"
#pragma once

class Warrior : public Adventurer{
public:
    Warrior(std::string name, std::string description) : Adventurer(name, description) {
        level = 1;
        experience = 0;
        gold = 0;

        maxHealth = 250;
        health = maxHealth;
        hpLvl = 40;

        physAtk = 50;
        pAtkLvl = 5;
        physDef = 30;
        pDefLvl = 5;

        magAtk = 10;
        mAtkLvl = 0;
        magDef = 25;
        mDefLvl = 5;

        speed = 95;
        spdLvl = 0;

        abi1MaxCD = 0;
        // levelUp();
        // levelUp();
        // levelUp();
    }

    void levelUp(){
        // update stats
        std::cout << "You leveled up! Your strength grows.\n";
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
            abi2MaxCD = 4;
            std::cout << "You unlocked Drain.\n";
        }
    }

    void inspect(){
        std::cout << name << " - Level " << level << " Warrior";
        std::cout << "\nExperience: \t\t" << experience << ", " << 75 * pow(1.1, level) << " to level\n"
        "Gold: \t\t\t" << gold << "\n"
        "Health: \t\t" << health << "/" << maxHealth << " (+" << maxHealthBonus << ")\n"
        "Physical ATK: \t\t" << physAtk << " (+" << physAtkBonus << ")\n"
        "Physical DEF: \t\t" << physDef << " (+" << physDefBonus << ")\n"
        "Magical ATK: \t\t" << magAtk << " (+" << magAtkBonus << ")\n"
        "Magical DEF: \t\t" << magDef << " (+" << magDefBonus << ")\n"
        "Speed: \t\t\t" << speed << " (+" << speedBonus << ")\n";

        std::cout << "\nAbilities:\n";
        if (abi1MaxCD != -1) std::cout << "Expose (no CD): Strike at an enemy and expose their weak points. Deals 60% PAtk physical damage and "
                                       << "applies a 3 turn PDef debuff.\n";
        if (abi2MaxCD != -1) std::cout << "Drain (" << abi2MaxCD << " turn CD): Attack an enemy. Deals 200% PAtk physical damage and "
                                       << "heals yourself for 30% of the damage dealt.\n";
    }

    void attack(Enemy* target){
        std::cout << "You bash " << target->getName() << " with your weapon, dealing " << target->dealPDamage(physAtk) << " physical damage.\n";
    }

    int ability(std::vector<Enemy*> targets){
        InputReader reader;
        int choice[]{0, 1, 2, 3, 4, 5};
        int abilityOptions = 1;
        if (abi1MaxCD != -1) abilityOptions++;
        if (abi2MaxCD != -1) abilityOptions++;
        if (abi3MaxCD != -1) abilityOptions++;
        if (abi4MaxCD != -1) abilityOptions++;
        if (abi5MaxCD != -1) abilityOptions++;

        // prompt for ability choice
        std::cout << "Choose an ability to use.\n"
                  << "0:\tCancel\n";
        
        // print ability 1
        if (abi1MaxCD != -1){
            std::cout << "1:\tExpose ";
            if (abi1CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi1CD << " turn(s))\n";
        }

        // print ability 2
        if (abi2MaxCD != -1){
            std::cout << "2:\tDrain ";
            if (abi2CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi2CD << " turn(s))\n";
        }

        // get user prompt and execute the action
        int abiChoice = reader.readInput(choice, abilityOptions);
        switch(abiChoice){
            case 0: return 0; // cancel selected
            case 1:{ // expose
                int enemySelection = selectTarget(targets);
                if (enemySelection == 0) return 0;
                else {
                    std::cout << "You dash towards " << targets[enemySelection - 1]->getName() << " and strike them, throwing them off balance. "
                                << "You deal " << targets[enemySelection - 1]->dealPDamage(physAtk * 0.8) << " physical damage and lower their "
                                << "physical defense for 3 turns.\n";
                    targets[enemySelection - 1]->buff(PHYS_DEF, -3);
                }
                // expose has no CD
                return 2;
            } break;
            case 2:{ // drain strike
                if (abi2CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    int enemySelection = selectTarget(targets);
                    if (enemySelection == 0) return 0;
                    else {
                        int damageDealt = targets[enemySelection - 1]->dealPDamage(physAtk * 2);
                        std::cout << "You deal a heavy strike at " << targets[enemySelection - 1]->getName() << ", dealing "
                                << damageDealt << " physical damage and healing yourself for " << damageDealt * 0.3 << " health.\n";
                                heal(damageDealt * 0.3);
                    }
                    abi2CD = abi2MaxCD;
                    return 2;
                }
            } break;
        }
    }
};