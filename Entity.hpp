#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity{
protected:
    std::string name;
    std::string description;
    std::string deathMessage = "It dies.";
    int health = 0, maxHealth = 0, physAtk = 0, physDef = 0, magAtk = 0, magDef = 0, speed = 0, turnBar;

public:
    Entity(){
        name = "";
        description = "";
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

    bool isAlive() const{
	    return health > 0; 
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
        return maxHealth;
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

    std::string getDeathMessage(){
        return deathMessage;
    }

    /**Setters for some attributes below.*/
    void addTurnBar(int turn){
        turnBar += turn;
    }

    void setTurnBar(int turn){
        turnBar = turn;
    }

    void setDeathMessage(std::string message){
        deathMessage = message;
    }

    /**Methods for dealing damage to this target below.
     * Damage formula is equivalent to: Damage * (1 - Defense / (Defense + 100)).
     * Int return value is for displaying feedback e.g. "Enemy deals " << dealPDamage(5) << " damage." 
     * */
    virtual int dealPDamage(int damage){
        double reduction = 1 - (double) physDef / (physDef + 100);
        health -= ((double)damage * reduction);
        return ((double)damage * reduction);
    }

    virtual int dealMDamage(int damage){
        double reduction = 1 - (double) magDef / (magDef + 100);
        health -= ((double)damage * reduction);
        return ((double)damage * reduction);
    }

    void heal(int value){
        health += value; 
        if (health > maxHealth) health = maxHealth;
    }

    virtual ~Entity() = default;
};

#endif
