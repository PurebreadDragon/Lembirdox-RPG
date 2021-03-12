#ifndef __SAMURAI__
#define __SAMURAI__

#include "./../headers/Adventurer.hpp"
#pragma once

class Samurai : public Adventurer{
private:
    int ki, perfectDomain;
    bool premonition;

public:
    Samurai(std::string name, std::string description) : Adventurer(name, description) {
        maxHealth = 140;
        health = maxHealth;
        hpLvl = 20;

        physAtk = 70;
        pAtkLvl = 5;
        physDef = 15;
        pDefLvl = 1;

        magAtk = 0;
        mAtkLvl = 0;
        magDef = 15;
        mDefLvl = 1;

        speed = 125;
        spdLvl = 4;

        abi1MaxCD = 3;

        ki = 0;
        perfectDomain = 0;
        premonition = false;
    }

    /**
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
     * */

    std::string outputSaveFile(){
        std::string save = "PLAYERINFO\nSamurai\n";
        return save + Adventurer::outputSaveFile();
    }

    void levelUp(){
        // update stats
        std::cout << "You leveled up! You can feel your skill with the blade becoming ever sharper.\n";
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
            abi2MaxCD = 8;
            std::cout << "You unlocked Perfect Domain.\n";
        }
        if (level == 7){
            abi3MaxCD = 4;
            std::cout << "You unlocked Blade Storm.\n";
        }
        if (level == 10){
            abi4MaxCD = 6;
            std::cout << "You unlocked Premonition.\n";
        }
        if (level == 13){
            abi5MaxCD = 10;
            std::cout << "You unlocked Ultimate Technique: Thunderflash.\n";
        }
    }

    void inspect(){
        std::cout << name << " - Level " << level << " Samurai";
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
        if (abi1MaxCD != -1) std::cout << "Blink Strike (" << abi1MaxCD << " turn CD): Blink through an enemy, cutting them. Debuff the target's "
                                       << "defense and perform an Iai Slash.\n";
        if (abi2MaxCD != -1) std::cout << "Perfect Domain (" << abi2MaxCD << " turn CD): Breathe deeply and draw upon the latent power within, "
                                       << "heightening your senses and increasing your sword skills to the limit.\n" 
                                       << "\t- Upon casting this ability, enter your Perfect Domain state. Perfect Domain lasts until you take damage 3 times.\n"
                                       << "\t- Reset your turn on cast. Cleanse all debuffs.\n"
                                       << "\t- When in your Perfect Domain state, each Iai Slash hits twice. You are immune to all debuffs.\n";
        if (abi3MaxCD != -1) std::cout << "Blade Storm (" << abi3MaxCD << " turn CD): Shower the enemy in countless slashes. Perform 3 Iai Slashes on "
                                       << "the same target. \n";
        if (abi4MaxCD != -1) std::cout << "Premonition (" << abi4MaxCD << " turn CD): Focus your mind and predict the enemy's movements. Block the "
                                       << "next instance of damage. Reset your turn.\n"
                                       << "\t- Casting Premonition multiple times will not stack the damage negation.\n";              
        if (abi5MaxCD != -1) std::cout << "Ultimate Technique: Thunder Flash (" << abi5MaxCD << " turn CD): Draw your blade and strike with the power of "
                                       << "thunder and speed of lightning.\n"
                                       << "\t- Grant yourself 2 turns of physical attack buff.\n"
                                       << "\t- Perform an Iai Slash. This Iai Slash is guaranteed to crit and ignores all defense.\n"
                                       << "\t- Additionally, deal an extra 300% PAtk magic damage.\n"
                                       << "\t- Resets your turn on cast.\n";                 
    }

    /**Prints the Ki bar.*/
    void printSpecialFeature(){
        std::cout << "         .--.      .-'.      .--.      .--.      .--. \n";
        int counter = 0;
        std::cout << "Ki: ";
        while (counter < ki){
            if (counter % 4 != 0) std::cout << ":::.\\";
            else std::cout << ":::::";
            counter += 10;
        }
        counter = 100 - ki;
        while (counter > 0){
            if (counter % 4 != 0) std::cout << "    \\";
            else std::cout << "     ";    
            counter -= 10;
        }
        std::cout << "\n";
        std::cout << "    `--'      `--'      `.-'      `--'      `--'      \n";

        if (perfectDomain > 0) std::cout << "Perfect Domain active: " << perfectDomain << " hits remaining\n";
        if (premonition) std::cout << "Premonition active: Blocking the next hit\n";
    }

    void attack(Enemy* target){
        int desc = rand() % 9 + 1;
        switch(desc){
            case 1: std::cout << "In the blink of an eye, you sheathe and unsheathe your blade. " << target->getName() << " doesn't even see your blade "
                              << "before a cut appears on their body. "; break;
            case 2: std::cout << "You slash at " << target->getName() << " at the speed of sound. "; break;
            case 3: std::cout << "You relax your blade for a moment, pointing its edge towards " << target->getName() << "'s feet. In an instant, you flick "
                              << "the blade upwards and slash across their body. "; break;
            case 4: std::cout << "You take a deep breath and focus. For a moment, all is still before you suddenly leap at " 
                              << target->getName() << " and thrust your blade, piercing right through their vitals. "; break;
            case 5: std::cout << "You raise your blade above your head and perform a devastating downwards slash at " << target->getName() << ". "; break;
            case 6: std::cout << "You slice the air, sending a sharp blade of wind towards " << target->getName() << ". "; break;
            case 7: std::cout << "You javelin toss your blade through " << target->getName() << ", then dash behind them to retrieve it before they can "
                              << "even react. "; break;
            case 8: std::cout << "In one fluid motion, you ready your blade, step forward and slice through " << target->getName() << ". "; break;
            case 9: std::cout << "You slice through " << target->getName() << " so fast that your blade's reflection is barely a flicker. "; break;
        } 
        
        ki = std::min(ki + 20, 100);

        int crit = rand() % 100 + 1;
        if (crit < ki) std::cout << "Your attack critically strikes. It deals " << target->dealPDamage(physAtk) << " physical damage.\n";
        else std::cout << "You deal " << target->dealPDamage(physAtk * 0.5) << " physical damage.\n";

        // double strike if perfect domain active
        if (perfectDomain > 0){
            int desc = rand() % 9 + 1;
            switch(desc){
                case 1: std::cout << "In the blink of an eye, you sheathe and unsheathe your blade. " << target->getName() << " doesn't even see your blade "
                                << "before a cut appears on their body. "; break;
                case 2: std::cout << "You slash at " << target->getName() << " at the speed of sound. "; break;
                case 3: std::cout << "You relax your blade for a moment, pointing its edge towards " << target->getName() << "'s feet. In an instant, you flick "
                                << "the blade upwards and slash across their body. "; break;
                case 4: std::cout << "You take a deep breath and focus. For a moment, all is still before you suddenly leap at " 
                                << target->getName() << " and thrust your blade, piercing right through their vitals. "; break;
                case 5: std::cout << "You raise your blade above your head and perform a devastating downwards slash at " << target->getName() << ". "; break;
                case 6: std::cout << "You slice the air, sending a sharp blade of wind towards " << target->getName() << ". "; break;
                case 7: std::cout << "You javelin toss your blade through " << target->getName() << ", then dash behind them to retrieve it before they can "
                                << "even react. "; break;
                case 8: std::cout << "In one fluid motion, you ready your blade, step forward and slice through " << target->getName() << ". "; break;
                case 9: std::cout << "You slice through " << target->getName() << " so fast that your blade's reflection is barely a flicker. "; break;
            } 
            
            ki = std::min(ki + 20, 100);

            int crit = rand() % 100 + 1;
            if (crit < ki) std::cout << "Your attack critically strikes. It deals " << target->dealPDamage(physAtk) << " physical damage.\n";
            else std::cout << "You deal " << target->dealPDamage(physAtk * 0.5) << " physical damage.\n";
        }
    }

    // for non-attack actions with special descriptions
    // need to call this twice during perfect domain
    void attackNoDescription(Enemy* target){
        ki = std::min(ki + 20, 100);

        int crit = rand() % 100 + 1;
        if (crit < ki) std::cout << "Your attack critically strikes. It deals " << target->dealPDamage(physAtk) << " physical damage.\n";
        else std::cout << "You deal " << target->dealPDamage(physAtk * 0.5) << " physical damage.\n";
    }

    int dealPDamage(int damage){
        if (!premonition){
            if (ki > 0) ki -= 10;
            if (perfectDomain > 0) --perfectDomain;
            double reduction = 1 - (double) physDef / (physDef + 100);
            health -= (int)((double)damage * reduction + 0.5);
            return (int)((double)damage * reduction + 0.5);
        } else {
            premonition = false;
            return 0;
        }
    }

    int dealMDamage(int damage){
        if (!premonition){
            if (ki > 0) ki -= 10;
            if (perfectDomain > 0) --perfectDomain;
            double reduction = 1 - (double) magDef / (magDef + 100);
            health -= (int)((double)damage * reduction + 0.5);
            return (int)((double)damage * reduction + 0.5);
        } else {
            premonition = false;
            return 0;
        }
    }

    int dealPDamage(int damage, double ignoreDef){
        if (!premonition){
            if (ki > 0) ki -= 10;
            if (perfectDomain > 0) --perfectDomain;
            double reduction = 1 - (double) physDef * (1 - ignoreDef) / (physDef * (1 - ignoreDef) + 100);
            health -= (int)((double)damage * reduction + 0.5);
            return (int)((double)damage * reduction + 0.5);
        } else {
            premonition = false;
            return 0;
        }
    }

    int dealMDamage(int damage, double ignoreDef){
        if (!premonition){
            if (ki > 0) ki -= 10;
            if (perfectDomain > 0) --perfectDomain;
            double reduction = 1 - (double) magDef * (1 - ignoreDef) / (magDef * (1 - ignoreDef) + 100);
            health -= (int)((double)damage * reduction + 0.5);
            return (int)((double)damage * reduction + 0.5);
        } else {
            premonition = false;
            return 0;
        }
    }

    void buff(Stat stat, int duration){
        switch(stat){
            case PHYS_ATK:{
                if (pAtkBuff == 0) pAtkOrig = physAtk;
                pAtkBuff += duration; 

                if (pAtkBuff > 0) physAtk = 1.5 * pAtkOrig;
                else if (pAtkBuff == 0) physAtk = pAtkOrig;
                else physAtk = 0.5 * pAtkOrig;
            } break;
            case PHYS_DEF:{
                if (pDefBuff == 0) pDefOrig = physDef;
                pDefBuff += duration; 

                if (pDefBuff > 0) physDef = 1.5 * pDefOrig;
                else if (pDefBuff == 0) physDef = pDefOrig;
                else physDef = 0.5 * pDefOrig;
            } break;
            case MAG_ATK:{
                if (mAtkBuff == 0) mAtkOrig = magAtk;
                mAtkBuff += duration; 

                if (mAtkBuff > 0) magAtk = 1.5 * mAtkOrig;
                else if (mAtkBuff == 0) magAtk = mAtkOrig;
                else magAtk = 0.5 * mAtkOrig;
            } break;
            case MAG_DEF:{
                if (mDefBuff == 0) mDefOrig = magDef;
                mDefBuff += duration; 

                if (mDefBuff > 0) magDef = 1.5 * mDefOrig;
                else if (mDefBuff == 0) magDef = mDefOrig;
                else magDef = 0.5 * mDefOrig;
            } break;
            case SPEED:{
                if (spdBuff == 0) spdOrig = speed;
                spdBuff += duration; 
                
                if (spdBuff > 0) speed = 1.3 * spdOrig;
                else if (spdBuff == 0) speed = spdOrig;
                else speed = 0.7 * spdOrig;
            } break;
        }

        if (perfectDomain > 0){
            if (pAtkBuff < 0 || pDefBuff < 0 || mAtkBuff < 0 || mDefBuff < 0 || spdBuff < 0){
                std::cout << "Your Perfect Domain deflects the incoming debuff.\n";
                cleanse();
            }
        }
    }

    int ability(std::vector<Enemy*> targets){
        InputReader reader;
        int choice[]{0, 1, 2, 3, 4, 5};
        int abilityOptions = 1;

        // prompt for ability choice
        std::cout << "Choose an ability to use.\n"
                  << "0:\tCancel\n";
        
        // print ability 1
        if (abi1MaxCD != -1){
            abilityOptions++;
            std::cout << "1:\tBlink Strike ";
            if (abi1CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi1CD << " turn(s))\n";
        }

        // print ability 2
        if (abi2MaxCD != -1){
            abilityOptions++;
            std::cout << "2:\tPerfect Domain ";
            if (abi2CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi2CD << " turn(s))\n";
        }

        // print ability 3
        if (abi3MaxCD != -1){
            abilityOptions++;
            std::cout << "3:\tBlade Storm ";
            if (abi3CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi3CD << " turn(s))\n";
        }

        // print ability 4
        if (abi4MaxCD != -1){
            abilityOptions++;
            std::cout << "4:\tPremonition ";
            if (abi4CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi4CD << " turn(s))\n";
        }
        
        // print ability 5
        if (abi5MaxCD != -1){
            abilityOptions++;
            std::cout << "5:\tUltimate Technique - Thunderflash ";
            if (abi5CD == 0) std::cout << "(Ready)\n";
            else std::cout << "(Ready in " << abi5CD << " turn(s))\n";
        }

        // get user prompt and execute the action
        int abiChoice = reader.readInput(choice, abilityOptions);
        switch(abiChoice){
            case 0: return 0; // cancel selected
            case 1:{ // blink strike
                if (abi1CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    int enemySelection = selectTarget(targets);
                    if (enemySelection == 0) return 0;
                    else {
                        std::cout << "You blink behind " << targets[enemySelection - 1]->getName() << "'s back, exposing their weak points. ";
                        targets[enemySelection - 1]->buff(PHYS_DEF, -3);
                        attack(targets[enemySelection - 1]);
                        turnBar += 500;
                        std::cout << "You poise to strike again immediately after.\n";
                    }
                    abi1CD = abi1MaxCD;
                    return 2;
                }
            } break;
            case 2:{ // perfect domain
                if (abi2CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    std::cout << "You hold your blade out towards your enemy, close your eyes and expand your senses. Drawing upon your latent power "
                              << "and thousands of hours of training as a Samurai, you heighten your senses and hone your sword ability to the highest level. "
                              << "You remove all debuffs on yourself and ready your blade to strike. \n";
                    cleanse();
                    perfectDomain = 3;
                    turnBar += 1000;
                    abi2CD = abi2MaxCD;
                    return 2;
                }
            } break;
            case 3:{ // blade storm
                if (abi3CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    int enemySelection = selectTarget(targets);
                    if (enemySelection == 0) return 0;
                    else {
                        std::cout << "You unleash a multitude of slashes on " << targets[enemySelection - 1]->getName() << ".\n";
                        std::cout << "\"One.\" You whisper under your breath as you step forwards and slice horizontally through your enemy. ";
                        attackNoDescription(targets[enemySelection - 1]);
                        std::cout << "\"Two.\" In the same fluid motion, you rapidly spin around to face your enemy, making a backhanded slash. ";
                        attackNoDescription(targets[enemySelection - 1]);
                        std::cout << "\"Three.\" You jump up and kick off of the top of "<< targets[enemySelection - 1]->getName() 
                                << ", somersaulting over them and cutting them in the process. ";
                        attackNoDescription(targets[enemySelection - 1]);
                        if (perfectDomain > 0){
                            std::cout << "\"Again.\" You turn around midair, landing on the ground facing your enemy. You dash through them, cutting them. ";
                            attackNoDescription(targets[enemySelection - 1]);
                            std::cout << "\"Again!\" You spin around and blink through them even faster, cutting them again. ";
                            attackNoDescription(targets[enemySelection - 1]);
                            std::cout << "\"One last time!\" You grip your blade with both hands and unleash one final powerful slash on " 
                                    << targets[enemySelection - 1]->getName() << ". ";
                            attackNoDescription(targets[enemySelection - 1]);
                        }
                    }
                    abi3CD = abi3MaxCD;
                    return 2;
                }
            } break;
            case 4:{
                if (abi4CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    std::cout << "You focus your mind and predict the enemy's movements. You preemptively block the next instance of damage and "
                            << "immediately prepare to strike again. \n";
                    premonition = true;
                    turnBar += 1000;
                    abi4CD = abi4MaxCD;
                    return 2;
                }
            } break;
            case 5:{
                if (abi5CD > 0){
                    std::cout << "That ability isn't ready yet.\n";
                    return 0; 
                } else {
                    int enemySelection = selectTarget(targets);
                    if (enemySelection == 0) return 0;
                    else {
                        std::cout << "You step back and relax your stance. The wind billows around you. Your blade is drawn, but at your side. All is calm.\n"
                                  << "Suddenly, the air around you explodes, a gash in the air left by your afterimage. In an instant, you close the gap between "
                                  << "you and the enemy. The razor-sharp edge of your blade flickers with lightning, gleaming brightly. ";
                        buff(PHYS_ATK, 2);
                        if (perfectDomain <= 0){
                            std::cout << "You unleash a blindingly fast strike, carving through air and flesh alike. "
                                      << targets[enemySelection - 1]->getName() << " has barely registered what happened before crumpling under the force of your strike, "
                                      << "lightning coursing through them.\n"
                                      << targets[enemySelection - 1]->getName() << " takes " << targets[enemySelection - 1]->dealPDamage(physAtk, 1) 
                                      << " physical damage.\n";
                            if (ki < 100) ki = std::min(ki + 20, 100);
                        } else {
                            std::cout << "You unleash two blindingly fast strikes, carving through air and flesh alike. "
                                      << targets[enemySelection - 1]->getName() << " has barely registered what happened before crumpling under the force of your two strikes, "
                                      << "lightning coursing through them.\n"
                                      << targets[enemySelection - 1]->getName() << " takes " << targets[enemySelection - 1]->dealPDamage(physAtk, 1) 
                                      << " critical physical damage.\n";
                            std::cout << targets[enemySelection - 1]->getName() << " takes an additional " << targets[enemySelection - 1]->dealPDamage(physAtk, 1) 
                                      << " critical physical damage.\n";
                            if (ki < 100) ki = std::min(ki + 20, 100);
                            if (ki < 100) ki = std::min(ki + 20, 100);
                        }
                        std::cout << "Before the dust cloud from your movement has even started forming, you return to your original position, and sheathe "
                                  << "your blade with a quiet *click*. ";
                        std::cout << "A brief moment later, a flash of lightning strikes " << targets[enemySelection - 1]->getName() << " and incinerates them, dealing an additional " 
                                  << targets[enemySelection - 1]->dealMDamage(physAtk * 3) << " magic damage.\n";
                    }
                    abi5CD = abi5MaxCD;
                    return 2;
                }
            } break;
        }
    }
};

#endif