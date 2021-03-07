#include <iostream>
#include <string>
#include "Adventurer.hpp" 

Adventurer::Adventurer(std::string name, std::string description, int maxHealth, int physAtk, int physDef, int magAtk, int magDef, int speed) 
    : Entity(name, description, maxHealth, physAtk, physDef, magAtk, magDef, speed){ }

void Adventurer::levelUp(){
	setLevel(getLevel()+1); 	
}

void Adventurer::actions(){

}

void Adventurer::setLevel(int l){
	level = l; 
}
	
int Adventurer::getLevel() const {
	return level;
}