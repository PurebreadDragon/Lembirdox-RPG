#ifndef __WARRIOR__
#define __WARRIOR__

#include "./../headers/Adventurer.hpp"
#pragma once

class Warrior : public Adventurer{
private:
    int revenge, revengeMax;
    double revengeReduction, revengeDamage;

public:
    Warrior(std::string name, std::string description) : Adventurer(name, description) {

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

        speed = 90;
        spdLvl = 0;

        abi1MaxCD = 0;
        revenge = 0;
        revengeMax = 3;
        revengeReduction = 0.05;
        revengeDamage = 0.15;

        description = "Warriors are slow, heavy hitters with the ability to tank a lot of damage and dish it back. The warrior thrives in the thick "
        "of battle, facing off against hordes of enemies. The warrior's defining "
        "feature is Revenge. When taking damage, the Warrior gains a stack of Revenge. The maximum amount of Revenge stacks increases with "
        "level. For each stack of Revenge, the warrior takes less damage "
        "and deals additional damage on their next attack. Revenge stacks are consumed upon attack.";
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
            ++revengeMax;
            std::cout << "You unlocked Drain. Your maximum amount of revenge stacks increased to " << revengeMax << ".\n";
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
        printSpecialFeature();

        std::cout << "\nAbilities:\n";
        if (abi1MaxCD != -1) std::cout << "Expose (no CD): Strike at an enemy and expose their weak points. Deals 60% PAtk physical damage and "
                                       << "applies a 3 turn PDef debuff.\n";
        if (abi2MaxCD != -1) std::cout << "Drain (" << abi2MaxCD << " turn CD): Attack an enemy. Deals 200% PAtk physical damage and "
                                       << "heals yourself for 30% of the damage dealt.\n";
    }

    /**Print the revenge stacks.*/
    void printSpecialFeature(){
        if (revenge > 0){
            std::cout << "Revenge stacks:\n";
            for (int i = 0; i < revenge; ++i) std::cout << "(>+<) ";
            std::cout << "\n";
            for (int i = 0; i < revenge; ++i) std::cout << "  |   ";
            std::cout << "\n";
            for (int i = 0; i < revenge; ++i) std::cout << "  |   ";
            std::cout << "\n";
            std::cout << "Reducing damage by " << revenge * revengeReduction * 100 << "% and increasing damage of the next hit by "
                    << revenge * revengeDamage * 100 << "%\n";   
        }
    }

    /**Warrior has special damage taken feature due to revenge stacks.*/
    int dealPDamage(int damage){
        if (revenge < revengeMax) ++revenge;
        double reduction = (1 - revenge * revengeReduction) * (1 - (double) physDef / (physDef + 100));
        health -= (int)((double)damage * reduction + 0.5);
        return (int)((double)damage * reduction + 0.5);
    }

    int dealMDamage(int damage){
        if (revenge < revengeMax) ++revenge;
        double reduction = (1 - revenge * revengeReduction) * (1 - (double) magDef / (magDef + 100));
        health -= (int)((double)damage * reduction + 0.5);
        return (int)((double)damage * reduction + 0.5);
    }

    int dealPDamage(int damage, double ignoreDef){
        if (revenge < revengeMax) ++revenge;
        double reduction = (1 - revenge * revengeReduction) * (1 - (double) physDef * (1 - ignoreDef) / (physDef * (1 - ignoreDef) + 100));
        health -= (int)((double)damage * reduction + 0.5);
        return (int)((double)damage * reduction + 0.5);
    }

    int dealMDamage(int damage, double ignoreDef){
        if (revenge < revengeMax) ++revenge;
        double reduction = (1 - revenge * revengeReduction) * (1 - (double) magDef * (1 - ignoreDef) / (magDef * (1 - ignoreDef) + 100));
        health -= (int)((double)damage * reduction + 0.5);
        return (int)((double)damage * reduction + 0.5);
    }

    /**And a special feature for dealing damage.
     * This method resets revenge stacks to 0. Only call this when you're making an attack. 
     * */
    int getModifiedPAtk(){
        double damage = (double)physAtk * (1 + (double)revenge * revengeDamage);
        revenge = 0;
        return damage;
    }

    /**This method gets the amount of bonus damage from revenge stacks.*/
    int getBonusRevengeDamage(){
        return (double)physAtk * ((double)revenge * revengeDamage);
    }

    void attack(Enemy* target){
        std::cout << "You bash " << target->getName() << " with your weapon, dealing (+" << getBonusRevengeDamage() << ") "
                  << target->dealPDamage(getModifiedPAtk()) << " physical damage.\n";
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
                                << "You deal " << targets[enemySelection - 1]->dealPDamage(getModifiedPAtk() * 0.6) << " physical damage and lower their "
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
                        int damageDealt = targets[enemySelection - 1]->dealPDamage(getModifiedPAtk() * 2);
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

#endif