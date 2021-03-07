#include <iostream>

using namespace std; 

#include <string>
#include "Adventurer.h" 

Adventurer::Adventurer(string name, string description, int maxHealth, int physAtk, int physDef, int magAtk, int magDef, int speed, string class, int level) : Adventurer(name, description, maxHealth, physAtk, physDef, magAtk, magDef, speed),  class(class) level (level) {}

void Adventurer::levelUp(){
	setLevel(getLevel()+1); 	
}

void Adventurer::actions(){

}

void Adventurer::setLevel(int l){
	level = l; 
	
int Adventurer::getLevel() const {
	return level;
}


