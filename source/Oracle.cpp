#ifndef __ORACLE__
#define __ORACLE__

#include "./InputReader.cpp"
#include "./../headers/Entity.hpp"

#include <cstdlib>
#include <vector>
#include <algorithm>

struct Card {
    char suit;
    int rank;
    Card(char s, int r) { suit = s; rank = r; }
    ~Card() = default;

    std::string identify() {
        std::string s = "";
        switch (rank) {
            case 1: s += "One"; break;
            case 2: s += "Two"; break;
            case 3: s += "Three"; break;
            case 4: s += "Four"; break;
            case 5: s += "Five"; break;
            case 6: s += "Six"; break;
            case 7: s += "Seven"; break;
            case 8: s += "Eight"; break;
            case 9: s += "Nine"; break;
            case 10: s += "Ten"; break;
            case 11: s += "Princess"; break;
            case 12: s += "Prince"; break;
            case 13: s += "Queen"; break;
            case 14: s += "King"; break;
        }
        s += " of ";
        switch (suit) {
            case 'P': s += "Pentacles"; break;
            case 'W': s += "Wands"; break;
            case 'S': s += "Swords"; break;
            case 'C': s += "Cups"; break;
        }
        return s;
    }

    void display(int row) {
        std::cout << "|";
        switch (row) {
            case 1:
                switch (rank) {
                    case 10: std::cout << "T"; break;
                    case 11: std::cout << "P"; break;
                    case 12: std::cout << "R"; break;
                    case 13: std::cout << "Q"; break;
                    case 14: std::cout << "K"; break;
                    default: std::cout << rank; break;
                }
                std::cout << " ";
                if (suit == 'W') { std::cout << "."; }
                else { std::cout << " "; }
                std::cout << "  | ";
                break;
            case 2:
                switch (suit) {
                    case 'P': std::cout << " _A_ | "; break;
                    case 'W': std::cout << " .@. | "; break;
                    case 'S': std::cout << "  _/ | "; break;
                    case 'C': std::cout << " (_) | "; break;
                }
                break;
            case 3:
                switch (suit) {
                    case 'P': std::cout << " /^\\ | "; break;
                    case 'W': std::cout << "  |  | "; break;
                    case 'S': std::cout << " '/7 | "; break;
                    case 'C': std::cout << "  I  | "; break;
                }
                break;
            case 4:
                switch (suit) {
                    case 'W': std::cout << "  |  | "; break;
                    case 'S': std::cout << " /   | "; break;
                    default:  std::cout << "     | "; break;
                }
                break;
            case 5:
                std::cout << "____" << suit << "| ";
                break;
        }
    }
//  _____   _____   _____   _____
// |T    | |P .  | |R    | |K    |
// | _A_ | | .@. | |  _/ | | (_) |
// | /^\ | |  |  | | '/7 | |  I  |
// |     | |  |  | | /   | |     |
// |____P| |____W| |____S| |____C|
};

class Oracle : public Adventurer {
private:
   std::vector<Card*> MinorArcana;
   std::vector<Card*> read;
   int potential;
   bool holistic;
   bool X;
   bool XII;
   int XIIduration;
   bool XIII;
   bool XIIIactive;
   std::vector<Enemy*> deathTargets;
   bool XIV;
   bool XIVactive;
   bool XVI;
public:
    Oracle(std::string name, std::string desc) : Adventurer(name, desc) {
        className = "Oracle";
        levelMessage = "You leveled up! Your connection to the spirit realm grows.\n";

        maxHealth = 150;
        health = maxHealth;
        maxHPOrig = 150;
        hpLvl = 10;

        physAtk = 20;
        pAtkLvl = 0;
        physDef = 30;
        pDefLvl = 5;
        
        magAtk = 50;
        mAtkLvl = 10;
        magDef = 45;
        mDefLvl = 5;

        speed = 80;
        spdLvl = 5;

        potential = 3;
        holistic = false;
        X = false;
        XII = false;
        XIIduration = -1;
        XIII = false;
        XIIIactive = false;
        deathTargets.clear();
        XIV = false;
        XIVactive = false;
        XVI = false;

        ShuffleDeck();

        //for (unsigned i = 0; i < 15; ++i) { levelUp(); }
    }

    ~Oracle() {
        deleteRead();
        for (unsigned i = 0; i < MinorArcana.size(); ++i) {
            delete MinorArcana.at(i);
        }
        MinorArcana.clear();

        for (auto i : inventory) { delete i; }
        inventory.clear();
    }



    void ShuffleDeck() {
        char curSuit;

        for (unsigned i = 0; i < MinorArcana.size(); ++i) {
            delete MinorArcana.at(i);
        }
        MinorArcana.clear();

        for (unsigned i = 1; i <= 4; ++i) {
            switch(i) {
                case 1: curSuit = 'P'; break; //Pentacles
                case 2: curSuit = 'C'; break; //Cups
                case 3: curSuit = 'S'; break; //Swords
                case 4: curSuit = 'W'; break; //Wands
            }
            for (unsigned rank = 1; rank <= 14; ++rank) {
                Card* c = new Card(curSuit, rank);
                MinorArcana.push_back(c);
            }
        }
        std::random_shuffle(MinorArcana.begin(), MinorArcana.end());
        if (level >= 5) { X = true; } //formerly 2
        if (level >= 7) { XIV = true; } //formerly 5
        if (level >= 2) { XII = true; } //formerly 7
        if (level >= 10) { XVI = true; }
        if (level >= 15) { XIII = true; }
    }

    void levelUp() {
        //update stats
        Adventurer::levelUp();
        //update abilities
        if (level == 3 || level == 6 || level == 9) {
            ++potential;
            std::cout << "Your psychic prowess has increased!\nYou may now read " << potential
                      << " cards at once, and your cards remain active longer.\n";
        }
        if (level == 5) { //formerly 2
            std::cout << "You have unlocked a new Major Arcana: The Wheel.\n";
            X = true;
        }
        if (level == 4) {
            std::cout << "You have unlocked Holistic Harming; "
                      << "your normal attack now does both physical and magical damage.\n";
            holistic = true;
        }
        if (level == 7) { //formerly 5
            std::cout << "You have unlocked a new Major Arcana: Temperance.\n";
            XIV = true;
        }
        if (level == 2) { //formerly 7
            std::cout << "You have unlocked a new Major Arcana: The Hanged Man.\n";
            XII = true;
        }
        if (level == 10) {
            std::cout << "You have unlocked a new Major Arcana: The Tower.\n";
            XVI = true;
        }
        if (level == 15) {
            std::cout << "You have unlocked a new Major Arcana: Death.\n";
            XIII = true;
        }
    }

    void inspect() {
        Adventurer::inspect();
        printSpecialFeature();

        std::cout << "\nAbilities:\n";
        
        if (level >= 4) {
            std::cout << "Holistic Harming (passive): Your standard attack hits twice, first dealing physical, "
                      << "then dealing magical damage.\n";
        }

        std::cout << "Reshuffle: Retrieve your tarot cards, wherever they may be, "
                  << "and shuffle them back into your deck.\n";

        std::cout << "Draw Minor Arcana: Commune with your tarot deck and place the top card into your "
                  << "current reading, applying its effect.\n";

        if (level >= 2) { //formerly 7
            std::cout << "XII, The Hanged Man: Activate this Major Arcana to reverse your health for three "
                      << "turns. At the end of the three turns, your health reverses again.\n";
        }

        if (level >= 5) { //formerly 2
            std::cout << "X, The Wheel: Call upon this Major Arcana to change the winds of fate, sacrificing "
                      << "your current reading to apply debuffs to all enemies.\n";
        }

        if (level >= 7) { //formerly 5
            std::cout << "XIV, Temperance: Use this Major Arcana to amplify your connection to the spirit "
                      << "realm, entering a trance for 1 turn in exchange for filling your entire reading.\n";
        }

        /*if (level >= 7) {
            std::cout << "\nXII, The Hanged Man: Activate this Major Arcana to reverse your health for three "
                      << "turns. At the end of the three turns, your health reverses again.\n";
        }*/
        
        if (level >= 10) {
            std::cout << "XVI, The Tower: Unleash the destructive side of your powers through the energy of this "
                      << "Major Arcana, sacrificing all of your reading to deal massive damage to all enemies.\n";
        }

        if (level >= 15) {
            std::cout << "XIII, Death: Channel the waves of life and death itself, foreseeing the end for your "
                      << "opponents. Enter a trance for three turns. At the end of this trance, your vision "
                      << "will come to pass.\n";
        }

        std::cout << "\nYour abilities do not have cooldowns, but your deck must be shuffled to reuse them.\n";
    }

    void printSpecialFeature() {
        if (read.size() != 0) {
            std::cout << "\nCurrent reading:\n";
            for (unsigned i = 0; i < read.size(); ++i) {
                std::cout << " _____  \t";
            }
            std::cout << std::endl;
            for (unsigned i = 1; i <= 5; ++i) {
                for (unsigned j = 0; j < read.size(); ++j) {
                    read.at(j)->display(i);
                    std::cout << "\t";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }

    void attack(Enemy* target) {
        if (MinorArcana.size() > 0) {
            delete MinorArcana.back();
            MinorArcana.pop_back();
            std::cout << "You draw a card from your deck and send it twirling through the air with bewildering "
                      << "speed, dealing " << target->dealPDamage(physAtk) << " physical damage";
            if (holistic) { std::cout << ". The card then disappears with evanescent flames, dealing an "
                                      << "additional " << target->dealMDamage(magAtk) << " magical damage"; }
            std::cout << " to the target.\n";
        }
        else {
            std::cout << "You reach for a card, but realize you have none left!\n";
        }
    }

    int ability(std::vector<Enemy*> targets) {
        InputReader reader;
        int abilityChoices[] = {0, 1, 2, 3, 4, 5, 6, 7};
        int choiceCount = 3;

        std::cout << "0.\tCancel\n"
                  << "1.\tReshuffle\n"
                  << "2.\tDraw Minor Arcana (" << MinorArcana.size() << ")\n";
        if (level >= 2) {
        ++choiceCount;
        std::cout << "3.\tThe Hanged Man (";
            if (XII) { std::cout << "Ready)\n"; }
            else { std::cout << "Already Used)\n"; }
        }
        if (level >= 5) { //formerly 2
        ++choiceCount;
        std::cout << "4.\tThe Wheel ("; //formerly 3.
            if (X) { std::cout << "Ready)\n"; }
            else { std::cout << "Already Used)\n"; }
        }
        if (level >= 7) { //formerly 5
        ++choiceCount;
        std::cout << "5.\tTemperance ("; //formerly 4.
            if (XIV) { std::cout << "Ready)\n"; }
            else { std::cout << "Already Used)\n"; }
        }
        /*if (level >= 7) {
        ++choiceCount;
        std::cout << "5.\tThe Hanged Man (";
            if (XII) { std::cout << "Ready)\n"; }
            else { std::cout << "Already Used)\n"; }
        }*/
        if (level >= 10) {
        ++choiceCount;
        std::cout << "6.\tThe Tower (";
            if (XVI) { std::cout << "Ready)\n"; }
            else { std::cout << "Already Used)\n"; }
        }
        if (level >= 15) {
        ++choiceCount;
        std::cout << "7.\tDeath (";
            if (XIII) { std::cout << "Ready)\n"; }
            else { std::cout << "Already Used)\n"; }
        }
        int choice = reader.readInput(abilityChoices, choiceCount);
        
        switch (choice) {
            case 1:
                deleteRead(); ShuffleDeck(); clearBuffs();
                std::cout << "With a flourish of your hand, you focus your energy and restore your"
                          << "tarot deck to its full potential.\n";
                return 2; break;
            case 2: return drawMA(); break;
            case 3: return theHangedMan(); break;
            case 4: return theWheel(targets); break;
            case 5: return temperance(); break;
            //case 3: return theWheel(targets); break;
            //case 4: return temperance(); break;
            //case 5: return theHangedMan(); break;
            case 6: return theTower(targets); break;
            case 7: return deathXIII(targets); break;
        }
    }

    void deleteRead() {
        for (unsigned i = 0; i < read.size(); ++i) {
            delete read.at(i);
        }
        read.clear();
    }

    int drawMA() {
        if (read.size() == potential) {
            std::cout << "\nYou are already reading from as many cards as you can!\n";
            return 0;
        }
        else if (MinorArcana.size() == 0) {
            std::cout << "\nYou have already drawn your last Minor Arcana card!\n";
            return 0;
        }
        else {
            std::cout << "\nYou close your eyes and pull the next tarot card from your deck.\n";
            read.push_back(MinorArcana.back());
            MinorArcana.pop_back();
            switch (read.back()->suit) {
                case 'P': this->buff(SPEED, (potential * 1.66667)); break;
                case 'C': this->buff(MAX_HEALTH, (potential * 1.66667)); break;
                case 'S': this->buff(PHYS_ATK, (potential * 1.66667)); break;
                case 'W': this->buff(MAG_ATK, (potential * 1.66667)); break;
            }
            return 2;
        }
    }

    int theWheel(std::vector<Enemy*> targets) {
        if (X) {
            std::cout << "You call upon The Wheel, Major Arcana of chance, destiny, and impermanence.\n"
                      << "The winds of fortune are in constant motion, and you are their hurricane.\n";
            for (unsigned i = 0; i < read.size(); ++i) {
                for (unsigned j = 0; j < targets.size(); ++j) {
                    switch (read.at(i)->suit) {
                        case 'P': targets.at(j)->buff(SPEED, (-1 * potential * 1.66667)); break;
                        case 'C': targets.at(j)->buff(MAX_HEALTH, (-1 * potential * 1.66667)); break;
                        case 'S': targets.at(j)->buff(PHYS_ATK, (-1 * potential * 1.66667)); break;
                        case 'W': targets.at(j)->buff(MAG_ATK, (-1 * potential * 1.66667)); break;
                    }
                }
            }
            clearBuffs();
            deleteRead();
            X = false;
            return 2;
        }
        else { 
            std::cout << "You've already drawn The Wheel! Draw another card or shuffle your deck.\n";
            return 0;
        }
    }

    int temperance() {
        if (XIV) {
            std::cout << "You call upon Temperance, Major Arcana of peace, patience, and creativity.\n"
                      << "Taking a breath and composing yourself, you feel your mind expand to realms beyond.\n";
            for (unsigned i = read.size(); i < potential; ++i) {
                drawMA();
            }
            this->stun(1);
            XIV = false;
            XIVactive = true;
            return 2;
        }
        else {
            std::cout << "You've already drawn Temperance! Draw another card or shuffle your deck.\n";
            return 0;
        }
    }

    int theHangedMan() {
        if (XII) {
            std::cout << "You call upon The Hanged Man, Major Arcana of reversal and self-liberation.\n"
                      << "You are the champion of your fate. Only you have the power to change your life.\n";
            health = (maxHealth - health); // 10/160 -> 150/160
            XIIduration = 3;
            XII = false;
            return 2;
        }
        else {
            std::cout << "You've already drawn The Hanged Man! Draw another card or shuffle your deck.\n";
            return 0;
        }
    }

    int theTower(std::vector<Enemy*> targets) {
        if (XVI) {
            double MATKtotal = 1;
            double PATKtotal = 1;
            int STUNtotal = 0;
            int DEBUFFtotal = 0;
            std::cout << "You call upon The Tower, Major Arcana of chaos, upheaval, and ruin.\n"
            << "Destruction yields rebirth; the inferno that consumes the forest leaves rich soil in its wake,\n"
            << "and you are burning brightly.\n";
            for (unsigned i = 0; i < read.size(); ++i) {
                std::cout << "The " << read.at(i)->identify() << " burns away, amplifying The Tower's power.\n";
                switch (read.at(i)->suit) {
                    case 'P': ++STUNtotal; break;
                    case 'C': --DEBUFFtotal; break;
                    case 'S': PATKtotal += (.01 * read.at(i)->rank); break;
                    case 'W': MATKtotal += (.01 * read.at(i)->rank); break;
                }
            }
            deleteRead();
            int MagDmg = (magAtk * MATKtotal);
            int PhyDmg = (physAtk * PATKtotal);
            Stat curStat;
            std::cout << "The very air feels tense with the energy you channel from The Tower.\n";
            for (unsigned i = 0; i < targets.size(); ++i) {
   /*DAMAGE*/   std::cout << "Your magic rips through " << targets.at(i)->getName() << ", dealing "
                          << targets.at(i)->dealPDamage(PhyDmg) << " physical and "
                          << targets.at(i)->dealMDamage(MagDmg) << " magical damage, rending them asunder.\n";
   /* STUN */   std::cout << "The impact is tremendous, leaving " << targets.at(i)->getName() << " stunned for "
                          << STUNtotal << " turns and inhibiting their ability to recover.\n";
                          targets.at(i)->stun(STUNtotal);
   /*DEBUFF*/   switch(rand() % 6) {
                    case 0: curStat = MAX_HEALTH; break;
                    case 1: curStat = PHYS_ATK; break;
                    case 2: curStat = PHYS_DEF; break;
                    case 3: curStat = MAG_ATK; break;
                    case 4: curStat = MAG_DEF; break;
                    case 5: curStat = SPEED; break;
                }
                targets.at(i)->buff(curStat, DEBUFFtotal);
            }
            XVI = false;
            return 2;
        }
        else {
            std::cout << "You've already drawn The Tower! Draw another card or shuffle your deck.\n";
            return 0;
        }
    }

    int deathXIII(std::vector<Enemy*> targets) {
        if (XIII) {
            deathTargets.clear();
            std::cout << "You call upon Death, Major Arcana of endings and beginnings.\n"
                      << "You close your eyes and enter a trance. All things must come to pass.\n";
            for (unsigned i = 0; i < targets.size(); ++i) {
                if (targets.at(i)->getName() != "Strange Fairy") { deathTargets.push_back(targets.at(i)); }
            }
            stun(3);
            XIIIactive = true;
            return 2;
        }
        else {
            std::cout << "You've already drawn Death! Draw another card or shuffle your deck.\n";
            return 0;
        }
    }

    void deathTrance() {
        if (stunDuration == 3) {
            std::cout << "You are channeling Death. You feel your heartbeat slow. You foresee the end.\n";
        }
        else if (stunDuration == 2) {
            std::cout << "You are channeling Death. "
                      << "You can sense the life force of the all things in this realm.\n";
        }
        else {
            std::cout << "You are channeling Death. "
                      << "Birth, life, fatality. Existence is not a line, but a circle.\n"
                      << "In this moment, you are its artist.\n";
            for (unsigned i = 0; i < deathTargets.size(); ++i) {
                deathTargets.at(i)->setHealth(0);
            }
            std::cout << "\nAll things must come to an end.\n";
            XIIIactive = false;
        }
    }

    //Output custom message if under effects of Temperance or Death
    bool isStunned() override {
        if (XIVactive) {
            std::cout << "You are in a trance due to Temperance, you cannot act yet.\n";
            XIVactive = false;
            return true;
        }
        else if (XIIIactive) {
            deathTrance();
            return true;
        }
        else { return Adventurer::isStunned(); }
    }

    //Custom updateBuffs for The Hanged Man
    void updateBuffs() override {
        Adventurer::updateBuffs();
        if (XIIduration > 0) { --XIIduration; }
        if (XIIduration == 0) {
            health = (maxHealth - health);
            XIIduration = -1;
            std::cout << "The Hanged Man effect has ended.\n";
        }
    }
};



/* Oracle: A class based on shuffling buffs, high-power sacrifices, and dangerous magic attacks.
 *
 * Oracles have a unique resource, their tarot deck. This is a resource that has significant randomness, and must
 * be strategically regulated during combat.
 * As the Oracle levels, their potential increases. This increases the possible size of their readings.
 *
 * The tarot deck (which only includes Minor Arcana) contains 4 suits of 14 cards each, for a total of 56.
 * 	1. One
 * 	2. Two
 * 	3. Three
 * 	4. Four	
 * 	5. Five			
 * 	6. Six			P. Pentacles
 * 	7. Seven      of 	C. Cups
 * 	8. Eight		S. Swords
 * 	9. Nine			W. Wands
 * 	10. Ten
 * 	11. Princess
 *	12. Prince
 *	13. Queen
 *	14. King
 * 
 * Oracles increase their physical defense, magical defense and attack, and speed. They are otherwise very frail.
 * -------------------
 * Basic attack: Throw a card at an enemy, removing it from the deck and dealing physical damage.
 * Upon reaching level 4, the basic attack adds magical damage as well.
 * -------------------
 * Level 1 ability: Reshuffle [1]
 * 	Remove all cards from the current reading and shuffle them back into the deck.
 * 	Also restores all lost cards.
 * -------------------
 * Level 1 ability: Draw Minor Arcana [2]
 * 	Draw a card from the Minor Arcana and place it into the reading, applying buffs as necessary.
 * -------------------
 * Level 2 ability: The Wheel [3]
 * 	Major Arcana : X
 * 	Chance, destiny, impermanence. The fortunes are constantly evolving.
 *
 * 	Sacrifice the current reading, removing all buffs from the Oracle and randomly assigning them as debuffs
 * 	to all enemies.
 * -------------------
 * Level 4 ability: Holistic Harming [passive, has no selection]
 * 	The Oracle's standard attack now deals physical and magical damage.
 * -------------------
 * Level 5 ability: Temperance [4]
 * 	Major Arcana : XIV
 * 	Peace, patience. Take things as they come.
 *
 * 	Debuff the Oracle's speed by (potential * 0.1) in exchange for filling the entire reading.
 * 	The debuff lasts for one turn.
 * -------------------
 * Level 7 ability: The Hanged Man [5]
 * 	Major Arcana : XII
 * 	Reversal, breaking away from old patterns. Learn to see from a new perspective.
 *
 * 	For three turns, the Oracle's health is inverted. When the duration ends, health returns to normal.
 * -------------------
 * Level 10 ability: The Tower [6]
 *      Major Arcana : XVI
 *      Chaos, destruction, renewal. That which is weak must be torn down to build anew.
 * 
 *      Sacrifice the current reading, using the cards sacrificed to amplify the effect of this ability.
 *      Deal magical damage to all enemies simultaneously. Let it all fall to ruin.
 * -------------------
 * Level 15 ability: Death [7]
 * 	Major Arcana : XIII
 * 	Endings, beginnings. All things must come to pass.
 *
 * 	Foresee the end. Enter a trance for three turns - at the end of the third turn, all enemies perish.
 * -------------------
 */

#endif
