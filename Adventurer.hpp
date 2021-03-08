#ifndef __ADVENTURER_H__
#define __ADVENTURER_H__

#include "Entity.hpp"
#include "Item.hpp"
#include "Enemy.cpp"
#include "InputReader.cpp"
#include <vector>
#include <math.h>

enum Class{Warrior, Wizard, Rogue}; //future expansions to include cleric, archer, etc. 

class Adventurer : public Entity
{
	public:
		Adventurer(Class, std::string, std::string);
		// modification methods
		void levelUp();
		void setLevel(int); 
		void addGold(int);
		void addExp(int);
		void addItem(Item*);
		void setHealth(double);
		void setHealth(int);
		// viewing methods
		int getLevel() const; 
		void inspect();
		void checkInventory();
		void printClass();
		// behaviors
		void deathPenalty();
		void turn(std::vector<Enemy*>);
		void attack(Enemy*);
		void ability(std::vector<Enemy*>);
	private:
		int level = 1, experience = 0, gold = 0; 
		int maxHealthBonus = 0, physAtkBonus = 0, physDefBonus = 0, magAtkBonus = 0, magDefBonus = 0, speedBonus = 0;
		int hpLvl = 0, pAtkLvl = 0, pDefLvl = 0, mAtkLvl = 0, mDefLvl = 0, spdLvl = 0;
		std::vector<Item*> inventory;
		Class job;
}; 

#endif 
