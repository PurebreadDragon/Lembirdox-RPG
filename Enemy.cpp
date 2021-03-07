#include <iostream>
#include <string>
#include <vector>
#include "Entity.hpp"
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
        maxHealth = 200;
        health = 200;
        physAtk = 20;
        physDef = 10;
        magAtk = 2;
        magDef = 30;
        speed = 75;
    }

    void turn(Entity* target){
        std::cout << "The skeleton flails its arms at " << target->getName() << ". It deals " << target->dealPDamage(physAtk * 1.5) << " damage.\n";
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
        physAtk = 10;
        physDef = 20;
        magAtk = 2;
        magDef = 10;
        speed = 125;
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
        physAtk = 0;
        physDef = 25;
        magAtk = 0;
        magDef = 25;
        speed = 75;
    }

    void turn(Entity* target){
        std::cout << "The slime gathers its power a little. It lurches back opening a mouth of sorts, exposing its core. ";
        magAtk += 15;
        speed += 10;
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
        physAtk = 10;
        physDef = 0;
        magAtk = 5;
        magDef = 0;
        speed = 60;
        shieldUp = false;
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