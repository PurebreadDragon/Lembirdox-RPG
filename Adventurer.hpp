#pragma once

#include "Entity.hpp"
#include "Item.hpp"
#include "Enemy.cpp"
#include "InputReader.cpp"
#include <vector>
#include <math.h>

class Adventurer : public Entity
{
	public:
		Adventurer(std::string, std::string);
		~Adventurer();
		// modification methods
		virtual void levelUp();
		void addGold(int);
		void addExp(int);
		void addItem(Item*);
		void setHealth(double);
		void setHealth(int);

		// viewing methods
		int getLevel() const; 
                int getGold() const;
		virtual void inspect();
		void checkInventory();
		virtual void printSpecialFeature();
		// behaviors
		void deathPenalty();
		void turn(std::vector<Enemy*>);
		virtual void attack(Enemy*);
		int selectTarget(std::vector<Enemy*>);
		virtual int ability(std::vector<Enemy*>);
		void updateCooldowns();
	protected:
		int level = 1, experience = 0, gold = 0; 
		int maxHealthBonus = 0, physAtkBonus = 0, physDefBonus = 0, magAtkBonus = 0, magDefBonus = 0, speedBonus = 0;
		int hpLvl = 0, pAtkLvl = 0, pDefLvl = 0, mAtkLvl = 0, mDefLvl = 0, spdLvl = 0;
		// max cd is set to -1 if the ability is not unlocked yet. 
		int abi1CD = 0, abi1MaxCD = -1, abi2CD = 0, abi2MaxCD = -1, abi3CD = 0, abi3MaxCD = -1, abi4CD = 0, abi4MaxCD = -1, abi5CD = 0, abi5MaxCD = -1;
		std::vector<Item*> inventory;
}; 
