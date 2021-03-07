#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity{
protected:
    std::string name;
    std::string description;
    int health, maxHealth, physAtk, physDef, magAtk, magDef, speed;

public:
	//default constructor 
    Entity(std::string name, std::string description, int maxHealth, int physAtk, int physDef, int magAtk, int magDef, int speed){
        this->name = name;
        this->description = description;
        this->maxHealth = maxHealth;
        health = maxHealth;
        this->physAtk = physAtk;
        this->physDef = physDef;
        this->magAtk = magAtk;
        this->magDef = magDef;
        this->speed = speed;
    }

    void inspect(){
        std::cout << name << ": " << description << "\n";
        std::cout << "Health: \t\t" << health << "/" << maxHealth << "\n"
        "Physical ATK/DEF: \t" << physAtk << "/" << physDef << "\n"
        "Magical ATK/DEF: \t" << magAtk << "/" << magDef << "\n"
        "Speed: \t\t\t" << speed << "\n";
    }
	
void affectHealth(int damage){
	health -= damage; 
}

bool isAlive() const{
	return getCurrentHealth() > 0; 
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

    std::string getName(){
        return name;
    }

    virtual ~Entity() = default;
};

#endif
