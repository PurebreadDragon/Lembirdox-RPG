#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity{
protected:
    std::string name;
    std::string description;
    int health, maxHealth, physAtk, physDef, magAtk, magDef, speed, turnBar;

public:
    Entity(){
        name = "";
        description = "";
        health = 0;
        maxHealth = 0;
        physAtk = 0;
        physDef = 0;
        magAtk = 0;
        magDef = 0;
        speed = 0;
        turnBar = 0;
    }

    Entity(std::string name, std::string description, int maxHealth, int physAtk, int physDef, int magAtk, int magDef, int speed) {
        this->name = name;
        this->description = description;
        this->maxHealth = maxHealth;
        health = maxHealth;
        this->physAtk = physAtk;
        this->physDef = physDef;
        this->magAtk = magAtk;
        this->magDef = magDef;
        this->speed = speed;
        turnBar = 0;
    }

    void inspect(){
        std::cout << name << ": " << description << "\n";
        std::cout << "Health: \t\t" << health << "/" << maxHealth << "\n"
        "Physical ATK/DEF: \t" << physAtk << "/" << physDef << "\n"
        "Magical ATK/DEF: \t" << magAtk << "/" << magDef << "\n"
        "Speed: \t\t\t" << speed << "\n";
    }

    /**
     * Getters for all attributes below.
     * args: none
     * outputs: the value of the desired stat
     * */

    int getCurrentHealth(){
        return health;
    }

    int getMaxHealth(){
        return health;
    }

    int getPAtk(){
        return physAtk;
    }

    int getPDef(){
        return physDef;
    }

    int getMAtk(){
        return magAtk;
    }

    int getMDef(){
        return magDef;
    }
    
    int getSpeed(){
        return speed;
    }

    int getTurnBar(){
        return turnBar;
    }

    std::string getName(){
        return name;
    }

    /**Setters for some attributes below.
     * */
    void addTurnBar(int turn){
        turnBar += turn;
    }

    void setTurnBar(int turn){
        turnBar = turn;
    }

    /**Methods for dealing damage to this target below.
     * Requires balancing. Right now damage is only reduced by a flat amount equal to defense. 
     * Int return value is for displaying feedback e.g. "Enemy deals " << dealPDamage(5) << " damage." 
     * */
    int dealPDamage(int damage){
        health -= std::max(damage - physDef, 0);
        return std::max(damage - physDef, 0);
    }

    int dealMDamage(int damage){
        health -= std::max(damage - magDef, 0);
        return std::max(damage - magDef, 0);
    }



    virtual ~Entity() = default;
};

#endif
