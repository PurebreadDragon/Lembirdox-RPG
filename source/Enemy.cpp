#include <iostream>
#include <string>
#include <vector>
#include "./../headers/Entity.hpp"
#pragma once

class Enemy : public Entity{
protected:
    int goldReward, expReward;

public:
    Enemy(){
        goldReward = 0;
        expReward = 0;
    }

    int getGoldReward(){
        return goldReward;
    }

    int getExpReward(){
        return expReward;
    }

    /**turn(): The master method for determining behavior of this monster during each of its turns.
     * This method takes in a vector of entities (adventurers) and uses that to select a valid target.
     * args: std::vector<Entity> targetList: the list of available targets
     * Currently only takes in a single entity as target. Enemy target selection/AI to be implemented later
     * */
    // void turn(std::vector<Entity> targetList);
    virtual void turn(Entity* target) = 0;

    /**getTarget(): This is used for enemy AI and target selection.
     * This method takes in a vector of valid targets and chooses one. 
     * The default chooses a random target. Unique enemies may have additional logic (choose lowest health or highest attack for example).
     * args: std::vector<Entity> targetList: the list of available targets
     * outputs: a chosen pointer to an entity 
     * */
    // Entity& getTarget(std::vector<Entity> targetList){
    //     vector<int>::iterator randIt = targetList.begin();
    //     std::advance(randIt, std::rand() % targetList.size());
    // }
};

class Skeleton : public Enemy{
public:
    Skeleton(){
        goldReward = 10;
        expReward = 10;
        name = "Skeleton";
        description = "A skeleton of a long-dead adventurer, but somehow it's moving again.";
        deathMessage = "The skeleton crumbles to the ground, reduced to dust.";
        maxHealth = 150;
        health = 150;
        maxHPOrig = 150;
        physAtk = 20;
        physDef = 10;
        magAtk = 2;
        magDef = 30;
        speed = 75 + rand() % 10 - 5;
        ID = 10001;
    }

    void turn(Entity* target){
        std::cout << "The skeleton flails its arms at " << target->getName() << ". It deals " << target->dealPDamage(physAtk) << " damage.\n";
    }
};

class BigRat : public Enemy{
public:
    BigRat(){
        goldReward = 7;
        expReward = 7;
        name = "Big Rat";
        description = "Usually an indicator of disease and plague, this ordinary gray rat has grown to disgustingly large proportions.";
        deathMessage = "The rat screeches as it dies.";
        maxHealth = 100;
        health = 100;
        maxHPOrig = 100;
        physAtk = 10;
        physDef = 20;
        magAtk = 2;
        magDef = 10;
        speed = 125 + rand() % 10 - 5;
        ID = 10002;
    }

    void turn(Entity* target){
        std::cout << "The rat bites " << target->getName() << ". It deals " << target->dealPDamage(physAtk) << " damage.\n";
    }
};

class GrowSlime : public Enemy{
public:
    GrowSlime(){
        goldReward = 50;
        expReward = 50;
        name = "Grow Slime";
        description = "A large red slime. It has a glowing red core in its center.";
        deathMessage = "The core inside the slime shatters as it melts into a puddle on the ground.";
        maxHealth = 200;
        health = 200;
        maxHPOrig = 200;
        physAtk = 0;
        physDef = 25;
        magAtk = 0;
        magDef = 25;
        speed = 75 + rand() % 10 - 5;
        ID = 10003;
    }

    void buff(Stat stat, int duration){
        switch(stat){
            case PHYS_ATK:{
                if (pAtkBuff == 0) pAtkOrig = physAtk;
                pAtkBuff += duration; 
            } break;
            case PHYS_DEF:{
                if (pDefBuff == 0) pDefOrig = physDef;
                pDefBuff += duration; 
            } break;
            case MAG_ATK:{
                std::cout << "The grow slime shakes off the debuff.\n";
            } break;
            case MAG_DEF:{
                if (mDefBuff == 0) mDefOrig = magDef;
                mDefBuff += duration; 
            } break;
            case SPEED:{
                std::cout << "The grow slime shakes off the debuff.\n";
            } break;
        }
    }

    void turn(Entity* target){
        std::cout << "The slime gathers its power a little. It lurches back opening a mouth of sorts, exposing its core. ";
        magAtk += 15;
        mAtkOrig += 15;
        speed += 10;
        spdOrig += 10;
        if (magAtk < 30) std::cout << "It shoots a little beam of flame at you, dealing " 
                                   << target->dealMDamage(magAtk) << " magic damage. It stings.\n";
        else if (magAtk < 60) std::cout << "It shoots a moderate beam of flame at you, dealing " 
                                        << target->dealMDamage(magAtk) << " magic damage. It burns.\n";
        else if (magAtk < 90) std::cout << "It launches a sizeable blast of flame at you, dealing " 
                                        << target->dealMDamage(magAtk) << " magic damage. It's seriously hot.\n";
        else std::cout << "It launches a massive blast of flame at you, dealing " 
                       << target->dealMDamage(magAtk) << " magic damage. You can barely breathe amidst the roaring flames.\n";
    }
};

class ShieldSkeleton : public Enemy{
private:
    bool shieldUp;

public:
    ShieldSkeleton(){
        goldReward = 50;
        expReward = 50;
        name = "Shield Skeleton";
        description = "It's the same variety as those skeletons earlier, but it's holding a shield.";
        deathMessage = "The shield skeleton crumbles into dust on the ground. Its shield crumbles with it.";
        maxHealth = 100;
        health = 100;
        maxHPOrig = 100;
        physAtk = 10;
        physDef = 0;
        magAtk = 5;
        magDef = 0;
        speed = 60 + rand() % 10 - 5;
        shieldUp = false;
        ID = 10004;
    }

    int dealPDamage(int damage){
        if (shieldUp){
            shieldUp = false;
            return 0;
        } else {
            double reduction = 1 - (double) physDef / (physDef + 100);
            health -= ((double)damage * reduction);
            return ((double)damage * reduction);
        }
    }

    int dealMDamage(int damage){
        if (shieldUp){
            shieldUp = false;
            return 0;
        } else {
            double reduction = 1 - (double) magDef / (magDef + 100);
            health -= ((double)damage * reduction);
            return ((double)damage * reduction);
        }
    }

    void turn(Entity* target){
        if (!shieldUp){
            std::cout << "The skeleton puts its shield up.\n";
            shieldUp = true;
        } else {
            std::cout << "The skeleton charges forward and bashes you with its shield, dealing " 
                      << target->dealPDamage(physAtk) << " physical damage.\n";
        }
    }
};

class StrangeFairy : public Enemy {
public:
    StrangeFairy() {
        goldReward = 0;
        expReward = 0;
        name = "Strange Fairy";
        description = "A small, glowing ball with wings. It looks soft and friendly.";
        deathMessage = "With a flash, the fairy disappears. It blinds you for a moment, leaving you dazed.\n";
        maxHealth = 2;
        health = 2;
        maxHPOrig = 2;
        physAtk = 1;
        physDef = 0;
        magAtk = 1;
        magDef = 100;
        speed = 50 + rand() % 10 - 5;
        ID = 10005;
    }

    void turn(Entity* target) {
        int decision = (rand() % 2);
        std::cout << "The fairy zips close to you, almost nervously. ";
        if (decision == 1) {
            std::cout << "It quickly swirls around you and you feel your wounds close.\n";
            target->heal(15 + ((rand() % 11) - 5));
        }
        else {
            std::cout << "It seems to panic, and smacks you in the face for " << target->dealPDamage(physAtk) << " physical damage.\n";
        }
        target->setTurnBar(0);
        turnBar = 1000;
        health = 0;
    }
};

class GreenSlime : public Enemy{
public:
    GreenSlime(){
        goldReward = 10;
        expReward = 10;
        name = "Green Slime";
        description = "It's a green slime. Mostly harmless but it is a little bit acidic and can dissolve your skin if kept in contact too long.";
        deathMessage = "The slime melts into the ground.";
        maxHealth = 50;
        health = 50;
        maxHPOrig = 50;
        physAtk = 5;
        physDef = 10;
        magAtk = 10;
        magDef = 10;
        speed = 50 + rand() % 10 - 5;
        ID = 10006;
    }

    void turn(Entity* target){
        std::cout << "The slime attempts to dissolve your clothes a little. It does a little damage.\n";
        std::cout << "You take " << target->dealMDamage(magAtk) << " magic damage.\n";
    }
};

class BowSkeleton : public Enemy{
public:
    BowSkeleton(){
        goldReward = 60;
        expReward = 60;
        name = "Bow Skeleton";
        description = "A skeleton of a long-dead adventurer, but somehow it's moving again. This one has a bow.";
        deathMessage = "The skeleton crumbles to the ground, reduced to dust. Its bow collapses with it.";
        maxHealth = 100;
        health = 100;
        maxHPOrig = 100;
        physAtk = 15;
        physDef = 10;
        magAtk = 2;
        magDef = 30;
        speed = 90 + rand() % 10 - 5;
        ID = 10007;
    }

    void turn(Entity* target){
        int dodged = rand() % 4; //0, 1, 2, 3
        std::cout << "The skeleton looses a volley of three arrows at you.\n";
        switch(dodged){
            case 0: std::cout << "You try to dodge out of the way, but you're hit by all 3 arrows. The first hits you for " 
                              << target->dealPDamage(physAtk - rand() % 5) << " physical damage.\n"
                              << "The second arrow hits you for " << target->dealPDamage(physAtk + rand() % 5) << " physical damage.\n"
                              << "The last hits you for " << target->dealPDamage(physAtk) << " physical damage.\n"; break;
            case 1: std::cout << "You duck out of the way of one, but still get hit by the other two. The first hits you for " 
                              << target->dealPDamage(physAtk - rand() % 5) << " physical damage.\n"
                              << "The second arrow hits you for " << target->dealPDamage(physAtk + rand() % 5) << " physical damage.\n"; break;
            case 2: std::cout << "You duck out of the way of two arrows, but the last one still nicks you in the side. It hits you for "
                              << target->dealPDamage(physAtk - rand() % 5) << " physical damage.\n"; break;
            case 3: std::cout << "You're fast on your feet and manage to roll out of the way, dodging all 3 arrows.\n";
        }
    }
};

class VampireWhelp : public Enemy {
public:
    VampireWhelp() {
        goldReward = 100;
        expReward = 100;
        name = "Vampire Whelp";
        description = "A mere fledgling of a vampire. You won't have to worry about becoming one, but those teeth are still sharp!";
        deathMessage = "The vampire whelp poofs into a small, tattered bat and collapses to the ground.";
        maxHealth = 200;
        health = 200;
        maxHPOrig = 200;
        physAtk = 20;
        physDef = 10;
        magAtk = 0;
        magDef = 20;
        speed = 60 + rand() % 10 - 5;
        ID = 10008;
    }

    void turn(Entity* target) {
        int dodge = rand() % 100; //90 - 99 is a dodge
        std::cout << "The vampire whelp draws close and lunges at your arm, fangs at the ready, ";
        if (dodge < 90) {
            int dmg = target->dealPDamage(physAtk);
            std::cout << "and you feel your life force being drawn as they sink into your skin.\n";
            std::cout << "You take " << dmg << " damage.\n";
            this->heal(dmg);
        }
        else {
            std::cout << "but you are faster, and deflect the approach.\n"
                      << "The whelp hisses angrily at you and keeps its distance.\n";
        }
    }
};

class TinySpider : public Enemy {
public:
    TinySpider() {
        goldReward = 0;
        expReward = 10;
        name = "Tiny Spider";
        description = "A tiny, poisonous spider. It moves quickly and erratically around your feet.";
        deathMessage = "The spider writhes in tiny anguish and curls its legs inward. Phew!";
        maxHealth = 1;
        health = 1;
        maxHPOrig = 1;
        physAtk = 5;
        physDef = 0;
        magAtk = 0;
        magDef = 0;
        speed = 80 + rand() % 10 - 5;
        ID = 10009;
    }

    int dealPDamage(int damage) {
        int acc = rand() % 100; //80 - 99 is a hit
        if (acc < 80) {
            std::cout << "The spider is too quick! It dodges your attack!\n";
            return 0;
        }
        else { 
            health = 0;
            return damage; 
        }
    }

    int dealPDamage(int damage, double ignoreDef) {
        return dealPDamage(damage);
    }

    void turn(Entity* target) {
        std::cout << "The tiny spider crawls onto your leg and bites you, dealing "
                  << target->dealPDamage(physAtk) << " damage. You flinch and fling it off.\n";
    }
};
